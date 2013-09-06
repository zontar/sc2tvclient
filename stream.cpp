#include "stream.h"
#include <QRegExp>
#include <QDebug>

Stream::Stream(QObject *parent) :
    QObject(parent)
{
    connect(&net,SIGNAL(finished(QNetworkReply*)),this,SLOT(loadFinished(QNetworkReply*)));
}


void Stream::prepare(const QString &link)
{
    QString address = "http://sc2tv.ru" + link;
    net.get(QNetworkRequest(QUrl(address)));
}

void Stream::loadFinished(QNetworkReply *reply)
{
    if(!reply) return;
    QString page = reply->readAll();

    QRegExp r;
    r.setPatternSyntax(QRegExp::RegExp2);
    r.setMinimal(true);
    if(page.size()>10000)
    {
        r.setPattern("block-sc2tv_player-0.*stream_player_body.*(data|src)=\"(.*)\"");
        if(r.indexIn(page)==-1) return;
        if(r.cap(2).indexOf("cybergame")!=-1) net.get(QNetworkRequest(QUrl(r.cap(2))));
        else emit streamReady(r.cap(2));
    }
    else
    {
        r.setPattern("src=\"(.*)\"");
        if(r.indexIn(page)==-1) return;
        emit streamReady(r.cap(1)+"&autostart=1");
    }
}
