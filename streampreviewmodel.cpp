#include "streampreviewmodel.h"
#include <QDebug>

StreamPreviewModel::StreamPreviewModel(QObject *parent) :
    QAbstractListModel(parent),itemCount(0)
{
    roles[NameRole] = "name";
    roles[DescriptionRole] = "description";
    roles[StreamerRole] = "streamer";
    roles[GameRole] = "game";
    roles[SectionRole] = "section";
    roles[LinkRole] = "link";
    roles[PictureLinkRole] = "picturelink";
    roles[IdRole] = "id";
    roles[RatingRole] = "rating";

    connect(&stream,SIGNAL(streamReady(QString)),this,SLOT(streamReady(QString)));
}

void StreamPreviewModel::setItemCount(const int &val)
{
    if(itemCount==val) return;
    itemCount = val;
    emit itemCountChanged();
}

int StreamPreviewModel::getItemCount() const
{
    return itemCount;
}

QVariant StreamPreviewModel::data(const QModelIndex &index, int role) const
{
    if (index.row()<0 || index.row()>=items.count()) return QVariant();

    const StreamPreviewItem & item = items[index.row()];
    switch(role)
    {
        case NameRole: return item.getName();
        case DescriptionRole: return item.getDescription();
        case StreamerRole: return item.getStreamerName();
        case GameRole: return item.getGameName();
        case SectionRole: return item.getSection();
        case LinkRole: return item.getLink();
        case PictureLinkRole: return item.getPictureLink();
        case IdRole: return item.getId();
        case RatingRole: return item.getRating();
    }
    return QVariant();
}

bool StreamPreviewModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.row()>=items.count()) return false;
    StreamPreviewItem & item = items[index.row()];
    switch(role)
    {
        case NameRole: item.setName(value.toString());
        case DescriptionRole: item.setDescription(value.toString());
        case StreamerRole: item.setStreamerName(value.toString());
        case GameRole: item.setGameName(value.toString());
        case SectionRole: item.setSection(value.toString());
        case LinkRole: item.setLink(value.toString());
        case PictureLinkRole: item.setPictureLink(value.toString());
        case IdRole: item.setId(value.toInt());
        case RatingRole: item.setRating(value.toInt());
    }
    return true;
}

int StreamPreviewModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return items.size();
}

void StreamPreviewModel::addItem(const StreamPreviewItem item)
{
    beginInsertRows(QModelIndex(),items.size(),items.size());
    items.push_back(item);
    endInsertRows();

}

void StreamPreviewModel::addItems(QList<StreamPreviewItem> values)
{
    items.append(values);
}

void StreamPreviewModel::loadStream(int id)
{
    stream.prepare(items.at(id).getLink());
}

void StreamPreviewModel::streamReady(const QString &link)
{
    emit showStream(link);
}

QHash<int, QByteArray> StreamPreviewModel::roleNames() const
{
    return roles;
}
