#ifndef VIDEOMODEL_H
#define VIDEOMODEL_H

#include "video.h"
#include "readjson.h"
#include <QAbstractListModel>

class VideoModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit VideoModel(QObject *parent = nullptr);
    enum DataRoles{
        ImageSourceRole = Qt::UserRole + 1,
        VideoSourceRole,
        AuctorImageRole,
        DesctibeRole,
        AuctorNameRole,
        LikeNumRole,
        TalkNumRole,
        IsLikeRole
    };
    Q_INVOKABLE void init();
    ~VideoModel();

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Add data:
    Q_INVOKABLE void insert(int index,const Video &data) ;

    // Remove data:
    Q_INVOKABLE void remove(int index);
    Q_INVOKABLE void append(const QString &imageSource, const QString &videoSource, const QString &auctorImage, const QString &auctor, const QString &describe, int likeNum, int talkNum, bool isLike);
    int count() const;

    Q_INVOKABLE void set(int index, int videoIndex);
    void initLikeNum(int index, int likeNum);
    Q_INVOKABLE void setLikeNum(int index,int videoIndex, int likeNum);
    int setTalkNum(int talkNum);

    Q_INVOKABLE void user_like(int video_id);
    Q_INVOKABLE void user_notlike(int video_id);
protected: // interface QAbstractListModel
    virtual QHash<int, QByteArray> roleNames() const;

private:
    QList<Video> dataList_;
    QJsonArray m_readJson;
    ReadJson m_readjson;
    std::vector<int> userlike={};
};

#endif // VIDEOMODEL_H
