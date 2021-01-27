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

void imageSolver::imageGain(Mat& ssImage, pingFrame* p_ping, int ii)
{
    if (p_ping->bytesPerSample == 1)
    {
        if ((ssImage.ptr<unsigned short>(0)[ii] + ALFA * log10(p_ping->numSamples-ii) + GAMA * (p_ping->numSamples-ii)) > 255)
            ssImage.ptr<unsigned short>(0)[ii] = 255;
        else
            ssImage.ptr<unsigned short>(0)[ii] = ssImage.ptr<unsigned short>(0)[ii] + ALFA * log10(p_ping->numSamples-ii) + GAMA * (p_ping->numSamples-ii);
        if ((ssImage.ptr<unsigned short>(0)[ii+p_ping->numSamples] + ALFA * log10(ii) + GAMA * (ii)) > 255)
            ssImage.ptr<unsigned short>(0)[ii+p_ping->numSamples] = 255;
        else
            ssImage.ptr<unsigned short>(0)[ii+p_ping->numSamples] = ssImage.ptr<unsigned short>(0)[ii+p_ping->numSamples] + ALFA * 10 * log10(ii) + GAMA * (ii);
    }
    else if (p_ping->bytesPerSample == 2)
    {
        if ((ssImage.ptr<unsigned short>(0)[ii] + ALFA * log10(p_ping->numSamples-ii) + GAMA * (p_ping->numSamples-ii)) > 65535)
            ssImage.ptr<unsigned short>(0)[ii] = 65535;
        else
            ssImage.ptr<unsigned short>(0)[ii] = ssImage.ptr<unsigned short>(0)[ii] + ALFA * log10(p_ping->numSamples-ii) + GAMA * (p_ping->numSamples-ii);
        if ((ssImage.ptr<unsigned short>(0)[ii+p_ping->numSamples] + ALFA * log10(ii) + GAMA * (ii)) > 65535)
            ssImage.ptr<unsigned short>(0)[ii+p_ping->numSamples] = 65535;
        else
            ssImage.ptr<unsigned short>(0)[ii+p_ping->numSamples] = ssImage.ptr<unsigned short>(0)[ii+p_ping->numSamples] + ALFA * log10(ii) + GAMA * (ii);
    }
}

void imageSolver::updateMat(cv::Mat* src){
    int ii,jj;
    unsigned short* ptr_dst;
    unsigned short* ptr_src;
    for(ii=src->rows-2; ii>0 || ii==0;ii--){
        ptr_dst=src->ptr<unsigned short>(ii+1);
        ptr_src=src->ptr<unsigned short>(ii);
        for(jj=0;jj<src->cols;jj++){
            *(ptr_dst+jj)=*(ptr_src+jj);
        }
    }
}

void imageSolver::gray2Color(Mat& gray, Mat& color)
{
    for (int i = 0; i < gray.rows; i++)
    {
        ushort *ptr_gray = gray.ptr<ushort>(i);
        Vec3s *ptr_color = color.ptr<Vec3s>(i);
        for (int j = 0; j < gray.cols; j++)
        {
            ptr_color[j][0] = abs(0.10 * ptr_gray[j] + COMPENSARION_VALUE);
            ptr_color[j][1] = abs(0.50 * ptr_gray[j] + COMPENSARION_VALUE);
            ptr_color[j][2] = abs(0.90 * ptr_gray[j] + COMPENSARION_VALUE);
        }
    }
}

void imageSolver::siglePingShow(Mat& rawPingImg, Mat& ssImage)
{
    Mat img8bit;
    ssImage.convertTo(img8bit, CV_8UC1);
    for (int k = 1; k < img8bit.cols; k++)
    {
        Point p1(k-1, 255-img8bit.at<uchar>(0, k-1));
        Point p2(k, 255-img8bit.at<uchar>(0, k));
        line(rawPingImg, p1, p2, cvScalar(255), 1);
    }

//    for (unsigned int k = 1; k < p_ping->numSamples; k++)
//    {
//        Mat img8bit;
//        ssImage.convertTo(img8bit, CV_8UC1);


//        if (p_ping->bytesPerSample == 1)
//        {
//            Point p1(k-1, 255-*((unsigned char*)p_ping->p_data[0]+(k-1)*p_ping->bytesPerSample));
//            Point p2(k, 255-*((unsigned char*)p_ping->p_data[0]+k*p_ping->bytesPerSample));
//            line(rawPingImg, p1, p2, cvScalar(255), 1);
//            Point p3(k+p_ping->numSamples-1, 255-*((unsigned char*)p_ping->p_data[1]+(k-1)*p_ping->bytesPerSample));
//            Point p4(k+p_ping->numSamples, 255-*((unsigned char*)p_ping->p_data[1]+k*p_ping->bytesPerSample));
//            line(rawPingImg, p3, p4, cvScalar(255), 1);
//        }
//        else if (p_ping->bytesPerSample == 2)
//        {
//            int ii = (int)(*((unsigned short*)p_ping->p_data[0]+(k-1)*p_ping->bytesPerSample)/65535*255);
//            int i = 255-(*((unsigned short*)p_ping->p_data[0]+(k-1)*p_ping->bytesPerSample))/65535*255;
//            Point p1(k-1, 255-(*((unsigned short*)p_ping->p_data[0]+(k-1)*p_ping->bytesPerSample))/65535*255);
//            Point p2(k, 255-(*((unsigned short*)p_ping->p_data[0]+k*p_ping->bytesPerSample))/65535*255);
//            line(rawPingImg, p1, p2, cvScalar(255), 1);
//            Point p3(k+p_ping->numSamples-1, 255-(*((unsigned short*)p_ping->p_data[1]+(k-1)*p_ping->bytesPerSample))/65535*255);
//            Point p4(k+p_ping->numSamples, 255-(*((unsigned short*)p_ping->p_data[1]+k*p_ping->bytesPerSample))/65535*255);
//            line(rawPingImg, p3, p4, cvScalar(255), 1);
//        }
//    }
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



















