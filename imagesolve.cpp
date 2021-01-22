#include "imagesolve.h"

#define COMPENSARION_VALUE 2
#define ALFA 1 // sonar parameters
#define GAMA 0.01f // sonar parameters

imageSolver::imageSolver()
{

}

imageSolver::~imageSolver()
{

}

void imageSolver::imageGain(Mat& ssImage, int numSamples)
{
    for (int i = 0; i < numSamples; i++)
    {
        if ((int)(ssImage.ptr<unsigned char>(WINDOW_H-1)[i] + ALFA * 10 * log10(numSamples-i) + GAMA * (numSamples-i)) > 255)
        {
            ssImage.ptr<unsigned char>(WINDOW_H-1)[i] = 255;
        }
        else
        {
            ssImage.ptr<unsigned char>(WINDOW_H-1)[i] = (int)(ssImage.ptr<unsigned char>(WINDOW_H-1)[i] + ALFA * 10 * log10(numSamples-i) + GAMA * (numSamples-i));
        }

        if ((int)((ssImage.ptr<unsigned char>(WINDOW_H-1)+numSamples)[i] + ALFA * 10 * log10(i) + GAMA * i) > 255)
        {
            (ssImage.ptr<unsigned char>(WINDOW_H-1)+numSamples)[i] = 255;
        }
        else
        {

            (ssImage.ptr<unsigned char>(WINDOW_H-1)+numSamples)[i] = (ssImage.ptr<unsigned char>(WINDOW_H-1)+numSamples)[i] + ALFA * 10 * log10(i) + GAMA * i;
        }
    }
}

void imageSolver::updateMat(cv::Mat* src){
    int ii,jj;
    unsigned char* ptr_dst;
    unsigned char* ptr_src;
    for(ii=src->rows-2; ii>0 || ii==0;ii--){
        ptr_dst=src->ptr<unsigned char>(ii+1);
        ptr_src=src->ptr<unsigned char>(ii);
        for(jj=0;jj<src->cols;jj++){
            *(ptr_dst+jj)=*(ptr_src+jj);
        }
    }
}

void imageSolver::copyToMat(unsigned char * src,unsigned char * dst,unsigned int len, int fBytesPerSample){
    unsigned int ii;
    for(ii=0; ii<len; ii++)
    {
        dst[ii] = src[fBytesPerSample*ii];
    }
}

void imageSolver::gray2Color(Mat& gray, Mat& color)
{
    for (int i = 0; i < gray.rows; i++)
    {
        uchar *ptr_gray = gray.ptr<uchar>(i);
        Vec3b *ptr_color = color.ptr<Vec3b>(i);
        for (int j = 0; j < gray.cols; j++)
        {
            ptr_color[j][0] = abs(0.10 * ptr_gray[j] + COMPENSARION_VALUE);
            ptr_color[j][1] = abs(0.50 * ptr_gray[j] + COMPENSARION_VALUE);
            ptr_color[j][2] = abs(0.90 * ptr_gray[j] + COMPENSARION_VALUE);
        }
    }
}

void imageSolver::siglePingShow(Mat rawPingImg, pingFrame *p_ping)
{
    for (unsigned int k = 1; k < p_ping->numSamples; k++)
    {
        Point p1(k-1, 255-*((unsigned char*)p_ping->p_data[0]+(k-1)*p_ping->bytesPerSample));
        Point p2(k, 255-*((unsigned char*)p_ping->p_data[0]+k*p_ping->bytesPerSample));
        line(rawPingImg, p1, p2, cvScalar(255), 1);
        Point p3(k+p_ping->numSamples-1, 255-*((unsigned char*)p_ping->p_data[1]+(k-1)*p_ping->bytesPerSample));
        Point p4(k+p_ping->numSamples, 255-*((unsigned char*)p_ping->p_data[1]+k*p_ping->bytesPerSample));
        line(rawPingImg, p3, p4, cvScalar(255), 1);
    }
}

void imageSolver::imgSegment(vector<Mat> &imgSet, Mat input, int width)
{
    int x = (width/2) / DETECT_SIZE;
    int y = (width/2) % DETECT_SIZE;
    int input_w = DETECT_SIZE + (y/x);

    for (int ii = 0; ii < 2*x; ii++)
    {
        Rect imgrect(ii*input_w, 0, input_w, DETECT_SIZE);
        imgSet.push_back(input(imgrect));
    }
}



















