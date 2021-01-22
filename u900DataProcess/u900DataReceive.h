#ifndef U900DATARECEIVE_H_
#define U900DATARECEIVE_H_
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<iostream>
#include <queue>

#include<cstring>
#include <vector>
#include <thread>
#include <functional>
//#include "xtfDataTrans.h"
#include "u900PingTrans.h"
#include "XTFReader/frame.h"
//#include<xtfDataTypesTransform.h>
using namespace std;
class u900DataReceive{
    public:
        u900DataReceive();
        ~u900DataReceive();
        //socket paraments
        int socket_fd;
        struct sockaddr_in addr;
        int socket_port;
        std::string socket_ip;
        int connect_state;

        //frame paraments
        int pingSize;       //the length per ping
        int fBytesPerSample;
        int fNumSamples;

        bool connectionState;
        bool receivingDataState;
        bool stopButtonState;

        struct xtf_pingpacket pingPacket;

        u900PingTrans transToXtfStruct;

        //void u900DadtaReceiveInit();
        bool connetSideScan();
        bool disconnectSideScan();
        bool receiveData();
        int startReceiveData();
        int stopReceiveData();
        int fetchFrame(Frame * &pFrame);
    
    private:
        //static std::vector<std::thread *> u900Threads;
        //static std::mutex frameQueueMutex;
        std::queue<Frame *> frameQueue;
        
};
#endif
