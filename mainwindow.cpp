#include "mainwindow.h"
#include "ui_mainwindow.h"

#define COMPENSARION_VALUE 2

#define MAP_W 1000
#define MAP_H 1000
#define MAP_RANGE 200 // meter
#define MAP_RESOLUTION 0.2f; // 精度
#define GAIN 1.0f
#define ALFA 1 // sonar parameters
#define GAMA 0.01f // sonar parameters


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    systemManager();
    toolBarManager();
    geometryManager();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/***********************************************************************************************
 *                                          Initial
 * *********************************************************************************************/
void MainWindow::systemManager()
{
    // ui operation
    if(!simulation){
        ui->actionOpen_File->setEnabled(0);
    }
    ui->lineEdit_IP->setClearButtonEnabled(true);
    ui->lineEdit_IP->setPlaceholderText("IP address");
    ui->lineEdit_IP->setValidator(0);
    ui->lineEdit_Port->setClearButtonEnabled(true);
    ui->lineEdit_Port->setPlaceholderText("Port Number");
    ui->lineEdit_Port->setValidator(new QIntValidator(ui->lineEdit_Port));

    statusLabel = new QLabel();
    ui->statusBar->showMessage("Ready");
    ui->statusBar->addPermanentWidget(statusLabel);

    QObject::connect(this, SIGNAL(weightSelected()), this, SLOT(detectorInit()));
}

void MainWindow::detectorInit()
{
    ui->statusBar->showMessage("Loading Weights...");
    waitKey(2000);
    detector = new Detector(cfg_file, weights_file, 0);
    statusLabel->setText("Loaded");
    ui->statusBar->clearMessage();
    ui->statusBar->showMessage("Ready");
}

int MainWindow::systemInit()
{
    if (cfg_file.empty())
    {
        QMessageBox::about(NULL, "ERROR", "Please Select cfg file");
        return 0;
    }
    if (weights_file.empty())
    {
        QMessageBox::about(NULL, "ERROR", "Please Select weight file");
        return 0;
    }
    if (names_file.empty())
    {
        QMessageBox::about(NULL, "ERROR", "Please Select names file");
        return 0;
    }

    if(simulation){
        if (file_path.empty())
        {
            QMessageBox::about(NULL, "ERROR", "Please Select XTF files");
            return 0;
        }
        p_simulator = new simulator(file_path);
    }
    else{
        u900Sonar = new u900DataReceive();
        u900Sonar->socket_ip = ip;
        u900Sonar->socket_port = port;
//    u900Sonar->socket_port = 7007;
//    u900Sonar->socket_ip = "192.168.1.80";
    }

    return 1;
}

/***********************************************************************************************
 *                                  sonar image function
 * *********************************************************************************************/
