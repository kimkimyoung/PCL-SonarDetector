#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QToolButton>
#include <QLabel>
#include <QDir>
#include <QDateTime>
#include <QTextStream>
#include <QProgressBar>
#include <QWebEngineView>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QUrl>
#include <QWebChannel>
#include <QDesktopServices>
#include <QWindow>
#include <QScreen>
#include <QDebug>
#include <QThread>

#include <cmath>
#include <string>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <eigen3/Eigen/StdVector>
#include <stdlib.h>
#include <fstream>
#include <algorithm>

#include "GeoEncoder/geoencoder.h"
#include "XTFReader/logger.h"
#include "XTFReader/simulator.h"
#include "XTFReader/frame.h"
#include "u900DataProcess/u900DataReceive.h"
#include "u900DataProcess/u900PingTrans.h"
#include "eventlabel.h"
#include "imagesolve.h"
#include "yolo_v2_class.h"
#include "jscontext.h"
#include "dialog.h"



#define DETECT_SIZE 500
#define WINDOW_H 1000
#define WINDOW_W 2400

using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int systemInit();
    void imageDetect();
    void systemManager();
    void toolBarManager();
    void geometryManager();
    void infoClear();

    void sonarInfoShow(pingFrame *p_ping);
    void detectionInfoShow();
    void detectionResultShow(pingFrame *p_ping, vector<bbox_t> &result_vec, int idxSeg, int lengthSeg,  vector<vector<double> > &gps_array, int single_box_num, int idxTable);
    void detectionResultShow(pingFrame *p_ping, vector<bbox_t> &result_vec, vector<vector<double> > &gps_array, int single_box_num, int idxTable);

    void gpsArrayUpdate(pingFrame *p_ping, int id, vector<vector<double> > &gps_array);
    void objNameInit(vector<string> &obj_names);
    void draw_boxes(cv::Mat mat_img, std::vector<bbox_t> result_vec, std::vector<std::string> &obj_names);

    void updateObjectMat(Mat& input, std::vector<bbox_t> result_vec, vector<vector<double> > &gps_array, pingFrame *p_ping, int single_box_num, int idxTable);
    void geometryEncoder(std::vector<bbox_t> result_vec, vector<vector<double> > &gps_array, pingFrame *p_ping, int single_box_num);

private:
    Ui::MainWindow *ui;
    Detector *detector;
    imageSolver *solver;
    simulator *p_simulator;
    u900DataReceive *u900Sonar;
    geoEncoder *ge = new geoEncoder();
    QLabel *statusLabel;
    QWebChannel *m_channel;
    JsContext *m_jsContext = new JsContext();
    Dialog *dialog = new Dialog();

    string cfg_file;
    string weights_file;
//    string file_path = "/home/kim/PCL-Works/DataSet/SideScanSonar_DataSet/SongShanHu/cs_ssh_20210110/cs_ssh_20210110/LogData/20210110_143029_01.XTF";
    string file_path = "/home/kim/PCL-Works/side_scan_mosaic/data/NY_HudsonRiver/000_1400.xtf";
    string names_file = "/home/kim/PCL-Works/Image_Detection/AlexeyAB_darknet/data/sonarData/sonar.names";
    QString project_path;

    int port;
    string ip;

    int initPingNum;
    int detect_time = 0;
    int box_num = 0;
    double longtitude_init = 0;
    double latitude_init = 0;
    vector<Mat> object_Mat;
    vector<double> object_Prob;
    vector<int> object_PingNum;
    vector<int> object_SampleNum;
    vector<double> object_Longtitude;
    vector<double> object_Latitude;
    vector<string> object_direction;
    vector<int> object_height;
    vector<int> object_width;
    vector<vector<Point2f>> dst_points;

    bool runningFlag;
    int simulation = 1;

private slots:
    void detectorInit();

    void on_btn_save_clicked();
    void on_btn_start_clicked();
    void on_btn_stop_clicked();
    void on_btn_connect_clicked();
    void on_radioButton_fast_clicked();
    void on_radioButton_precise_clicked();
    void on_radioButton_medium_clicked();

    void appQuit();
    void speedUp();
    void speedDown();
    void openFile();
    void screenShot();
    void selectProjPath();
    void selectOffMode();
    void selectRealTimeMode();
    void simulationPause();

    void setGPS(QString lon, QString lat);
    void sendGPS2Web();
    void sendObjectGPS2Web(double lon, double lat, int index);
    void showObject(QString index);
    void clearMarker();

signals:
    void weightSelected();
    void appQuited();
    void currentGPSSet();
    void objectAdded(double lon, double lat, int index);
    void objectClicked(Mat &object, double prob, int pingNum, int numsample, double lon, double lat, string direction, int height, int width, vector<Point2f> &dst);
    void markerCleared();
};

#endif // MAINWINDOW_H
