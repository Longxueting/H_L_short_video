#ifndef VIDEOPLAY_H
#define VIDEOPLAY_H

#endif // VIDEOPLAY_H

#include <iostream>
#include <string>
#include <vector>
#include <QObject>
#include "readjson.h"
#include "Load_video.h"
using namespace std;

class VideoPlay:public QObject{

    Q_OBJECT
private:
    ReadJson videojson;
    LoadVideo loadVideo;
    string path="/root/receiver/";
    vector<char*>outfilenames={"receive1.flv","receive2.flv","recive3.flv","recive4.flv","recive5.flv"};
public:
    explicit VideoPlay();
    Q_INVOKABLE void VideoInit();
    Q_INVOKABLE void up_slide(int currentIndex,int videoIndex);
    Q_INVOKABLE void down_slide(int currentIndex,int videoIndex);
    ~VideoPlay();
};
