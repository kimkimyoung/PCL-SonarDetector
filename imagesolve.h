#ifndef IMAGESOLVE_H
#define IMAGESOLVE_H

#include <cmath>
#include <string>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <eigen3/Eigen/StdVector>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include "XTFReader/frame.h"


using namespace std;
using namespace cv;

class imageSolver
{
public:
    imageSolver();
    ~imageSolver();

    void imageGain(Mat& ssImage, pingFrame* p_ping, int ii);
    void updateMat(Mat* src);
    void gray2Color(Mat& gray, Mat& color);
    void siglePingShow(Mat& rawPingImg, Mat& ssImage);
    void imgSegment(vector<Mat> &imgSet, Mat input, int width);
};




#endif // IMAGESOLVE_H
