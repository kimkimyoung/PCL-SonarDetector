#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QListWidgetItem>

#include <cmath>
#include <string>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <eigen3/Eigen/StdVector>
#include <stdlib.h>
#include <fstream>

using namespace std;
using namespace cv;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void drawGeoMetry(Mat& ge, Mat& object, vector<Point2f> &dst_points);
signals:

private slots:
    void dialogShow(Mat& object, double prob, int pingNum, int numSample, double lon, double lat, string direction, int height, int width, vector<Point2f> &dst);

private:
    Ui::Dialog *ui;

};


#endif // DIALOG_H
