#include "u900DataProcess/u900DataReceive.h"
//#include "xtfDataTrans.h"

static std::vector<std::thread *> u900Threads;
static std::mutex frameQueueMutex;
//std::queue<Frame *> frameQueue;
/*
unsigned int Chars2Word(char *p){
    unsigned int n=(((unsigned char)((p)[1])) << 8) + (((unsigned char)((p)[0])));
    return n;
}

unsigned int Chars2Dword(char *p){
    unsigned int n=(((unsigned char)((p)[3])) << 24) + (((unsigned char)((p)[2])) << 16) + (((unsigned char)((p)[1])) << 8) +(((unsigned char)((p)[0])));
    return n;
}
*/
u900DataReceive::u900DataReceive(){
    socket_port = 7007;
    socket_ip = "192.168.1.100";
    fBytesPerSample = 2;
    fNumSamples = 1200;
    pingSize = 1024 + 256 + 2*(64 + (fNumSamples*fBytesPerSample));
    connectionState = false;
    receivingDataState = false;
}

u900DataReceive::~u900DataReceive(){

}
/*
void u900DataReceive::u900DadtaReceiveInit(){
    socket_port = 7007;
    socket_ip = "192.168.1.100";
    fBytesPerSample = 2;
    fNumSamples = 1200;
    //pingSize = 1024 + 256 + 2*(64 + (fNumSamples*fBytesPerSample));
}
*/
bool u900DataReceive::connetSideScan(){
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(-1 == socket_fd){
        cout <<"socket create failed!!!"<<endl;
        //exit(-1);
        return 0;
    }
    cout<<"socket created, waiting for connection..."<<endl;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(socket_port);
    addr.sin_addr.s_addr = inet_addr(socket_ip.c_str());

    connect_state = connect(socket_fd, (struct sockaddr*)&addr, sizeof(addr));
    if(-1 == connect_state){
        cout<<"connect "<<socket_ip<<" failed..."<<endl;
        //exit(-1);
        return 0;
    }
    cout<<"connect"<<socket_ip<<" succeed..."<<endl;
    connectionState = true;
    receivingDataState = true;
    return 1;
}

bool u900DataReceive::disconnectSideScan(){
    close(connect_state);
    close(socket_fd);
    std::cout<<"connection closed..."<<std::endl;
    connectionState = false;
    return 1;
}

