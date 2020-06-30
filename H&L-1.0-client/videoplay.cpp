#include "videoplay.h"
#include "videomodel.h"
#include "firstimage.h"

#define INIT_NUM 5

VideoPlay::VideoPlay(){

}

void VideoPlay::VideoInit(){

    QJsonArray init=videojson.getFiveData();
    vector<string> infiles;
    for(int i=0;i<INIT_NUM;i++){
        QString video_src=init.at(i)["v_url"].toString();
        infiles.push_back(video_src.toStdString());
        cout<<infiles[i]<<endl;
//        std::string imageOutFile = "/root/receiver/receive" + to_string(i+1) + ".png";
//        char * outputImage;
//        outputImage = const_cast<char *>(imageOutFile.c_str());
//        FirstImage image;
//        image.getFirstImage(infiles[i], outputImage);
    }

    loadVideo.loadInitVideo(infiles);
}

void VideoPlay::up_slide(int currentIndex,int videoIndex)
{
    //videoIndex--;
    QJsonObject video=videojson.getOneData(videoIndex-3);
    if(videoIndex==0){
        cout<<".....刷新中....."<<endl;
    }
    if(videoIndex>=3){
        switch (currentIndex) {
        cout<<video["v_url"].toString().toStdString()<<endl;
        case 0:
            loadVideo.loadOneVideo(video["v_url"].toString().toStdString(),3);
            //img.getFirstImage("/root/receiver/receive.flv");
            break;
        case 1:
            loadVideo.loadOneVideo(video["v_url"].toString().toStdString(),4);
            break;
        case 2:
            loadVideo.loadOneVideo(video["v_url"].toString().toStdString(),0);
            break;
        case 3:
            loadVideo.loadOneVideo(video["v_url"].toString().toStdString(),1);
            break;
        case 4:
            loadVideo.loadOneVideo(video["v_url"].toString().toStdString(),2);
            break;
        case 5:
            loadVideo.loadOneVideo(video["v_url"].toString().toStdString(),3);
            break;
        case 6:
            loadVideo.loadOneVideo(video["v_url"].toString().toStdString(),4);
            break;
        default:
            break;
        }
    }

}

void VideoPlay::down_slide(int currentIndex,int videoIndex)
{
    //videoIndex++;
    QJsonObject video=videojson.getOneData(videoIndex+1);
    //    DataModel d;
    //    d.set(currentIndex, videoIndex);
    if(videoIndex>3){
        switch (currentIndex) {
        cout<<video["v_url"].toString().toStdString()<<endl;
        case 0:
            loadVideo.loadOneVideo(video["v_url"].toString().toStdString(),2);
            break;
        case 1:
            loadVideo.loadOneVideo(video["v_url"].toString().toStdString(),3);
            break;
        case 2:
            loadVideo.loadOneVideo(video["v_url"].toString().toStdString(),4);
            break;
        case 3:
            loadVideo.loadOneVideo(video["v_url"].toString().toStdString(),0);
            break;
        case 4:
            loadVideo.loadOneVideo(video["v_url"].toString().toStdString(),1);
            break;
        case 5:
            loadVideo.loadOneVideo(video["v_url"].toString().toStdString(),2);
            break;
        case 6:
            loadVideo.loadOneVideo(video["v_url"].toString().toStdString(),3);
            break;
        default:
            break;
        }
    }
}

VideoPlay::~VideoPlay(){}
