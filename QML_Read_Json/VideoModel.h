#ifndef VIDEOLIST_H
#define VIDEOLIST_H

#include "Video.h"
#include "readjson.h"
#include <QAbstractListModel>

class DataModel : public QAbstractListModel
{
    Q_OBJECT

public:
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

    explicit DataModel(QObject *parent = nullptr);
    void init();
    ~DataModel();

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Add data:
    Q_INVOKABLE void insert(int index,const Video &data) ;

    // Remove data:
    Q_INVOKABLE void remove(int index);
    Q_INVOKABLE void append(const QString &imageSource, const QString &videoSource, const QString &auctorImage, const QString &auctor, const QString &describe, int likeNum, int talkNum, bool isLike);
    int count() const;

    void set(int index);
    Q_INVOKABLE void setLikeNum(int index, int likeNum);
    int setTalkNum(int talkNum);

protected: // interface QAbstractListModel
    virtual QHash<int, QByteArray> roleNames() const;

private:
    QList<Video> dataList_;
    QJsonArray m_readJson;
};

#endif // VIDEOLIST_H
