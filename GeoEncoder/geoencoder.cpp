#include "geoencoder.h"

geoEncoder::geoEncoder(){
    pj.pjCtx=pj_ctx_alloc();
    pj.pjWGS84=pj_init_plus_ctx(pj.pjCtx,"+proj=longlat +ellps=WGS84 +datum=WGS84");
    pj.pjMerc=pj_init_plus_ctx(pj.pjCtx,
        "+proj=merc +lon_0=0 +lat_0=0 +k=1 +x_0=0 +y_0=0 +ellps=WGS84 +datum=WGS84 +units=m +no_defs");
    LOG(debug,"Success initialized a pj instance!");
    stopEncoder=true;
}

geoEncoder::~geoEncoder(){
    pj_free (pj.pjWGS84);
    pj_free (pj.pjMerc);
    LOG(debug,"delete pj instance!");
}

int geoEncoder::pjGeo2Merc(double longtitude,double latitude,double &x,double &y){
    x=longtitude*DEG_TO_RAD;
    y=latitude*DEG_TO_RAD;
    int proj_ret;
    proj_ret = pj_transform(pj.pjWGS84,pj.pjMerc, 1, 1, &x, &y, nullptr );
    return proj_ret;
}

int geoEncoder::pjMerc2Geo(double x,double y,double &longtitude,double &latitude){
    int proj_ret;
    proj_ret = pj_transform(pj.pjMerc,pj.pjWGS84, 1, 1, &x, &y, nullptr);
    longtitude=x*RAD_TO_DEG;
    latitude=y*RAD_TO_DEG;
    return proj_ret;
}

int geoEncoder::SendToEncoding(pingFrame* p_ping){
    m_oriPingsMutex.lock();
    oriPings.push_back(p_ping);
    m_oriPingsMutex.unlock();
    m_cond.notify_all();
    return SUCCESS;
}

int geoEncoder::initGeoEncoding(){
    stopEncoder=false;
    p_geoEncodingThread=new std::thread(std::bind(&geoEncoder::encodingProc, this));
    return SUCCESS;
}

int geoEncoder::closeGeoEncoder(){
    stopEncoder=true;
    m_cond.notify_all();
    p_geoEncodingThread->join();
    delete p_geoEncodingThread;
    while(oriPings.size()>=1){
        auto ptr=oriPings.front();
        oriPings.pop_front();
        delete ptr;
        LOG(debug,"clear oriPings");
    }
    while(encodedPings.size()>=1){
        auto ptr=encodedPings.front();
        encodedPings.pop_front();
        delete ptr;
        LOG(debug,"clear encodedPings");
    }
    LOG(debug,"stop geoEncoder.");
}

int geoEncoder::encodingProc(){
    std::unique_lock <std::mutex> lck(m_mu);
    LOG(debug,"entering encodingProc()")
    while(!stopEncoder){
        if(oriPings.size()<3)
            m_cond.wait(lck);
        else{
            std::list<pingFrame*>::iterator it=oriPings.begin();
            auto front=*it;
            auto mid=*(++it);
            auto behind=*(++it);

            double cx,cy;
            pjGeo2Merc(mid->sensorXcoordinate,mid->sensorYcoordinate,cx,cy);
            Eigen::Vector2d vec;
            vec<<behind->sensorXcoordinate-front->sensorXcoordinate,
                behind->sensorYcoordinate-front->sensorYcoordinate;
            vec=vec.normalized();
            //Eigen::Matrix3d rt;
            //rt<<vec.y(),vec.x(),cx,-vec.x(),vec.y(),cy,0,0,1;
            auto ptr=new encodedPingFrame;
            ptr->numSamples=mid->numSamples;
            ptr->pingNumber=mid->pingNumber;
            ptr->p_pos[0]=(Eigen::Vector2d*)malloc(ptr->numSamples*sizeof(Eigen::Vector2d));
            memset(ptr->p_pos[0], 0, ptr->numSamples*sizeof(Eigen::Vector2d));
            ptr->p_pos[1]=(Eigen::Vector2d*)malloc(ptr->numSamples*sizeof(Eigen::Vector2d));
            memset(ptr->p_pos[1], 0, ptr->numSamples*sizeof(Eigen::Vector2d));
            ptr->p_data[0]=(char*)malloc(ptr->numSamples*sizeof(char));
            memset(ptr->p_data[0], 0, ptr->numSamples*sizeof(char));
            ptr->p_data[1]=(char*)malloc(ptr->numSamples*sizeof(char));
            memset(ptr->p_data[1], 0, ptr->numSamples*sizeof(char));
            for(int ii=0;ii<ptr->numSamples;ii++){
                *(ptr->p_data[0]+ii)=*((char*)(mid->p_data[0])+ii);
                *(ptr->p_data[1]+ii)=*((char*)(mid->p_data[1])+ii);
            }
            double dx=mid->slantRange/mid->numSamples;
            for(int ii=1;ii<ptr->numSamples+1;ii++){
                double x=double(ii)*dx;
                *(ptr->p_pos[0]+ii-1)<<-vec.y()*x+cx,vec.x()*x+cy;
                *(ptr->p_pos[1]+ii-1)<<vec.y()*x+cx,-vec.x()*x+cy;
            }
            m_oriPingsMutex.lock();
            oriPings.pop_front();
            m_oriPingsMutex.unlock();
            m_encodedPingsMutex.lock();
            encodedPings.push_back(ptr);
            m_encodedPingsMutex.unlock();
            delete front;
        }
    }
    return SUCCESS;
}


Eigen::Vector2d geoEncoder::pjEcho(Eigen::Vector2d vec,float sensorXcoordinate,float sensorYcoordinate,float x){
    double cx,cy;
    pjGeo2Merc(sensorXcoordinate,sensorYcoordinate,cx,cy);
    //LOG(debug,"cx= "+std::to_string(mid->sensorXcoordinate)+" cy="+std::to_string(mid->sensorYcoordinate));
    Eigen::Vector2d pos;
    pos<<-vec.y()*x+cx,vec.x()*x+cy;
    return pos;
}

encodedPingFrame* geoEncoder::getNextEncodedPing(){
    encodedPingFrame* ptr=nullptr;
    if(!encodedPings.empty()){
        m_encodedPingsMutex.lock();
        ptr=encodedPings.front();
        encodedPings.pop_front();
        m_encodedPingsMutex.unlock();
    }
    return ptr;
}
