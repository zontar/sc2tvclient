#include "sc2tvstreamitem.h"

Sc2tvStreamItem::Sc2tvStreamItem(const QVariantMap &map): AbstractStreamItem(map)
{
    m_values["path"] = "http://sc2tv.ru/" + m_values["path"].toString();
}

Sc2tvStreamItem::~Sc2tvStreamItem()
{

}
