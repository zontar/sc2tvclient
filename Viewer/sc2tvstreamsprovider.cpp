#include "sc2tvstreamsprovider.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>

Sc2tvStreamsProvider::Sc2tvStreamsProvider(QObject *parent) :
    AbstractStreamsProvider(parent)
{
    connect(&d_, SIGNAL(error(QString)), this, SLOT(downloadError(QString)));
}

Sc2tvStreamsProvider::~Sc2tvStreamsProvider()
{

}

void Sc2tvStreamsProvider::get()
{
    connect(&d_, SIGNAL(ready()) ,this, SLOT(streamListDownloaded()));
    d_.download("http://sc2tv.ru/streams_list.json");
}

void Sc2tvStreamsProvider::downloadError(const QString &error)
{
    qDebug() << error;
}

void Sc2tvStreamsProvider::streamListDownloaded()
{
    d_.disconnect(SIGNAL(ready()));
    QByteArray page = d_.readAll();

    QJsonParseError  parseError;
    QJsonDocument jdoc = QJsonDocument::fromJson(page, &parseError);
    qDebug() << jdoc.isNull() << jdoc.isEmpty() << jdoc.isObject() << jdoc.isArray() << parseError.errorString();
    QJsonObject jObj = jdoc.object();
    if(jObj.isEmpty())
    {
        qDebug() << "Couldn't get streams list";
        emit error("Couldn't get streams list");
        return;
    }
    QJsonArray jArr = jObj.find("streams").value().toArray();
    if(jArr.isEmpty())
    {
        qDebug() << "Couldn't get streams array";
        emit error("Couldn't get streams array");
        return;
    }

    for(auto iter = jArr.begin(); iter != jArr.end(); ++iter)
    {
        QJsonValue value = *iter;
        if(!value.isObject())
        {
            qDebug() << "Unexpercted non object item while parse streams array";
            continue;
        }
        Sc2tvStreamItem item(value.toObject().toVariantMap());
        emit found(item);
    }

}
