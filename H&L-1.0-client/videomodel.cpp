#include "videomodel.h"

#include <iostream>


VideoModel::VideoModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

void VideoModel::init()
{
    m_readJson= m_readjson.getFiveData();

    Video video;
    for (int i=0; i<5; i++){
        video.setAuctor(m_readJson.at(i)["v_author"].toString());
        video.setDescribe(m_readJson.at(i)["v_describe"].toString());
        std::string imageFile = "file:///root/receiver/img" + std::to_string(i+1) + ".pnm";
        std::string videoFile = "file:///root/receiver/receive" + std::to_string(i+1) + ".flv";
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
    video.setImageSource("file:///root/receiver/img1.pnm");
    video.setVideoSource("file:///root/receiver/receive1.flv");
    video.setLikeNum(m_readJson.at(0)["v_like_num"].toInt());
    video.setIsLike(false);
    dataList_.append(video);

    video.setAuctor(m_readJson.at(1)["v_author"].toString());
    video.setDescribe(m_readJson.at(1)["v_describe"].toString());
    video.setImageSource("file:///root/receiver/img2.pnm");
    video.setVideoSource("file:///root/receiver/receive2.flv");
    video.setLikeNum(m_readJson.at(1)["v_like_num"].toInt());
    video.setIsLike(false);
    dataList_.append(video);
}

VideoModel::~VideoModel()
{
}

int VideoModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return dataList_.count();
}

QVariant VideoModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if(row < 0 || row >= dataList_.count()) {
        return QVariant();
    }

    const Video &data = dataList_[row];
    switch (role) {
    case ImageSourceRole:
        return data.imageSource();
    case VideoSourceRole:
        return data.videoSource();
    case AuctorImageRole:
        return data.auctorImage();
    case AuctorNameRole:
        return data.auctor();
    case DesctibeRole:
        return data.describe();
    case LikeNumRole:
        return data.likeNum();
    case TalkNumRole:
        return data.talkNum();
    case IsLikeRole:
        return data.isLike();
    }

    return QVariant();
}


//dm : data model
QHash<int, QByteArray> VideoModel::roleNames() const
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

void VideoModel::insert(int index, const Video &data)
{
    if(index < 0 || index > dataList_.count()) {
        return;
    }

    emit beginInsertRows(QModelIndex(), index, index);
    dataList_.insert(index, data);
    emit endInsertRows();
//    emit countChanged(m_data.count());
}

void VideoModel::remove(int index)
{
    if(index < 0 || index >= dataList_.count()) {
        return;
    }

    beginRemoveRows(QModelIndex(), index, index);
    dataList_.removeAt(index);
    endRemoveRows();
}


void VideoModel::append(const QString &imageSource, const QString &videoSource, const QString &auctorImage, const QString &auctor, const QString &describe, int likeNum, int talkNum, bool isLike)
{
    insert(count(), Video(imageSource,videoSource,auctorImage, auctor,describe, likeNum, talkNum, isLike));
}


int VideoModel::count() const
{
    return rowCount(QModelIndex());
}
void VideoModel::set(int index, int videoIndex)//根据true 和false修改显示状态
{
    if(index < 0 || index >= dataList_.count()) {
        return;
    }
    QJsonObject object = m_readjson.getOneData(videoIndex-1);
    dataList_[index].setAuctor(object["v_author"].toString());
    dataList_[index].setDescribe(object["v_describe"].toString());
    if(object["isLike"] == true){
        dataList_[index].setIsLike(true);
    }else{
        dataList_[index
                ].setIsLike(false);
    }
    if(index == 0 || index == 5){
        dataList_[0].setLikeNum(object["v_like_num"].toInt());
        dataList_[5].setLikeNum(object["v_like_num"].toInt());
    }else if(index == 1 || index == 6){
        dataList_[1].setLikeNum(object["v_like_num"].toInt());
        dataList_[6].setLikeNum(object["v_like_num"].toInt());
    }
    dataList_[index].setLikeNum(object["v_like_num"].toInt());
    emit dataChanged(createIndex(index, 0), createIndex(index, 0));
}

void VideoModel::initLikeNum(int index, int likeNum)
{
    dataList_[index].setLikeNum(likeNum);
    emit dataChanged(createIndex(index, 0), createIndex(index, 0));
}

void VideoModel::setLikeNum(int index, int videoIndex,int likeNum)
{
    int i = dataList_[index].likeNum() + likeNum;
    dataList_[index].setLikeNum(i);
    std::cout <<"i : " <<i <<std::endl;
    if(likeNum > 0){
        dataList_[index].setIsLike(true);
        m_readjson.changeLikeNum(videoIndex-1, i, true);
    }else {
        dataList_[index].setIsLike(false);
        m_readjson.changeLikeNum(videoIndex-1, i, false);
    }

    std::cout <<"videoIndex : " <<videoIndex-1 <<std::endl;

    std::cout << m_readjson.getOneData(videoIndex-1)["v_like_num"].toInt() << std::endl;

    emit dataChanged(createIndex(index, 0), createIndex(index, 0));
}

int VideoModel::setTalkNum(int talkNum)
{

}

void VideoModel::user_like(int video_id)
{
    userlike.push_back(video_id);
}

void VideoModel::user_notlike(int video_id)
{
    std::vector<int>::iterator it;
    for(it=userlike.begin();it!=userlike.end();++it){
        if(*it==video_id)
            it=userlike.erase(it);
        else {
            ++it;
        }
    }
}


