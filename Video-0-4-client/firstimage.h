#ifndef FIRSTIMAGE_H
#define FIRSTIMAGE_H

#ifdef __cplusplus
extern "C"
{
#endif
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavdevice/avdevice.h>
#include<libswresample/swresample.h>
#include <libavutil/pixfmt.h>
#include <libswscale/swscale.h>
#ifdef __cplusplus
};
#endif

#include <string>


class FirstImage
{
public:
    FirstImage();
    void save_image(AVFrame *pFrame, int w, int h,char * outputfile);
    int getFirstImage(std::string name, char *filepath);
};

#endif // FIRSTIMAGE_H
