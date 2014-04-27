#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkReply>
#include "singlenetworkaccessmanager.h"

class Downloader : public QObject
{
    Q_OBJECT
public:
    explicit Downloader(QObject *parent = 0);
    QByteArray readAll() const;
    void download(const QString &url);
    void download(const QUrl url);

private:
    SingleNetworkAccessManager *net;
    QByteArray data;

signals:
    void ready();
    void error(const QString &text);

private slots:
    void loadFinished();

    void downloadError(QNetworkReply::NetworkError code);

};


#endif // DOWNLOADER_H
