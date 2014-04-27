#include "sc2tvstreamitem.h"

Sc2tvStreamItem::Sc2tvStreamItem(const QVariantMap &map): AbstractStreamItem(map)
{
    m_values["path"] = "http://sc2tv.ru/" + m_values["path"].toString();
    QString img = m_values["img"].toString();
    if(!img.startsWith("http"))
    {
        if(img.startsWith("/sites")) m_values["img"] = "http://sc2tv.ru" + img;
        else m_values["img"] = "qrc:///images/thumb-error.jpg";
    }
}

Sc2tvStreamItem::~Sc2tvStreamItem()
{

}
