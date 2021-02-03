#ifndef GEOENCODER_H_
#define GEOENCODER_H_
#ifndef ACCEPT_USE_OF_DEPRECATED_PROJ_API_H
#define ACCEPT_USE_OF_DEPRECATED_PROJ_API_H
#endif
#include <proj_api.h>
#include <eigen3/Eigen/Eigen>
#include <list>
#include "XTFReader/frame.h"
#include "XTFReader/logger.h"
#include "XTFReader/status.h"

struct pjCartographic{
    projCtx pjCtx;
    projPJ pjWGS84;
    projPJ pjMerc;
};
class encodedPingFrame{
public:
    encodedPingFrame(){
        p_pos[0]=nullptr;
        p_pos[1]=nullptr;
        p_data[0]=nullptr;
        p_data[1]=nullptr;
    }
    ~encodedPingFrame(){
        if(p_pos[0])
            free(p_pos[0]);
        if(p_pos[1])
            free(p_pos[1]);
        if(p_data[0])
            free(p_data[0]);
        if(p_data[1])
            free(p_data[1]);
    }
public:
    unsigned int pingNumber;
    unsigned int numSamples;
    Eigen::Vector2d* p_pos[2];
    char* p_data[2];
};
class geoEncoder{
public:
    geoEncoder();
    ~geoEncoder();
    int pjGeo2Merc(double longtitude,double latitude,double &x,double &y);
    int pjMerc2Geo(double x,double y,double &longtitude,double &latitude);
    encodedPingFrame* getNextEncodedPing();
    int SendToEncoding(pingFrame* p_ping);
    int initGeoEncoding();
    int closeGeoEncoder();
    Eigen::Vector2d pjEcho(Eigen::Vector2d vec,float sensorXcoordinate,float sensorYcoordinate,float x);
private:
    int encodingProc();
private:
    bool stopEncoder;
    pjCartographic pj;
    std::list<pingFrame*> oriPings;
    std::list<encodedPingFrame*> encodedPings;
    std::mutex m_oriPingsMutex;
    std::mutex m_encodedPingsMutex;
    std::condition_variable m_cond;
    std::mutex m_mu;
    std::thread* p_geoEncodingThread;
};

#endif
