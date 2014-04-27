#ifndef SC2TVSTREAMSPROVIDER_H
#define SC2TVSTREAMSPROVIDER_H

#include "abstractstreamsprovider.h"
#include "sc2tvstreamitem.h"
#include "downloader.h"

#include <QList>

class Sc2tvStreamsProvider : public AbstractStreamsProvider
{
    Q_OBJECT
public:
    explicit Sc2tvStreamsProvider(QObject *parent = 0);
    ~Sc2tvStreamsProvider();
    void get();

private:
    Downloader d_;

signals:

public slots:
    void downloadError(const QString &error);
    void streamListDownloaded();

};

#endif // SC2TVSTREAMSPROVIDER_H
