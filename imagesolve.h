#ifndef IMAGESOLVE_H
#define IMAGESOLVE_H

#include "mainwindow.h"

using namespace cv;

class imageSolver
{
public:
    imageSolver();
    ~imageSolver();

    void imageGain(Mat& ssImage, int numSamples);
    void updateMat(Mat* src);
    void copyToMat(unsigned char * src,unsigned char * dst,unsigned int len, int fBytesPerSample);
    void gray2Color(Mat& gray, Mat& color);
    void siglePingShow(Mat rawPingImg, pingFrame *p_ping);
    void imgSegment(vector<Mat> &imgSet, Mat input, int width);
};




#endif // IMAGESOLVE_H
