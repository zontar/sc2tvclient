#ifndef IMAGESTORE_H
#define IMAGESTORE_H

#include <QObject>
#include <QVector>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class ImageStore : public QObject
{
    Q_OBJECT
public:
    explicit ImageStore(QObject *parent = 0);
    void addImage(int id, const QString &address);
private:
    QNetworkAccessManager net;
signals:
    void imageReady(int id, const QString &path);
    
public slots:
protected slots:
    void loadFinished(QNetworkReply *reply);
};

#endif // IMAGESTORE_H
