#include "streamripper.h"

#include <QNetworkRequest>
#include <QRegExp>
#include <QDebug>


StreamRipper::StreamRipper()
{
    connect(&net,SIGNAL(finished(QNetworkReply*)),this,SLOT(loadFinished(QNetworkReply*)));
    connect(&store,SIGNAL(imageReady(int,QString)),this,SLOT(imageLoaded(int,QString)));
}

StreamRipper::~StreamRipper()
{
}

void StreamRipper::load()
{
    net.get(QNetworkRequest(QUrl("http://sc2tv.ru/")));
}

QList<StreamPreviewItem> StreamRipper::getItems() const
{
    return items;
}

ImageStore *StreamRipper::getImageStore()
{
    return &store;
}

void StreamRipper::loadFinished(QNetworkReply *reply)
{
    if(!reply)  return;

    QString siteData = reply->readAll();
    QRegExp reg;
    reg.setPatternSyntax(QRegExp::RegExp2);
    reg.setMinimal(true);
    int pos,nextpos;
    reg.setPattern("user-stream-list");
    pos = reg.indexIn(siteData);
    nextpos = reg.indexIn(siteData,pos+1);
    if(pos==-1) return;

    StreamPreviewItem item;
    while(pos!=-1)
    {
        reg.setPattern("img\\salt=\"(.*)\"\\ssrc=\"(.*)\"");
        pos = reg.indexIn(siteData,pos+1);
        if(pos>nextpos&&nextpos!=-1)pos=-1;
        if(pos==-1) continue;
        item.setName(reg.cap(1));
        item.setPictureLink(reg.cap(2));

        reg.setPattern("class=\"user\">(.*)</a>");
        pos = reg.indexIn(siteData,pos+1);
        item.setStreamerName(reg.cap(1));

        reg.setPattern("<p>Рейтинг\\s:\\s(-?\\d*)</p>");
        pos = reg.indexIn(siteData,pos+1);
        item.setRating(reg.cap(1).toInt());

        reg.setPattern("<p>(.*)</p>");
        pos = reg.indexIn(siteData,pos+1);
        item.setDescription(reg.cap(1));

        reg.setPattern("<span>(.*)</span>");
        pos = reg.indexIn(siteData,pos+1);
        item.setSection(reg.cap(1));

        reg.setPattern("<a href=\"(.*)\"");
        pos = reg.indexIn(siteData,pos+1);
        item.setLink(reg.cap(1));

        item.setId(items.size());
        items << item;
        store.addImage(item.getId(),item.getPictureLink());
    }
}

void StreamRipper::imageLoaded(int id, const QString &path)
{
    items[id].setPictureLink(path);
    emit funStreamFound(items.at(id));
}
