#include "downloader.h"
#include <QNetworkReply>
#include <QNetworkRequest>

Downloader::Downloader(QObject *parent) :
    QObject(parent)
{
    net = SingleNetworkAccessManager::instance();
}

QByteArray Downloader::readAll() const
{
    return data;
}

void Downloader::download(const QString &url)
{
    download(QUrl(url));
}

void Downloader::download(const QUrl url)
{
    QNetworkReply *r = net->get(QNetworkRequest(url));
    connect(r,SIGNAL(finished()),this,SLOT(loadFinished()));
    connect(r,SIGNAL(error(QNetworkReply::NetworkError)),this,SLOT(downloadError(QNetworkReply::NetworkError)));
}

void Downloader::loadFinished()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    reply->deleteLater();
    if(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt()==301||reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt()==302)
    {
        QNetworkReply *r = net->get(QNetworkRequest(reply->attribute(QNetworkRequest::RedirectionTargetAttribute).toUrl()));
        connect(r,SIGNAL(finished()),this,SLOT(loadFinished()));
        return;
    }
    if(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt()!=200)
    {

        emit error("Downloading fail with code:" + reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toString());
        return;
    }
    data = reply->readAll();
    emit ready();
}

void Downloader::downloadError(QNetworkReply::NetworkError code)
{
    Q_UNUSED(code)
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    reply->deleteLater();
    emit error("Download error: " + reply->errorString());
}
