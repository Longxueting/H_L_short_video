#include "Video.h"

Video::Video(){
    m_imageSource = "file:///root/01.png";
    m_videoSource = "file:///root/myVideo/receive1.flv";
    m_auctorImage = "file:///root/02.png";
    m_auctor = "";
    m_likeNum = 0;
    m_talkNum = 0;
    m_isLike = false;
}

Video::Video(const QString &imageSource, const QString &videoSource, const QString &auctorImage, const QString &auctor, const QString &describe, int likeNum, int talkNum, bool isLike)
    : m_imageSource(imageSource),
      m_videoSource(videoSource),
      m_auctorImage(auctorImage),
      m_describe(describe),
      m_auctor(auctor),
      m_likeNum(likeNum),
      m_talkNum(talkNum),
      m_isLike(isLike){}

Video::~Video()
{

}

void Video::setDescribe(const QString &describe)
{
    m_describe = describe;
}

void Video::setAuctor(const QString &auctor)
{
    m_auctor = auctor;
}

void Video::setLikeNum(int likeNum)
{
    m_likeNum = likeNum;
}

void Video::setTalkNum(int talkNum)
{
    m_talkNum = talkNum;
}

void Video::setIsLike(bool isLike)
{
    m_isLike = isLike;
}

QString Video::imageSource() const
{
    return m_imageSource;
}

QString Video::videoSource() const
{
    return m_videoSource;
}

QString Video::auctorImage() const
{
    return m_auctorImage;
}

QString Video::describe() const
{
    return m_describe;
}

QString Video::auctor() const
{
    return m_auctor;
}

int Video::likeNum() const
{
    return m_likeNum;
}

int Video::talkNum() const
{
    return m_talkNum;
}

bool Video::isLike() const
{
    return m_isLike;
}

void Video::setImageSource(const QString &imageSource)
{
    m_imageSource = imageSource;
}

void Video::setVideoSource(const QString &videoSource)
{
    m_videoSource = videoSource;
}

void Video::setAuctorImage(const QString &auctorImage)
{
    m_auctorImage = auctorImage;
}