void MainWindow::imageDetect()
{
    active_logger = (unique_ptr<logger>) new logger(logger::log_level::debug);

    int receiveState = 0;
    bool isFirstPing = true;
    bool enableSSimage=true;
    Mat ssImage(WINDOW_H,WINDOW_W,CV_16UC1, cvScalar(0));
    Mat ssImage8bit(WINDOW_H,WINDOW_W,CV_8UC3, cvScalar(0));
    Mat color_ssImage(WINDOW_H,WINDOW_W,CV_16UC3, cvScalar(0));

    Frame * p_frame;
    vector< vector<double> > gps_array(DETECT_SIZE, vector<double>(4)); // 存储gps信息
    for (int i = 0; i < DETECT_SIZE; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            gps_array[i][j] = 0;
        }
    }

    if (simulation)
    {
        p_simulator->initializeSimulator();
        p_simulator->startSimulator();
        runningFlag = p_simulator->getSimState()!=simState::simStop;
    }
    else
    {
        u900Sonar->stopButtonState = true;
        u900Sonar->fBytesPerSample = 2;
        u900Sonar->fNumSamples = 1200;
        u900Sonar->transToXtfStruct.channelNum = 2;

        if (!u900Sonar->connetSideScan())
        {
            QMessageBox::about(NULL,"ERROR","Connection Failed !");
        }
        u900Sonar->startReceiveData();
        runningFlag = u900Sonar->receivingDataState == 1 && u900Sonar->connectionState == 1;
    }

    while (runningFlag)
    {
        if (ui->btn_start->text() == "Start")
        {
            if (simulation){
                p_simulator->stopSimulator();
                break;
            }
            else{
                u900Sonar->stopButtonState = false;
            }
        }
        if (simulation){
            receiveState = p_simulator->fetchFrame(p_frame);
        }
        else {
            receiveState = u900Sonar->fetchFrame(p_frame);
        }

        if(receiveState)
        {
            if(p_frame->packetType==XTF_DATA_SIDESCAN)
            {
                pingFrame* p_ping=(pingFrame *)p_frame;
                int window_w = 2 * p_ping->numSamples;
                // 检测初始ping
                if (isFirstPing)
                {
                    longtitude_init = p_ping->sensorXcoordinate;
                    latitude_init = p_ping->sensorYcoordinate;
                    ssImage.create(WINDOW_H,window_w,CV_16UC1);
                    ssImage8bit.create(WINDOW_H,window_w,CV_8UC3);
                    color_ssImage.create(ssImage.rows, ssImage.cols, CV_16UC3);
                    emit currentGPSSet();

                    initPingNum = p_ping->pingNumber;
                    isFirstPing = false;
                }
                int pingSum = p_ping->pingNumber - initPingNum + 1; // 进来的总ping数
                int id = pingSum % DETECT_SIZE;
                detect_time = int(pingSum / DETECT_SIZE);

                gpsArrayUpdate(p_ping, id, gps_array);
                sonarInfoShow(p_ping);
                detectionInfoShow();

                Mat rawPingImg(280, window_w, CV_8UC1, cvScalar(0));

                LOG(info,"Time stamp: "+std::to_string(p_ping->timeStamp)+"No: "+std::to_string(p_ping->pingNumber));

                if(enableSSimage)
                {
                    solver->updateMat(&ssImage);
                    for(unsigned int ii=0; ii<p_ping->numSamples; ii++)
                    {
                        if (p_ping->bytesPerSample == 1)
                        {
                            ssImage.ptr<unsigned short>(0)[ii] = *((unsigned char *)(p_ping->p_data[0]) + ii) * GAIN;
                            ssImage.ptr<unsigned short>(0)[ii+p_ping->numSamples] = *((unsigned char *)(p_ping->p_data[1]) + ii) * GAIN;
                            solver->imageGain(ssImage, p_ping, ii);
                        }
                        else if (p_ping->bytesPerSample == 2)
                        {
                            ssImage.ptr<unsigned short>(0)[ii] = *((unsigned short *)(p_ping->p_data[0]) + ii) * GAIN;
                            ssImage.ptr<unsigned short>(0)[ii+p_ping->numSamples] = *((unsigned short *)(p_ping->p_data[1]) + ii) * GAIN;
                            solver->imageGain(ssImage, p_ping, ii);
                        }
                    }
                    solver->gray2Color(ssImage, color_ssImage);
                    solver->siglePingShow(rawPingImg, ssImage);
                    color_ssImage.convertTo(ssImage8bit, CV_8UC3);

                    if (id == 0) // 每DETECT_SIZE次做一次检测
                    {
                        vector<string> obj_names;
                        objNameInit(obj_names);

                        Mat input, rest;
                        Rect rect_input(0, 0, window_w, DETECT_SIZE);
                        Rect rect_rest(0, DETECT_SIZE, window_w, WINDOW_H-DETECT_SIZE);
                        input = ssImage8bit(rect_input);
                        rest = ssImage8bit(rect_rest);

                        vector<bbox_t> result_vec = detector->detect(input);
                        box_num += result_vec.size();
                        int single_box_num = result_vec.size();

                        // Geometry Encoder and Display
                        for (int idxTable = (box_num-single_box_num); single_box_num > 0; idxTable++)
                        {
                            geometryEncoder(result_vec, gps_array, p_ping, single_box_num);
                            updateObjectMat(input, result_vec, gps_array, p_ping, single_box_num, idxTable);
                            detectionResultShow(p_ping, result_vec, gps_array, single_box_num, idxTable);

                            single_box_num--;
                        }
                        draw_boxes(input, result_vec, obj_names);
                        vconcat(input, rest, ssImage8bit);
                    }
                    Mat rgb;
                    cvtColor(ssImage8bit, rgb, COLOR_BGR2RGB);
                    QImage disImage = QImage((const uchar*)(rgb.data), rgb.cols, rgb.rows, rgb.cols*rgb.channels(), QImage::Format_RGB888);
                    QPixmap pixmap = QPixmap::fromImage(disImage);
                    QPixmap scaled = pixmap.scaled(ui->label_view_sonar->width(), ui->label_view_sonar->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    ui->label_view_sonar->setScaledContents(true);
                    ui->label_view_sonar->setPixmap(scaled);

                    QImage rawImage = QImage((const uchar*)(rawPingImg.data), rawPingImg.cols, rawPingImg.rows, rawPingImg.cols*rawPingImg.channels(), QImage::Format_Indexed8);
                    QPixmap rawPixmap = QPixmap::fromImage(rawImage);
                    rawPixmap.scaled(ui->label_view_ping->width(), ui->label_view_ping->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    ui->label_view_ping->setScaledContents(true);
                    ui->label_view_ping->setPixmap(rawPixmap);

                    cv::waitKey(20);
                }
            }
        }
        QApplication::processEvents();
    }
    if (!simulation){
        u900Sonar->stopReceiveData();
    }
}

/***********************************************************************************************
 *                                        sonar info
 * *********************************************************************************************/
void MainWindow::sonarInfoShow(pingFrame *p_ping)
{
    ui->label_TimeStamp->setText(QString::number(p_ping->timeStamp, 'f', 6));
    ui->label_PingNumber->setNum(int(p_ping->pingNumber));
    ui->label_SensorHeading->setText(QString::number(p_ping->sensorHeading, 'f', 6));
    ui->label_SensorPitch->setText(QString::number(p_ping->sensorPitch, 'f', 6));
    ui->label_SensorRoll->setText(QString::number(p_ping->sensorRoll, 'f', 6));
    ui->label_SensorSpeed->setText(QString::number(p_ping->sensorSpeed, 'f', 6));
    ui->label_SensorPriAltitude->setText(QString::number(p_ping->sensorPrimaryAltitude, 'f', 6));
    ui->label_SensorXcoord->setText(QString::number(p_ping->sensorXcoordinate, 'f', 6));
    ui->label_SensorYcoord->setText(QString::number(p_ping->sensorYcoordinate, 'f', 6));
    ui->label_bytePerSample->setNum(double(p_ping->bytesPerSample));
    ui->label_ShipGyro->setText(QString::number(p_ping->shipGyro, 'f', 6));
    ui->label_ShipSpeed->setText(QString::number(p_ping->shipSpeed, 'f', 6));
    ui->label_PacketType->setNum(int(p_ping->packetType));
    ui->label_SlantRange->setText(QString::number(p_ping->slantRange, 'f', 6));
    ui->label_SoundVelocity->setText(QString::number(p_ping->soundVelocity, 'f', 6));
}

/***********************************************************************************************
 *                                        detection info
 * *********************************************************************************************/

string doubleToString(const double &dbNum)
{
    char *chCode;
    chCode = new(std::nothrow)char[20];
    sprintf(chCode, "%.2lf", dbNum);  // .2 是控制输出精度的，两位小数bai
    string strCode(chCode);
    delete []chCode;
    return strCode;
}

vector<string> objects_names_from_file(string const filename) {
    ifstream file(filename);
    vector<string> file_lines;
    if (!file.is_open()) return file_lines;
    for (string line; getline(file, line);) file_lines.push_back(line);
    cout << "object names loaded \n";
    return file_lines;
}

void MainWindow::draw_boxes(cv::Mat mat_img, std::vector<bbox_t> result_vec, std::vector<std::string> &obj_names)
{
    int const colors[6][3] = { { 1,0,1 },{ 0,0,1 },{ 0,1,1 },{ 0,1,0 },{ 1,1,0 },{ 1,0,0 } };
    for (auto &i : result_vec)
    {
        cv::Scalar color = obj_id_to_color(i.obj_id);
        cv::rectangle(mat_img, cv::Rect(i.x, i.y, i.w, i.h), color, 2);
        if (obj_names.size() > i.obj_id) {
            std::string obj_name = obj_names[i.obj_id];
            if (i.track_id > 0) obj_name += " - " + std::to_string(i.track_id);
            obj_name += " " + doubleToString(i.prob);
            cv::Size const text_size = getTextSize(obj_name, cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, 2, 0);
            int const max_width = (text_size.width > i.w + 2) ? text_size.width : (i.w + 2);
            cv::rectangle(mat_img, cv::Point2f(std::max((int)i.x - 1, 0), std::max((int)i.y - 30, 0)),
            cv::Point2f(std::min((int)i.x + max_width, mat_img.cols - 1), std::min((int)i.y, mat_img.rows - 1)),color, CV_FILLED, 8, 0);
            putText(mat_img, obj_name, cv::Point2f(i.x, i.y - 10), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, cv::Scalar(0, 0, 0), 2);
        }
    }
}

void MainWindow::objNameInit(vector<string> &obj_names)
{
    ifstream ifs(names_file.c_str());
    string line;
    while (getline(ifs, line)) obj_names.push_back(line);
    std::cout << detector->cur_gpu_id<< std::endl;
}

void MainWindow::gpsArrayUpdate(pingFrame *p_ping, int id, vector<vector<double> > &gps_array)
{
    if (id != 0)
    {
        gps_array[id-1][0] = p_ping->sensorXcoordinate;
        gps_array[id-1][1] = p_ping->sensorYcoordinate;
        gps_array[id-1][2] = p_ping->slantRange;
        gps_array[id-1][3] = p_ping->numSamples;
    }
    else
    {
        gps_array[DETECT_SIZE-1][0] = p_ping->sensorXcoordinate;
        gps_array[DETECT_SIZE-1][1] = p_ping->sensorYcoordinate;
        gps_array[DETECT_SIZE-1][2] = p_ping->slantRange;
        gps_array[DETECT_SIZE-1][3] = p_ping->numSamples;
    }
}

void MainWindow::detectionInfoShow()
{
    ui->label_detectionCounts->setNum(detect_time);
    ui->label_detectionBoxesNumber->setNum(box_num);
}

void MainWindow::detectionResultShow(pingFrame *p_ping, vector<bbox_t> &result_vec, int idxSeg, int lengthSeg, vector<vector<double> > &gps_array, int single_box_num, int idxTable)
{
    ui->tableWidget->insertRow(idxTable);
    ui->tableWidget->setItem(idxTable, 0, new QTableWidgetItem(QString::number(idxTable+1)));
    ui->tableWidget->setItem(idxTable, 1, new QTableWidgetItem(QString::number(result_vec[single_box_num-1].prob)));
    ui->tableWidget->setItem(idxTable, 2, new QTableWidgetItem(QString::number(p_ping->pingNumber - (result_vec[single_box_num-1].y+result_vec[single_box_num-1].h/2)))); // 所在ping数
    if (result_vec[single_box_num-1].x + idxSeg*lengthSeg > p_ping->numSamples)
    {
        ui->tableWidget->setItem(idxTable, 3, new QTableWidgetItem(QString("Right")));
        ui->tableWidget->setItem(idxTable, 4, new QTableWidgetItem(QString::number(result_vec[single_box_num-1].x + idxSeg*lengthSeg - p_ping->numSamples)));
    }
    else
    {
        ui->tableWidget->setItem(idxTable, 3, new QTableWidgetItem(QString("Left")));
        ui->tableWidget->setItem(idxTable, 4, new QTableWidgetItem(QString::number(p_ping->numSamples - result_vec[single_box_num-1].x + idxSeg*lengthSeg)));
    }
    ui->tableWidget->setItem(idxTable, 5, new QTableWidgetItem(QString::number(result_vec[single_box_num-1].w))); // 框中心的宽
    ui->tableWidget->setItem(idxTable, 6, new QTableWidgetItem(QString::number(result_vec[single_box_num-1].h))); // 框中心的高

    int pingNum = DETECT_SIZE - int(result_vec[single_box_num-1].y+result_vec[single_box_num-1].h/2);
    ui->tableWidget->setItem(idxTable, 7, new QTableWidgetItem(QString::number(gps_array[pingNum][0], 'f', 6))); // gps_x
    ui->tableWidget->setItem(idxTable, 8, new QTableWidgetItem(QString::number(gps_array[pingNum][1], 'f', 6))); // gps_y

}

void MainWindow::detectionResultShow(pingFrame *p_ping, vector<bbox_t> &result_vec, vector<vector<double> > &gps_array, int single_box_num, int idxTable)
{
    ui->tableWidget->insertRow(idxTable);
    ui->tableWidget->setItem(idxTable, 0, new QTableWidgetItem(QString::number(idxTable+1)));
    ui->tableWidget->setItem(idxTable, 1, new QTableWidgetItem(QString::number(result_vec[single_box_num-1].prob)));
    ui->tableWidget->setItem(idxTable, 2, new QTableWidgetItem(QString::number(p_ping->pingNumber - (result_vec[single_box_num-1].y+result_vec[single_box_num-1].h/2)))); // 所在ping数
    if (result_vec[single_box_num-1].x > p_ping->numSamples)
    {
        ui->tableWidget->setItem(idxTable, 3, new QTableWidgetItem(QString("Starboard"))); // right = starboard ; left = port;
        ui->tableWidget->setItem(idxTable, 4, new QTableWidgetItem(QString::number(result_vec[single_box_num-1].x - p_ping->numSamples)));
    }
    else
    {
        ui->tableWidget->setItem(idxTable, 3, new QTableWidgetItem(QString("Port")));
        ui->tableWidget->setItem(idxTable, 4, new QTableWidgetItem(QString::number(p_ping->numSamples - result_vec[single_box_num-1].x)));
    }
    ui->tableWidget->setItem(idxTable, 5, new QTableWidgetItem(QString::number(result_vec[single_box_num-1].w))); // 框中心的宽
    ui->tableWidget->setItem(idxTable, 6, new QTableWidgetItem(QString::number(result_vec[single_box_num-1].h))); // 框中心的高

    int pingNum = DETECT_SIZE - int(result_vec[single_box_num-1].y+result_vec[single_box_num-1].h/2);
    ui->tableWidget->setItem(idxTable, 7, new QTableWidgetItem(QString::number(gps_array[pingNum][0], 'f', 6))); // gps_x
    ui->tableWidget->setItem(idxTable, 8, new QTableWidgetItem(QString::number(gps_array[pingNum][1], 'f', 6))); // gps_y

}

/***********************************************************************************************
 *                                        Geometry Map
 * *********************************************************************************************/
void MainWindow::geometryManager()
{
    ui->graphicsView->load(QUrl("file:///home/kim/PCL-Works/SonarDetector/Map/BaiduMap.html"));
    ui->graphicsView->show();

    // web <-> qt
    m_channel = new QWebChannel(this);
    m_channel->registerObject("context", (QObject*) m_jsContext);
    ui->graphicsView->page()->setWebChannel(m_channel);

    QObject::connect(m_jsContext, SIGNAL(CoordinatesGet(QString,QString)), this, SLOT(setGPS(QString,QString)));
    QObject::connect(m_jsContext, SIGNAL(ObjectIndexGet(QString)), this, SLOT(showObject(QString)));
//    QObject::connect(this, SIGNAL(objectAdded(double,double,int)), this, SLOT(sendObjectGPS2Web(double,double,int)));
    QObject::connect(this, SIGNAL(currentGPSSet()), this, SLOT(sendGPS2Web()));
    QObject::connect(this, SIGNAL(objectClicked(Mat&, double, int, int, double, double, string, int, int, vector<Point2f>&)),
                     dialog, SLOT(dialogShow(Mat&, double, int, int, double, double, string, int, int, vector<Point2f>&)));
    QObject::connect(this, SIGNAL(markerCleared()), this, SLOT(clearMarker()));
}

void MainWindow::clearMarker()
{
    QString cmd = QString("clearALL()");
    ui->graphicsView->page()->runJavaScript(cmd);
}

void MainWindow::setGPS(QString lon, QString lat)
{
    ui->label_gps->setText("("+lon+","+lat+")");
}

void MainWindow::showObject(QString index)
{
    int idx = index.toInt();
    emit objectClicked(object_Mat[idx], object_Prob[idx], object_PingNum[idx], object_SampleNum[idx], object_Longtitude[idx], object_Latitude[idx], object_direction[idx],
                       object_height[idx], object_width[idx], dst_points[idx]);
}

void MainWindow::sendGPS2Web()
{
    if (longtitude_init != 0 && latitude_init != 0)
    {
        QString cmd = QString("addStartPosition(%0, %1)")
                .arg(QString::number(longtitude_init, 'f', 6)).arg(QString::number(latitude_init, 'f', 6));
        ui->graphicsView->page()->runJavaScript(cmd);
    }
}

void MainWindow::sendObjectGPS2Web(double lon, double lat, int index)
{
    if (lon != 0 && lat != 0)
    {
        QString cmd = QString("addObjectPosition(%0, %1, %2)")
                .arg(QString::number(lon, 'f', 6)).arg(QString::number(lat, 'f', 6)).arg(QString::number(index));
        ui->graphicsView->page()->runJavaScript(cmd);
    }
}

void MainWindow::updateObjectMat(Mat &input, std::vector<bbox_t> result_vec, vector<vector<double> > &gps_array, pingFrame *p_ping, int single_box_num, int idxTable)
{
    if ((result_vec[single_box_num-1].x + result_vec[single_box_num-1].w) > input.cols )
    {
        result_vec[single_box_num-1].w = input.cols - result_vec[single_box_num-1].x;
    }

    if ((result_vec[single_box_num-1].y + result_vec[single_box_num-1].h) > input.rows )
    {
        result_vec[single_box_num-1].h = input.rows - result_vec[single_box_num-1].y;
    }

    Rect box(result_vec[single_box_num-1].x, result_vec[single_box_num-1].y, result_vec[single_box_num-1].w, result_vec[single_box_num-1].h);
    Mat boxArea = input(box).clone();
    int pingNum = DETECT_SIZE - int(result_vec[single_box_num-1].y+result_vec[single_box_num-1].h/2);

    object_Mat.push_back(boxArea);
    object_Prob.push_back(result_vec[single_box_num-1].prob);
    if (result_vec[single_box_num-1].x > p_ping->numSamples)
    {
        object_SampleNum.push_back(result_vec[single_box_num-1].x - p_ping->numSamples);
        object_direction.push_back("Starboard");
    }
    else
    {
        object_SampleNum.push_back(p_ping->numSamples - result_vec[single_box_num-1].x);
        object_direction.push_back("Port");
    }
    object_PingNum.push_back(p_ping->pingNumber - (result_vec[single_box_num-1].y+result_vec[single_box_num-1].h/2));
    object_Longtitude.push_back(gps_array[pingNum][0]);
    object_Latitude.push_back(gps_array[pingNum][1]);

    sendObjectGPS2Web(gps_array[pingNum][0], gps_array[pingNum][1], idxTable);
    QThread::msleep(180); // to be optimized

}

void MainWindow::geometryEncoder(std::vector<bbox_t> result_vec, vector<vector<double> > &gps_array, pingFrame *p_ping, int single_box_num)
{
    int curPingNumUp = int(DETECT_SIZE-(result_vec[single_box_num-1].y + result_vec[single_box_num-1].h));
    int curPingNumDown = int(DETECT_SIZE- result_vec[single_box_num-1].y - 1);

    vector<double> upFrontGPS, upBehindGPS, upMidGPS;
    vector<double> downFrontGPS, downBehindGPS, downMidGPS;
    if (curPingNumUp == 0)
    {
        upFrontGPS = gps_array[curPingNumUp];
        upMidGPS = gps_array[curPingNumUp];
        upBehindGPS = gps_array[curPingNumUp+1];
        downFrontGPS = gps_array[curPingNumDown-1];
        downMidGPS = gps_array[curPingNumDown];
        downBehindGPS = gps_array[curPingNumDown+1];
    }
    else if (curPingNumDown == DETECT_SIZE-1)
    {
        upFrontGPS = gps_array[curPingNumUp-1];
        upMidGPS = gps_array[curPingNumUp];
        upBehindGPS = gps_array[curPingNumUp+1];
        downFrontGPS = gps_array[curPingNumDown-1];
        downMidGPS = gps_array[curPingNumDown];
        downBehindGPS = gps_array[curPingNumDown];
    }
    else
    {
        upFrontGPS = gps_array[curPingNumUp-1];
        upMidGPS = gps_array[curPingNumUp];
        upBehindGPS = gps_array[curPingNumUp+1];
        downFrontGPS = gps_array[curPingNumDown-1];
        downMidGPS = gps_array[curPingNumDown];
        downBehindGPS = gps_array[curPingNumDown+1];
    }

    double up = sqrt((upBehindGPS[0]-upFrontGPS[0])*(upBehindGPS[0]-upFrontGPS[0]) + (upBehindGPS[1]-upFrontGPS[1])*(upBehindGPS[1]-upFrontGPS[1]));
    double down = sqrt((downBehindGPS[0]-downFrontGPS[0])*(downBehindGPS[0]-downFrontGPS[0]) + (downBehindGPS[1]-downFrontGPS[1])*(downBehindGPS[1]-downFrontGPS[1]));

    Eigen::Vector2d vecUp;
    Eigen::Vector2d vecDown;
    vecUp << (upBehindGPS[0]-upFrontGPS[0])/up, (upBehindGPS[1]-upFrontGPS[1])/up;
    vecDown << (downBehindGPS[0]-downFrontGPS[0])/up, (downBehindGPS[1]-downFrontGPS[1])/down;

    int point_pixel[4];
    float point_meter[4];
    if (result_vec[single_box_num-1].x > p_ping->numSamples)
    {
        point_pixel[0] = int(result_vec[single_box_num-1].x - p_ping->numSamples);
        point_pixel[1] = int(result_vec[single_box_num-1].x - p_ping->numSamples + result_vec[single_box_num-1].w);
        point_pixel[2] = int(result_vec[single_box_num-1].x - p_ping->numSamples);
        point_pixel[3] = int(result_vec[single_box_num-1].x - p_ping->numSamples + result_vec[single_box_num-1].w);
    }
    else
    {
        point_pixel[0] = int(p_ping->numSamples - result_vec[single_box_num-1].x);
        point_pixel[1] = int(p_ping->numSamples - result_vec[single_box_num-1].x - result_vec[single_box_num-1].w);
        point_pixel[2] = int(p_ping->numSamples - result_vec[single_box_num-1].x);
        point_pixel[3] = int(p_ping->numSamples - result_vec[single_box_num-1].x - result_vec[single_box_num-1].w);
    }

    point_meter[0] = gps_array[curPingNumDown][2]/gps_array[curPingNumDown][3] * point_pixel[0];
    point_meter[1] = gps_array[curPingNumDown][2]/gps_array[curPingNumDown][3] * point_pixel[1];
    point_meter[2] = gps_array[curPingNumUp][2]/gps_array[curPingNumUp][3] * point_pixel[2];
    point_meter[3] = gps_array[curPingNumUp][2]/gps_array[curPingNumUp][3] * point_pixel[3];

    Eigen::Vector2d pos1, pos2, pos3, pos4;
    pos1 = ge->pjEcho(vecDown, gps_array[curPingNumDown][0], gps_array[curPingNumDown][1], point_meter[0]);
    pos2 = ge->pjEcho(vecDown, gps_array[curPingNumDown][0], gps_array[curPingNumDown][1], point_meter[1]);
    pos3 = ge->pjEcho(vecUp, gps_array[curPingNumUp][0], gps_array[curPingNumUp][1], point_meter[2]);
    pos4 = ge->pjEcho(vecUp, gps_array[curPingNumUp][0], gps_array[curPingNumUp][1], point_meter[3]);

    vector<int> e1, e2, e3;
    for (int i = 0; i < 2; i++)
    {
        float a = (pos2[i] - pos1[i])/MAP_RESOLUTION;
        float b = (pos3[i] - pos1[i])/MAP_RESOLUTION;
        float c = (pos4[i] - pos1[i])/MAP_RESOLUTION;
        e1.push_back(a);
        e2.push_back(b);
        e3.push_back(c);
    }

    int height, width;
    int x, y;
    if (e1[1] < 0)
    {
        vector<int> comp{e2[1], e3[1]};
        height = -e1[1] + *std::max_element(comp.begin(), comp.end());
        y = -e1[1];
    }
    else
    {
        vector<int> comp{e1[1], e2[1], e3[1]};
        height = *std::max_element(comp.begin(), comp.end());
        y = 0;
    }

    if (e2[0] < 0)
    {
        vector<int> comp{e1[0], e3[0]-e2[0], std::abs(e1[0]-e2[0])};
        x = -e2[0];
        width = *std::max(comp.begin(), comp.end());
    }
    else
    {
        vector<int> comp{e1[0], e3[0]};
        x = 0;
        width = *std::max_element(comp.begin(), comp.end());
    }

    vector<Point2f> dst_points_array;
    dst_points_array.push_back(Point2f(x, y));
    dst_points_array.push_back(Point2f(x+e1[0], y+e1[1]));
    dst_points_array.push_back(Point2f(x+e3[0], y+e3[1]));
    dst_points_array.push_back(Point2f(x+e2[0], y+e2[1]));
    dst_points.push_back(dst_points_array);

    object_height.push_back(height);
    object_width.push_back(width);
}

/***********************************************************************************************
 *                                        buttons
 * *********************************************************************************************/
void MainWindow::on_btn_start_clicked()
{
    if (systemInit())
    {
        infoClear();
        ui->btn_start->setText("Restart");
        ui->btn_stop->setEnabled(1);
        ui->radioButton_fast->setEnabled(0);
        ui->radioButton_medium->setEnabled(0);
        ui->radioButton_precise->setEnabled(0);
        ui->actionExit->setEnabled(1);
        ui->actionStop->setEnabled(1);
        ui->actionPause_Application->setEnabled(1);
        ui->actionSpeed_Down->setEnabled(1);
        ui->actionSpeed_Up->setEnabled(1);
        ui->actionReal_TIme->setEnabled(0);
        ui->actionSimulation->setEnabled(0);
        imageDetect();
    }
}

void MainWindow::on_btn_stop_clicked()
{
    ui->btn_start->setText("Start");
    ui->btn_stop->setEnabled(0);
    ui->radioButton_fast->setEnabled(1);
    ui->radioButton_medium->setEnabled(1);
    ui->radioButton_precise->setEnabled(1);
    ui->actionPause_Application->setEnabled(0);
    ui->actionSpeed_Down->setEnabled(0);
    ui->actionSpeed_Up->setEnabled(0);
    ui->actionReal_TIme->setEnabled(1);
    ui->actionSimulation->setEnabled(1);

    emit markerCleared();
}

void MainWindow::on_btn_connect_clicked()
{
    if (ui->lineEdit_IP->text().isEmpty() || ui->lineEdit_Port->text().isEmpty())
    {
        QMessageBox::about(NULL,"ERROR","Please Select the Port and IP Address");
        return;
    }
    port = ui->lineEdit_Port->text().toInt();
    ip = ui->lineEdit_IP->text().toStdString();
    QMessageBox::about(NULL,"SUCCEED","Successully set the connection");
}

void MainWindow::on_radioButton_fast_clicked()
{
    cfg_file = "/home/kim/PCL-Works/Image_Detection/AlexeyAB_darknet/data/sonarData/sonar-MobileNetV2-YOLOv3-Lite.cfg";
    weights_file = "/home/kim/PCL-Works/Image_Detection/AlexeyAB_darknet/data/sonarData/backup/sonar-MobileNetV2-YOLOv3-Lite_best.weights";
    statusLabel->clear();
    emit weightSelected();
}

void MainWindow::on_radioButton_precise_clicked()
{
    cfg_file = "/home/kim/PCL-Works/Image_Detection/AlexeyAB_darknet/data/sonarData/sonar.cfg";
    weights_file = "/home/kim/PCL-Works/Image_Detection/AlexeyAB_darknet/data/sonarData/backup/sonar_best.weights";
    statusLabel->clear();
    emit weightSelected();
}

void MainWindow::on_radioButton_medium_clicked()
{
    cfg_file = "/home/kim/PCL-Works/Image_Detection/AlexeyAB_darknet/data/sonarData/sonar_prune.cfg";
    weights_file = "/home/kim/PCL-Works/Image_Detection/AlexeyAB_darknet/data/sonarData/backup/sonar_prune_finetune.weights";
    statusLabel->clear();
    emit weightSelected();
}

void MainWindow::on_btn_save_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("csv file"), QString("./detect_info.csv"), tr("Excel Files(*.csv)"));

    if(fileName.isEmpty())
    {
        return;
    }

    QFile file(fileName);

    bool ret = file.open(QIODevice::Truncate | QIODevice::WriteOnly);
    if (!ret)
    {
        return;
    }

    QTextStream out(&file);
    QString contents;
    QHeaderView *header = ui->tableWidget->horizontalHeader();
    if (header)
    {
        for(int i = 0; i < header->count(); i++)
        {
            QTableWidgetItem *item = ui->tableWidget->horizontalHeaderItem(i);
            if (!item)
            {
                continue;
            }
            contents += item->text() + ',';
        }
        contents += "\n";
    }

    for( int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        for( int j = 0; j < ui->tableWidget->columnCount(); j++)
        {
            QTableWidgetItem *item = ui->tableWidget->item(i, j);
            if (!item)
            {
                continue;
            }
            QString str = item->text();
            str.replace(",",",");
            contents += str + ",";
        }
        contents += "\n";
    }
    out << contents;
    file.close();

    if (QMessageBox::question(NULL,QString::fromUtf8("完成"),QString::fromUtf8("文件已经导出，是否现在打开？"),QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {

        QDesktopServices::openUrl(QUrl("file:///" + QDir::toNativeSeparators(fileName)));

    }
}

/***********************************************************************************************
 *                                        main tool bar
 * *********************************************************************************************/
void MainWindow::toolBarManager()
{
    connect(ui->actionExit, SIGNAL(triggered(bool)), this, SLOT(appQuit()));
    connect(ui->actionSpeed_Up, SIGNAL(triggered(bool)), this, SLOT(speedUp()));
    connect(ui->actionSpeed_Down, SIGNAL(triggered(bool)), this, SLOT(speedDown()));
    connect(ui->actionOpen_File, SIGNAL(triggered(bool)), this, SLOT(openFile()));
    connect(ui->actionSave, SIGNAL(triggered(bool)), this, SLOT(on_btn_save_clicked()));
    connect(ui->actionScreenshot, SIGNAL(triggered(bool)), this, SLOT(screenShot()));
    connect(ui->actionSelect_Project_Path, SIGNAL(triggered(bool)), this, SLOT(selectProjPath()));
    connect(ui->actionReal_TIme, SIGNAL(triggered(bool)), this, SLOT(selectRealTimeMode()));
    connect(ui->actionSimulation, SIGNAL(triggered(bool)), this, SLOT(selectOffMode()));
    connect(ui->actionPause_Application, SIGNAL(triggered(bool)), this, SLOT(simulationPause()));
    connect(ui->actionStart_Application, SIGNAL(triggered(bool)), this, SLOT(on_btn_start_clicked()));
    connect(ui->actionStop, SIGNAL(triggered(bool)), this, SLOT(on_btn_stop_clicked()));
    connect(this, SIGNAL(appQuited()), this, SLOT(on_btn_stop_clicked()));
}

void MainWindow::openFile()
{
    QString str_path = QFileDialog::getOpenFileName(this, tr("select xtf file"));
    if (str_path != ""){
        file_path = str_path.toStdString();
    }
}

void MainWindow::appQuit()
{
#if(SIMULATOR)
    if (p_simulator)
    {
        p_simulator->pauseSimulator();
        if (!(QMessageBox::information(this,tr("Exit Warning"),tr("Do you really want exit ?"),tr("Yes"),tr("No"))))
        {
            qApp->quit();
            emit appQuited();
        }
        p_simulator->unpauseSimulator();
    }
#else
    qApp->quit();
#endif
}

void MainWindow::speedUp()
{
    if (p_simulator->getSpeed() < p_simulator->_MAX_SPEED)
    {
        QMessageBox::about(NULL, "ERROR", "Out of MAX Speed");
        return;
    }
    p_simulator->speedUp();
}

void MainWindow::speedDown()
{
    if (p_simulator->getSpeed() > p_simulator->_MIN_SPEED)
    {
        QMessageBox::about(NULL, "ERROR", "Out of MIN Speed");
        return;
    }
    p_simulator->speedDown();
}

void MainWindow::infoClear()
{
    ui->label_TimeStamp->clear();
    ui->label_PingNumber->clear();
    ui->label_SensorHeading->clear();
    ui->label_SensorPitch->clear();
    ui->label_SensorRoll->clear();
    ui->label_SensorSpeed->clear();
    ui->label_SensorPriAltitude->clear();
    ui->label_SensorXcoord->clear();
    ui->label_SensorYcoord->clear();
    ui->label_bytePerSample->clear();
    ui->label_ShipGyro->clear();
    ui->label_ShipSpeed->clear();
    ui->label_PacketType->clear();
    ui->label_SlantRange->clear();
    ui->label_SoundVelocity->clear();
    ui->label_detectionCounts->clear();
    ui->label_detectionBoxesNumber->clear();
    while(ui->tableWidget->rowCount() > 0)
    {
        ui->tableWidget->removeRow(ui->tableWidget->rowCount()-1);
    }
    statusLabel->clear();
    box_num = 0;
}

void MainWindow::screenShot()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    if (const QWindow *window = windowHandle())
        screen = window->screen();
    if (!screen)
        return;
    QPixmap originalPixmap = screen->grabWindow(0);
    QDateTime time = QDateTime::currentDateTime();
    if (!originalPixmap.save(project_path + "/" + time.toString("yy-MM-dd hh:mm:ss") + ".jpg"))
    {
        QMessageBox::about(NULL, "ERROR", "Please Select Project Path");
    }
}

void MainWindow::selectProjPath()
{
    project_path = QFileDialog::getExistingDirectory(this, tr("select directory"));
}

void MainWindow::selectOffMode()
{
    simulation = 1;
}

void MainWindow::selectRealTimeMode()
{
    simulation = 0;
}

void MainWindow::simulationPause()
{
    if (ui->actionPause_Application->iconText() == "run")
    {
        ui->actionPause_Application->setIconText("pause");
        p_simulator->unpauseSimulator();
    }
    else if (ui->actionPause_Application->iconText() == "pause")
    {
        ui->actionPause_Application->setIconText("run");
        p_simulator->pauseSimulator();
    }
}
