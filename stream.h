#ifndef STREAM_H
#define STREAM_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Stream : public QObject
{
    Q_OBJECT
public:
    explicit Stream(QObject *parent = 0);
    
private:
    QNetworkAccessManager net;

signals:
    void streamReady(const QString &link);

public slots:
    void prepare(const QString &link);

protected slots:
    void loadFinished(QNetworkReply *reply);

};

#endif // STREAM_H
