#ifndef LOAD_VIDEO_H
#define LOAD_VIDEO_H

#include <string>
#include <vector>
class LoadVideo
{
public:
    LoadVideo();
//    LoadVideo(std::vector<std::string> files);
    void loadInitVideo(std::vector<std::string> infiles);
    void loadOneVideo(std::string filename, int index);
    void loadvideo(std::string filename, int index);

private:

    //std::vector<std::string> m_infiles;
    std::string path="/root/receiver/";
};

#endif // LOAD_VIDEO_H
