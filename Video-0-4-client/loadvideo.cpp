#include "reciver.h"
#include "loadvideo.h"
#include "firstimage.h"

#include <thread>
#include <algorithm>
#include <functional>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

LoadVideo::LoadVideo(){
    if(access(path.c_str(),0)==-1){
        int flag=mkdir(path.c_str(),0777);
        if(flag==0){
            cout<<"创建成功！"<<endl;
        }else {
            cout<<"创建失败！"<<endl;
        }
    }
}

//LoadVideo::LoadVideo(std::vector<string> files)
//{
//    m_infiles = files;
//}

void LoadVideo::loadInitVideo(std::vector<string> infiles){
    LoadVideo load;
    std::vector<std::thread> threads;
    //Reciver loadVideos;
    for(int i = 0; i < 5; ++i){
        std::string imageOutFile = "/root/receiver/img" + to_string(i+1) + ".pnm";
        char * outputImage;
        outputImage = const_cast<char *>(imageOutFile.c_str());
        FirstImage image;
        image.getFirstImage(infiles[i], outputImage);
        threads.push_back(std::thread(&LoadVideo::loadvideo,&load, infiles[i], i));
    }
    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::detach));
}

void LoadVideo::loadOneVideo(std::string filename, int index){
    std::string imageOutFile = "/root/receiver/img" + to_string(index+1) + ".pnm";
    char * outputImage;
    outputImage = const_cast<char *>(imageOutFile.c_str());
    FirstImage image;
    image.getFirstImage(filename, outputImage);
    LoadVideo load;
    std::thread t(&LoadVideo::loadvideo,&load, filename, index);
    t.detach();
}

void LoadVideo::loadvideo(string filename, int index)
{
    std::string outfile ="/root/receiver/receive" + to_string(index+1) + ".flv";
    char * outputFile;
    outputFile = const_cast<char *>(outfile.c_str());
    Reciver loadVideo;
    loadVideo.getVideo(filename,outputFile);
}
