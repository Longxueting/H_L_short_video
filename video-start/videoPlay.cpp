#include "videoPlay.h"
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

//PlayNode *VideoPlay::MakeNode(char* outfilename){
//    PlayNode* p=(PlayNode*)malloc(sizeof (PlayNode));
//    p->_data=outfilename;
//    return p;
//}

//void VideoPlay::InitList(PlayList &list){
//    PlayNode *p1=MakeNode(outfilenames[0]);
//    PlayNode *p2=MakeNode(outfilenames[1]);
//    PlayNode *p3=MakeNode(outfilenames[2]);
//    PlayNode *p4=MakeNode(outfilenames[3]);
//    PlayNode *p5=MakeNode(outfilenames[4]);
//    list.head=p1;
//    list.size=5;
//    p1->_next=p2;
//    p1->_pre=p5;
//    p2->_next=p3;
//    p2->_pre=p1;
//    p3->_next=p4;
//    p3->_pre=p2;
//    p4->_next=p5;
//    p4->_pre=p3;
//    p5->_next=p1;
//    p5->_pre=p4;
//}

VideoPlay::~VideoPlay(){}
