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

#include <cmath>
#include <string>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <eigen3/Eigen/StdVector>
#include <stdlib.h>
#include <fstream>

#include "XTFReader/logger.h"
#include "XTFReader/simulator.h"
#include "XTFReader/frame.h"
#include "u900DataProcess/u900DataReceive.h"
#include "u900DataProcess/u900PingTrans.h"
#include "eventlabel.h"
#include "imagesolve.h"
#include "yolo_v2_class.h"


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
    void infoClear();

    void sonarInfoShow(pingFrame *p_ping);
    void detectionInfoShow();
    void detectionResultShow(pingFrame *p_ping, vector<bbox_t> &result_vec, int idxSeg, int lengthSeg,  vector<vector<double> > &gps_array);

    void gpsArrayUpdate(pingFrame *p_ping, int id, vector<vector<double> > &gps_array);
    void objNameInit(vector<string> &obj_names);
    void draw_boxes(cv::Mat mat_img, std::vector<bbox_t> result_vec, std::vector<std::string> &obj_names);

private:
    Ui::MainWindow *ui;
    Detector *detector;
    simulator *p_simulator;
    u900DataReceive *u900Sonar;
    QLabel *statusLabel;
    QWebChannel *channel;

    string cfg_file;
    string weights_file;
    string file_path = "/home/kim/PCL-Works/side_scan_mosaic/data/xtf_data_20210118/ET4125_1600kHz_xtf/ET4125_1600kHz_Line1H.xtf";
    string names_file = "/home/kim/PCL-Works/Image_Detection/AlexeyAB_darknet/data/sonarData/sonar.names";
    QString project_path;

    int port;
    string ip;

    int initPingNum;
    int detect_time = 0;
    int box_num = 0;
    int single_box_num = 0;

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


signals:
    void weightSelected();
    void appQuited();
};

#endif // MAINWINDOW_H
