#ifndef STREAMRIPPER_H
#define STREAMRIPPER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QList>
#include "streampreviewitem.h"
#include "imagestore.h"

class StreamRipper: public QObject
{
    Q_OBJECT
public:
    StreamRipper();
    ~StreamRipper();
    void load();
    QList<StreamPreviewItem> getItems() const;
    ImageStore *getImageStore();
private:
    QNetworkAccessManager net;
    QList<StreamPreviewItem> items;
    ImageStore store;
signals:
    void funStreamFound(StreamPreviewItem item);
private slots:
    void loadFinished(QNetworkReply *reply);
    void imageLoaded(int id, const QString &path);

};

#endif // STREAMRIPPER_H
