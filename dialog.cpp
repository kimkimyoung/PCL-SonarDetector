#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QLabel>
#include <QDialog>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::dialogShow(Mat& object, double prob, int pingNum, int numSample, double lon, double lat, string direction, int height, int width, vector<Point2f> &dst_points)
{
    Mat rgb;
    cvtColor(object, rgb, COLOR_BGR2RGB);

    QImage disImage = QImage((const uchar*)(rgb.data), rgb.cols, rgb.rows, rgb.cols*rgb.channels(), QImage::Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(disImage);

    ui->label_view->setPixmap(pixmap);
    ui->lable_confidence->setText(QString::number(prob, 'f', 6));
    ui->label_pingnumber->setText(QString::number(pingNum));
    ui->label_numbersample->setText(QString::number(numSample));
    ui->label_longtitude->setText(QString::number(lon, 'f', 6));
    ui->label_latitude->setText(QString::number(lat, 'f', 6));
    ui->label_direction->setText(QString::fromStdString(direction));

    Mat ge(height, width, CV_8UC3, cvScalar(0, 0, 0));
    drawGeoMetry(ge, object, dst_points);

    Mat rgb_ge;
    cvtColor(ge, rgb_ge, COLOR_BGR2RGB);
    ui->label_geo->setPixmap(QPixmap::fromImage(QImage((const uchar*)(rgb_ge.data), rgb_ge.cols, rgb_ge.rows, rgb_ge.cols*rgb_ge.channels(), QImage::Format_RGB888)));

    this->show();
}

void Dialog::drawGeoMetry(Mat &ge, Mat &object, vector<Point2f> &dst_points)
{
    Size size = object.size();
    vector<Point2f> src_points;
    src_points.push_back(Point2f(0, 0));
    src_points.push_back(Point2f(size.width - 1, 0));
    src_points.push_back(Point2f(size.width - 1, size.height - 1));
    src_points.push_back(Point2f(0, size.height - 1));

    Mat temp = ge.clone();
    Mat h = cv::findHomography(src_points, dst_points);
    cv::warpPerspective(object, temp, h, temp.size());
    Point pts_dst[4];
    for (int j = 0; j < 4; j++)
    {
        pts_dst[j] = dst_points[j];
    }
    cv::fillConvexPoly(ge, pts_dst, 4, Scalar(0));
    ge = ge + temp;
}
