#ifndef ABSTRACTSTREAMSPROVIDER_H
#define ABSTRACTSTREAMSPROVIDER_H

#include <QObject>
#include "abstractstreamitem.h"

class AbstractStreamsProvider : public QObject
{
    Q_OBJECT
public:
    explicit AbstractStreamsProvider(QObject *parent = 0);
    virtual ~AbstractStreamsProvider();
    virtual void get() = 0;

signals:
    void found(AbstractStreamItem &item);
    void error(const QString &error);

public slots:

};

#endif // ABSTRACTSTREAMSPROVIDER_H
