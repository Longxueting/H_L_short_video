#include "firstimage.h"

#include <string>

#define MAX_AUDIO_FRAME_SIZE  192000
#define SAMPLE_PRT(fmt...)   \
    do {\
        printf("[%s]-%d: ", __FUNCTION__, __LINE__);\
        printf(fmt);\
       }while(0)

//'1': Use H.264 Bitstream Filter
#define USE_H264BSF 1

FirstImage::FirstImage()
{

}

void FirstImage::save_image(AVFrame *pFrame, int w, int h, char * outputfile)
{
    FILE *fl;
    char szFilename[32];
    int  y;

    // Open file
    sprintf(szFilename, outputfile);
    fl=fopen(szFilename, "wb");

    if(fl==NULL)
        return;

    fprintf(fl, "P6\n%d %d\n255\n", w, h); // 加入pnm文件头
    // Write pixel data
    for(y=0; y<h; y++)
    {
        fwrite(pFrame->data[0]+y*pFrame->linesize[0], 1, w*3, fl);
    }

    // Close file
    fclose(fl);
}

int FirstImage::getFirstImage(std::string filename,char *outputfile)
{
//    char *file_path = "/run/media/root/study/H&L/01.mp4";
    char *file_path;
    file_path=const_cast<char *>(filename.c_str());


    AVFormatContext *pFormatCtx;
    AVCodecContext *pCodecCtx;
    AVCodec *pCodec;
    AVFrame *pFrame, *pFrameRGB;
    AVPacket *packet;
    uint8_t *out_buffer;

    static struct SwsContext *img_convert_ctx;

    int videoStream, i, numBytes;
    int ret, got_picture;

    av_register_all(); //初始化FFMPEG  调用了这个才能正常适用编码器和解码器

    //Allocate an AVFormatContext.
    pFormatCtx = avformat_alloc_context();

    if (avformat_open_input(&pFormatCtx, file_path, NULL, NULL) != 0) {
        SAMPLE_PRT("open file error\n");
        return -1;
    }

    if (avformat_find_stream_info(pFormatCtx, NULL) < 0) {
        SAMPLE_PRT("Could't find stream infomation\n");
        return -1;
    }

    videoStream = -1;

    for (i = 0; i < pFormatCtx->nb_streams; i++) {
        if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO) {
            videoStream = i;
        }
    }

    if (videoStream == -1) {
        SAMPLE_PRT("no find vedio_stream");
        return -1;
    }

    ///查找解码器
    pCodecCtx = pFormatCtx->streams[videoStream]->codec;
    pCodec = avcodec_find_decoder(pCodecCtx->codec_id);

    if (pCodec == NULL) {
        SAMPLE_PRT(" not found decodec.\n");
        return -1;
    }

    ///打开解码器
    if (avcodec_open2(pCodecCtx, pCodec, NULL) < 0) {
        SAMPLE_PRT("Could not open decodec.");
        return -1;
    }

    pFrame = av_frame_alloc();
    pFrameRGB = av_frame_alloc();

    img_convert_ctx = sws_getContext(pCodecCtx->width, pCodecCtx->height,
            pCodecCtx->pix_fmt, pCodecCtx->width, pCodecCtx->height,
            AV_PIX_FMT_RGB24, SWS_BICUBIC, NULL, NULL, NULL);

    numBytes = avpicture_get_size(AV_PIX_FMT_RGB24, pCodecCtx->width,pCodecCtx->height);

    out_buffer = (uint8_t *) av_malloc(numBytes * sizeof(uint8_t));
    avpicture_fill((AVPicture *) pFrameRGB, out_buffer, AV_PIX_FMT_RGB24,
            pCodecCtx->width, pCodecCtx->height);

    int y_size = pCodecCtx->width * pCodecCtx->height;

    packet = (AVPacket *) malloc(sizeof(AVPacket)); //分配一个packet
    av_new_packet(packet, y_size); //分配packet的数据

    av_dump_format(pFormatCtx, 0, file_path, 0); //输出视频信息

    int index = 0;

    while (av_read_frame(pFormatCtx, packet) >=0){
        if (packet->stream_index == videoStream) {
            ret = avcodec_decode_video2(pCodecCtx, pFrame, &got_picture,packet);

            if (ret < 0) {
                SAMPLE_PRT("decode error.");
                return -1;
            }

            if (got_picture) {
                sws_scale(img_convert_ctx,
                        (uint8_t const * const *) pFrame->data,
                        pFrame->linesize, 0, pCodecCtx->height, pFrameRGB->data,
                        pFrameRGB->linesize);

                save_image(pFrameRGB, pCodecCtx->width,pCodecCtx->height,outputfile); //保存图片
                index++;
                if (index > 0) return 0; //1张
            }
        }
        av_free_packet(packet);
    }
    av_free(out_buffer);
    av_free(pFrameRGB);
    avcodec_close(pCodecCtx);
    avformat_close_input(&pFormatCtx);

    return 0;
}
