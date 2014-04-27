#include "singlenetworkaccessmanager.h"


SingleNetworkAccessManager *SingleNetworkAccessManager::self=NULL;

SingleNetworkAccessManager *SingleNetworkAccessManager::instance()
{
    if(!self) self = new SingleNetworkAccessManager();
    return self;
}

void SingleNetworkAccessManager::release()
{
    if(self) self->deleteLater();
}

SingleNetworkAccessManager::SingleNetworkAccessManager(QObject *parent) :
    QNetworkAccessManager(parent)
{
}
