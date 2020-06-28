#ifndef RECIVER_H
#define RECIVER_H
#ifdef __cplusplus
extern "C"
{
#endif
#include <libavformat/avformat.h>
#include <libavutil/mathematics.h>
#include <libavutil/time.h>
#ifdef __cplusplus
};
#endif
#include <string>
#include <iostream>
using namespace std;
class Reciver{
private:
    AVOutputFormat *ofmt = nullptr;
    AVFormatContext *ifmt_ctx = nullptr, *ofmt_ctx = nullptr;
    AVPacket pkt;
    string file="";
    int ret, i;
    int videoindex=-1;
    int frame_index=0;
public:
    Reciver();
    void getVideo(string filename,char* &out_filename);
    void ReciverVideo(char* &out_filename);
    ~Reciver();
};

#endif // RECIVER_H
