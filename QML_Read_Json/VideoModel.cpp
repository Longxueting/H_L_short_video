#include "VideoModel.h"

#include <iostream>


DataModel::DataModel(QObject *parent)
    : QAbstractListModel(parent)
{
    ReadJson readJson;
    this->m_readJson= readJson.getFiveData();
    init();
}

void DataModel::init()
{
    Video video;
    video.setAuctor(m_readJson.at(4)["v_author"].toString());
    video.setDescribe(m_readJson.at(4)["v_describe"].toString());
    video.setImageSource("file:///root/05.png");
    video.setVideoSource("file:///root/myVideo/receive5.flv");
    video.setLikeNum(m_readJson.at(4)["v_like_num"].toInt());
    video.setIsLike(false);
    dataList_.append(video);
    for (int i=0; i<5; i++){
        video.setAuctor(m_readJson.at(i)["v_author"].toString());
        video.setDescribe(m_readJson.at(i)["v_describe"].toString());
        std::string imageFile = "file:///root/0" + std::to_string(i+1) + ".png";
        std::string videoFile = "file:///root/myVideo/receive" + std::to_string(i+1) + ".flv";
        QString s2 = QString::fromStdString(imageFile);
        video.setImageSource(s2);
        video.setLikeNum(m_readJson.at(i)["v_like_num"].toInt());
        s2 = QString::fromStdString(videoFile);
        video.setVideoSource(s2);
        video.setIsLike(false);
        dataList_.append(video);
    }
    video.setAuctor(m_readJson.at(0)["v_author"].toString());
    video.setDescribe(m_readJson.at(0)["v_describe"].toString());
    video.setImageSource("file:///root/01.png");
    video.setVideoSource("file:///root/myVideo/receive1.flv");
    video.setLikeNum(m_readJson.at(0)["v_like_num"].toInt());
    video.setIsLike(false);
    dataList_.append(video);
}

DataModel::~DataModel()
{
}

int DataModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return dataList_.count();
}

QVariant DataModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if(row < 0 || row >= dataList_.count()) {
        return QVariant();
    }

    const Video &data = dataList_[row];
    switch (role) {
    case ImageSourceRole:
        return data.imageSource();
        break;
    case VideoSourceRole:
        return data.videoSource();
        break;
    case AuctorImageRole:
        return data.auctorImage();
        break;
    case AuctorNameRole:
        return data.auctor();
        break;
    case DesctibeRole:
        return data.describe();
        break;
    case LikeNumRole:
        return data.likeNum();
        break;
    case TalkNumRole:
        return data.talkNum();
        break;
    case IsLikeRole:
        return data.isLike();
        break;
    }

    return QVariant();
}


//dm : data model
QHash<int, QByteArray> DataModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ImageSourceRole] = "hlVideoImage";
    roles[VideoSourceRole] = "hlVideoSource";
    roles[AuctorImageRole] = "hlAuctorImage";
    roles[AuctorNameRole] = "hlAuctorName";
    roles[DesctibeRole] = "hlDescribe";
    roles[LikeNumRole] = "hlLikeNum";
    roles[TalkNumRole] = "hlTalkNum";
    roles[IsLikeRole] = "hlIsLike";
    return roles;
    //    emit countChanged(m_data.count());
}

void DataModel::insert(int index, const Video &data)
{
    if(index < 0 || index > dataList_.count()) {
        return;
    }

    emit beginInsertRows(QModelIndex(), index, index);
    dataList_.insert(index, data);
    emit endInsertRows();
//    emit countChanged(m_data.count());
}

void DataModel::remove(int index)
{
    if(index < 0 || index >= dataList_.count()) {
        return;
    }

    beginRemoveRows(QModelIndex(), index, index);
    dataList_.removeAt(index);
    endRemoveRows();
}


void DataModel::append(const QString &imageSource, const QString &videoSource, const QString &auctorImage, const QString &auctor, const QString &describe, int likeNum, int talkNum, bool isLike)
{
    insert(count(), Video(imageSource,videoSource,auctorImage, auctor,describe, likeNum, talkNum, isLike));
}


int DataModel::count() const
{
    return rowCount(QModelIndex());
}
void DataModel::set(int index)
{
    if(index < 0 || index >= dataList_.count()) {
        return;
    }

    dataList_[index].setAuctor(m_readJson.at(index)["v_author"].toString());
    dataList_[index].setDescribe(m_readJson.at(index)["v_describe"].toString());
    dataList_[index].setIsLike(false);

    ReadJson readJson;
    QJsonObject jsonobj=readJson.getOneData(index);
    setLikeNum(index ,jsonobj["v_like_num"].toInt());
//    setTalkNum(jsonobj[""]);
    emit dataChanged(createIndex(index, 0), createIndex(index, 0));
}

void DataModel::setLikeNum(int index, int likeNum)
{
    int i = dataList_[index].likeNum() + likeNum;
    dataList_[index].setLikeNum(i);
    if(likeNum > 0){
        dataList_[index].setIsLike(true);
    }else {
        dataList_[index].setIsLike(false);
    }
    emit dataChanged(createIndex(index, 0), createIndex(index, 0));
}

int DataModel::setTalkNum(int talkNum)
{

}


