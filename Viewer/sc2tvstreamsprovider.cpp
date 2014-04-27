#include "sc2tvstreamsprovider.h"
#include <QJsonDocument>
#include <QDebug>

Sc2tvStreamsProvider::Sc2tvStreamsProvider(QObject *parent) :
    AbstractStreamsProvider(parent)
{
    connect(&d, SIGNAL(error(QString)), this, SLOT(downloadError(QString)));
}

void Sc2tvStreamsProvider::get()
{
    connect(&d, SIGNAL(ready()) ,this, SLOT(streamListDownloaded()));
    d.download("http://sc2tv.ru/stream_list.json");
}

void Sc2tvStreamsProvider::downloadError(const QString &error)
{
    qDebug() << error;
}

void Sc2tvStreamsProvider::streamListDownloaded()
{
    d.disconnect(SIGNAL(ready()));
}
