#include "imagestore.h"
#include <QFile>
#include <QDir>

ImageStore::ImageStore(QObject *parent) :
    QObject(parent)
{
    connect(&net,SIGNAL(finished(QNetworkReply*)),this,SLOT(loadFinished(QNetworkReply*)));
}

void ImageStore::addImage(int id, const QString &address)
{
    QNetworkRequest request;
    request.setUrl(QUrl(address));
    request.setAttribute((QNetworkRequest::Attribute)(QNetworkRequest::User),QVariant::fromValue<int>(id));
    QNetworkReply *r =  net.get(request);
    r->setProperty("id",id);
}

void ImageStore::loadFinished(QNetworkReply *reply)
{
    if(!reply) return;
    int id = reply->property("id").toInt();
    QDir dir(QDir::currentPath());
    dir.mkpath("preview");
    QByteArray data = reply->readAll();
    QString filename;
    if(reply->error() == QNetworkReply::NoError)
    {
        filename = dir.absolutePath() + "/preview/" + QString::number(id) + ".jpg";
        QFile file(filename);
        file.open(QIODevice::WriteOnly);
        file.write(data);
        file.flush();
        file.close();
        filename = "file:///"+filename;
    }
    else
    {
        filename = "qrc:///image//thumb-error.jpg";
    }
    emit imageReady(id,filename);
}
