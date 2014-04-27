#include "sc2tvstreamsprovider.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>

Sc2tvStreamsProvider::Sc2tvStreamsProvider(QObject *parent) :
    AbstractStreamsProvider(parent)
{
    connect(&d, SIGNAL(error(QString)), this, SLOT(downloadError(QString)));
}

void Sc2tvStreamsProvider::get()
{
    connect(&d, SIGNAL(ready()) ,this, SLOT(streamListDownloaded()));
    d.download("http://sc2tv.ru/streams_list.json");
}

void Sc2tvStreamsProvider::downloadError(const QString &error)
{
    qDebug() << error;
}

void recursiveJsonWrite(QFile &f, QJsonValue value, int tab = 0)
{
    QString tabs;
    QString line;
    for(int i=0;i<tab;++i) tabs += "\t";
    switch(value.type())
    {
        case QJsonValue::Bool:
            line = tabs + "bool: " + (value.toBool()?"true":"false");
            f.write(line.toLocal8Bit());
            break;
        case QJsonValue::Double:
            line = tabs + "double: " + QString::number(value.toDouble());
            f.write(line.toLocal8Bit());
            break;
        case QJsonValue::String:
            line = tabs + "string: " + value.toString();
            f.write(line.toLocal8Bit());
            break;
        case QJsonValue::Array:
            line = tabs + "array:\n";
            f.write(line.toLocal8Bit());
            {
                QJsonArray jArr = value.toArray();
                for(auto iter = jArr.begin(); iter !=jArr.end(); ++iter)
                {
                    recursiveJsonWrite(f, *iter, tab+2);
                }
            }

            break;
        case QJsonValue::Object:
            line = tabs + "object:\n";
            f.write(line.toLocal8Bit());
            {
                QJsonObject jObj = value.toObject();
                for(auto iter = jObj.begin(); iter !=jObj.end(); ++iter)
                {
                    line = tabs + "\t" + iter.key();
                    f.write(line.toLocal8Bit());
                    recursiveJsonWrite(f, iter.value(), tab+2);
                }
            }
            break;
        default:
            line = tabs + "SHIT HAPPENS!";
            f.write(line.toLocal8Bit());
            break;
    }

    f.write("\n");
}

void Sc2tvStreamsProvider::streamListDownloaded()
{
    d.disconnect(SIGNAL(ready()));
    QByteArray page = d.readAll();

    QJsonParseError  parseError;
    QJsonDocument jdoc = QJsonDocument::fromJson(page, &parseError);
    qDebug() << jdoc.isNull() << jdoc.isEmpty() << jdoc.isObject() << jdoc.isArray() << parseError.errorString();
    QJsonObject jObj = jdoc.object();
    QFile f("test.txt");
    f.open(QIODevice::WriteOnly);
    for(auto iter = jObj.begin(); iter !=jObj.end(); ++iter)
    {
        QString line = iter.key();
        f.write(line.toLocal8Bit());
        recursiveJsonWrite(f, iter.value());
    }
    f.close();
}