bool u900DataReceive::receiveData(){
    //connect the side scan
    //connetSideScan();
    
    //trans the data
    //u900PingTrans transToXtfStruct;
    //transToXtfStruct.u900PingTransInit();

    pingSize = 1024 + 256 + 2*(64 + (fNumSamples * fBytesPerSample));
    char buffer[pingSize];

    //receive the data
    int size = 0;
    int transStatue = 0;
    while(stopButtonState){
        size = recv(socket_fd, buffer, sizeof(buffer), MSG_WAITALL);
        transStatue = transToXtfStruct.u900PingToXtfStruct(buffer);
        if(0 != transStatue){
            break;
        }
        if(0 == size){
            break;
        }

        //fill the pingPacket with current ping data
        pingPacket.pingHeader = transToXtfStruct.xtfStructData.pingheader;
        pingPacket.pingChanHeader[0] = transToXtfStruct.xtfStructData.pingchanportheader;
        pingPacket.pingChanHeader[1] = transToXtfStruct.xtfStructData.pingchanstbdheader;
        //channel 0 data for pingPacket p_data
        if(transToXtfStruct.xtfStructData.fileheader.chaninfo[0].BytesPerSample == 1){
            int channelNumSamples0 = transToXtfStruct.xtfStructData.pingchanportheader.NumSamples;
            pingPacket.p_ping[0] = malloc(channelNumSamples0);
            memset(pingPacket.p_ping[0], 0, channelNumSamples0);
            unsigned char a[channelNumSamples0];
            for(int i = 0; i < channelNumSamples0; i++ ){
                a[i] = (unsigned char)(transToXtfStruct.xtfStructData.ssrawport[i]);
            }
            memcpy(pingPacket.p_ping[0], a, channelNumSamples0 * sizeof(char));
            /*
            for(int t = 0; t < 10; t++){
                std::cout<<int(*(unsigned char *)(pingPacket.p_ping[0]))<<std::endl;
                pingPacket.p_ping[0] += 1;
            }
            */
        }

        else if(transToXtfStruct.xtfStructData.fileheader.chaninfo[0].BytesPerSample == 2){
            int channelNumSamples0 = transToXtfStruct.xtfStructData.pingchanportheader.NumSamples;
            pingPacket.p_ping[0] = malloc( 2 * channelNumSamples0);
            memset(pingPacket.p_ping[0], 0, 2 * channelNumSamples0);
            memcpy(pingPacket.p_ping[0], transToXtfStruct.xtfStructData.ssrawport, channelNumSamples0 * sizeof(unsigned short));
            /*
            for(int t = 0; t<10; t++){
                std::cout<<int(*(unsigned short *)(pingPacket.p_ping[0]))<<std::endl;
                pingPacket.p_ping[0] += 2;
            }
            */
        }

        else{
            std::cout<<"channel 0 bytesPerSample is "<<transToXtfStruct.xtfStructData.fileheader.chaninfo[0].BytesPerSample<<" ! Error"<<std::endl;
            return 0;
        }

        //channel 1 data for ping Packet p_data
        if(transToXtfStruct.xtfStructData.fileheader.chaninfo[1].BytesPerSample == 1){
            int channelNumSamples1 = transToXtfStruct.xtfStructData.pingchanstbdheader.NumSamples;
            pingPacket.p_ping[1] = malloc(channelNumSamples1);
            memset(pingPacket.p_ping[1], 0, channelNumSamples1);
            unsigned char b[channelNumSamples1];
            for(int i = 0; i < channelNumSamples1; i++ ){
                b[i] = (unsigned char)(transToXtfStruct.xtfStructData.ssrawstbd[i]);
            }
            memcpy(pingPacket.p_ping[1], b, channelNumSamples1 * sizeof(char));
            /*
            for(int t = 0; t < 10; t++){
                std::cout<<(int)(*(unsigned char *)(pingPacket.p_ping[1]))<<std::endl;
                pingPacket.p_ping[1] += 1;
            }
            */            
        }

        else if(transToXtfStruct.xtfStructData.fileheader.chaninfo[1].BytesPerSample == 2){
            int channelNumSamples1 = transToXtfStruct.xtfStructData.pingchanportheader.NumSamples;
            pingPacket.p_ping[1] = malloc( 2 * channelNumSamples1);
            memset(pingPacket.p_ping[1], 0, 2 * channelNumSamples1);
            memcpy(pingPacket.p_ping[1], transToXtfStruct.xtfStructData.ssrawstbd, channelNumSamples1 * sizeof(unsigned short));
            /*
            for(int t = 0; t<10; t++){
                std::cout<<int(*(unsigned short *)(pingPacket.p_ping[1]))<<std::endl;
                pingPacket.p_ping[1] += 2;
            }
            */            
        }

        else{
            std::cout<<"channel 1 bytesPerSample is "<<transToXtfStruct.xtfStructData.fileheader.chaninfo[1].BytesPerSample<<" ! Error"<<std::endl;
            return 0;
        }

        frameQueueMutex.lock();
        frameQueue.push(new pingFrame(&pingPacket,transToXtfStruct.xtfStructData.fileheader));
        frameQueueMutex.unlock();

        pingPacket.p_ping[0] = NULL;
        pingPacket.p_ping[1] = NULL;
        delete pingPacket.p_ping[0];
        delete pingPacket.p_ping[1];
    }
    disconnectSideScan();
    return 1;
}

int u900DataReceive::fetchFrame(Frame * &pFrame){
    if(frameQueue.size()>=1){
        frameQueueMutex.lock();
        pFrame=frameQueue.front();
        frameQueue.pop();
        frameQueueMutex.unlock();
        return 1;
    }
    return 0;
}

int u900DataReceive::startReceiveData(){
    u900Threads.push_back(new std::thread(std::bind(&u900DataReceive::receiveData, this)));
    return 1;
}

int u900DataReceive::stopReceiveData(){
    for (std::vector<std::thread*>::iterator it = u900Threads.begin(); it != u900Threads.end() ; ++it)
    {
        (*it)->join();
        delete *it;
    }
    u900Threads.clear();
    while(frameQueue.size()>=1){
        Frame* ptr=frameQueue.front();
        frameQueue.pop();
        delete ptr;
        std::cout<<"clear frameQueue..."<<std::endl;
    }
    std::cout<<"Receiving data stopped..."<<std::endl;
}
/*
int main(){
    //connect the sidscan    
    u900DataReceive client_a;
    client_a.u900DadtaReceiveInit();
    client_a.connetSideScan();
    char buffer[client_a.pingSize];

    //trans the data
    u900PingTrans transToXtfStruct;
    transToXtfStruct.u900PingTransInit();

    int size = 0;
    int transStatue = 0;
    while(1){
        size = recv(client_a.socket_fd, buffer, sizeof(buffer), MSG_WAITALL);
        transStatue = transToXtfStruct.u900PingToXtfStruct(buffer);
        if(0 != transStatue){
            break;
        }
        if(0 == size){
            break;
        }
        std::cout<<transToXtfStruct.xtfStructData.pingheader.SensorYcoordinate<<std::endl;
    }
    //int size = recv(client_a.socket_fd, buffer, sizeof(buffer), MSG_WAITALL);
    //int transStatue = transToXtfStruct.u900PingToXtfStruct(buffer);
    client_a.disconnectSideScan();

    return 0;
}
*/
