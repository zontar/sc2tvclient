#ifndef SC2TVSTREAMITEM_H
#define SC2TVSTREAMITEM_H

#include "abstractstreamitem.h"

class Sc2tvStreamItem : public AbstractStreamItem
{
public:
    Sc2tvStreamItem(const QVariantMap &map);
    ~Sc2tvStreamItem();
};

#endif // SC2TVSTREAMITEM_H
