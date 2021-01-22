#ifndef U900PINGTRANS_H_
#define U900PINGTRANS_H_
#include<iostream>
#include <XTFReader/xtf.h>
extern "C"{
#include <XTFReader/get_value.h>
}
//#define swapInt(a) (((a) << 24) | (((a) << 8) & 0x00ff0000) | (((a) >> 8) & 0x0000ff00) | ((unsigned int)(a) >> 24))
using namespace std;
class u900PingTrans{
public:
    u900PingTrans();
    ~u900PingTrans();

    struct xtffile_struct xtfStructData;
    int channelNum;
    void u900PingTransInit();
    int u900PingToXtfStruct(char *xtfStream);
};

#endif
