#ifndef VIDEOPLAY_H
#define VIDEOPLAY_H

#endif // VIDEOPLAY_H

#include <iostream>
#include <string>
#include <vector>
#include <QObject>
#include "readAllJson.h"
#include "Load_video.h"
using namespace std;
typedef char* DataType;
struct PlayNode{
    struct PlayNode* _next;
    struct PlayNode* _pre;
    DataType _data;

//    PlayNode(const DataType &data=DataType())
//        :_next(NULL),_p re(NULL),_data(data){}
};

struct PlayList{
    PlayList(){size=0;}
    size_t size;
    PlayNode *head;
};

class VideoPlay:public QObject{

    Q_OBJECT
private:
    PlayList list;
    ReadJson videojson;
    LoadVideo loadVideo;
    string path="/root/receiver/";
    vector<char*>outfilenames={"receive1.flv","receive2.flv","recive3.flv","recive4.flv","recive5.flv"};
public:
    PlayNode *MakeNode(char*);
    void InitList(PlayList &L);
    explicit VideoPlay();
    Q_INVOKABLE void VideoInit();
    Q_INVOKABLE void up_slide(int currentIndex,int videoIndex);
    Q_INVOKABLE void down_slide(int currentIndex,int videoIndex);
    ~VideoPlay();
};
