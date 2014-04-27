#ifndef SC2TVSTREAMSPROVIDER_H
#define SC2TVSTREAMSPROVIDER_H

#include "abstractstreamsprovider.h"
#include "downloader.h"

class Sc2tvStreamsProvider : public AbstractStreamsProvider
{
    Q_OBJECT
public:
    explicit Sc2tvStreamsProvider(QObject *parent = 0);
    void get();

signals:

public slots:

};

#endif // SC2TVSTREAMSPROVIDER_H
