#ifndef SINGLENETWORKACCESSMANAGER_H
#define SINGLENETWORKACCESSMANAGER_H


#include <QNetworkAccessManager>

class SingleNetworkAccessManager : public QNetworkAccessManager
{
    Q_OBJECT
public:
    static SingleNetworkAccessManager *instance();
    static void release();

protected:
    explicit SingleNetworkAccessManager(QObject *parent = 0);

private:
    static SingleNetworkAccessManager *self;
};

#endif // SINGLENETWORKACCESSMANAGER_H
