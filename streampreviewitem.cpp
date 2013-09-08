#include "streampreviewitem.h"
#include <QDebug>

StreamPreviewItem::StreamPreviewItem(QObject *parent) :
    QObject(parent)
{
}

StreamPreviewItem::StreamPreviewItem(const StreamPreviewItem &right)
{
    name = right.name;
    description = right.description;
    streamer = right.streamer;
    game = right.game;
    section = right.section;
    link = right.link;
    picturelink = right.picturelink;
    id = right.id;
    rating = right.rating;
}

StreamPreviewItem &StreamPreviewItem::StreamPreviewItem::operator =(const StreamPreviewItem &right)
{
    name = right.name;
    description = right.description;
    streamer = right.streamer;
    game = right.game;
    section = right.section;
    link = right.link;
    picturelink = right.picturelink;
    id = right.id;
    rating = right.rating;
    return *this;
}

void StreamPreviewItem::setName(const QString &val)
{
    name = val;
}

QString StreamPreviewItem::getName() const
{
    return name;
}

void StreamPreviewItem::setDescription(const QString &val)
{
    description = val;
}

QString StreamPreviewItem::getDescription() const
{
    return description;
}

void StreamPreviewItem::setStreamerName(const QString &val)
{
    streamer = val;
}

QString StreamPreviewItem::getStreamerName() const
{
    return streamer;
}

void StreamPreviewItem::setGameName(const QString &val)
{
    game = val;
}

QString StreamPreviewItem::getGameName() const
{
    return game;
}

void StreamPreviewItem::setSection(const QString &val)
{
    section = val;
}

QString StreamPreviewItem::getSection() const
{
    return section;
}

void StreamPreviewItem::setLink(const QString &val)
{
    link = val;
}

QString StreamPreviewItem::getLink() const
{
    return link;
}

void StreamPreviewItem::setPictureLink(const QString &val)
{
    picturelink = val;
}

QString StreamPreviewItem::getPictureLink() const
{
    return picturelink;
}

void StreamPreviewItem::setRating(const int val)
{
    rating = val;
}

int StreamPreviewItem::getRating() const
{
    return rating;
}

int StreamPreviewItem::getId() const
{
    return id;
}

void StreamPreviewItem::setType(StreamPreviewItem::StreamType type)
{
    streamType = type;
}

StreamPreviewItem::StreamType StreamPreviewItem::getType() const
{
    return streamType;
}

void StreamPreviewItem::setId(const int val)
{
    id = val;
}


