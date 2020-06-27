#ifndef VIDEO_H
#define VIDEO_H

#include <QObject>
#include <string>

class Video
{
public:
    Video();
    Video(const QString &imageSource, const QString &videoSource, const QString &auctorImage, const QString &auctor, const QString &describe, int likeNum, int talkNum, bool isLike);
    virtual ~Video();

    void setDescribe(const QString &describe);
    void setAuctor(const QString &auctor);
    void setLikeNum(int likeNum);
    void setTalkNum(int talkNum);
    void setIsLike(bool isLike);

    QString imageSource() const;
    QString videoSource() const;
    QString auctorImage() const;
    QString describe() const;
    QString auctor() const;
    int likeNum() const;
    int talkNum() const;
    bool isLike() const;

    void setImageSource(const QString &imageSource);

    void setVideoSource(const QString &videoSource);

    void setAuctorImage(const QString &auctorImage);

private:
    QString m_imageSource;
    QString m_videoSource;
    QString m_auctorImage;
    QString m_describe;
    QString m_auctor;
    int m_likeNum;
    int m_talkNum;
    bool m_isLike;
};

#endif // VIDEO_H
