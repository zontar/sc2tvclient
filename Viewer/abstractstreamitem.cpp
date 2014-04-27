#include "abstractstreamitem.h"

AbstractStreamItem::AbstractStreamItem()
{
}

AbstractStreamItem::AbstractStreamItem(const QVariantMap &map): m_values(map)
{

}

AbstractStreamItem::~AbstractStreamItem()
{

}

QVariant AbstractStreamItem::getValue(const QString &name) const
{
    return m_values.contains(name)?m_values[name]:QVariant();
}

bool AbstractStreamItem::setValue(const QString &name, const QVariant &value)
{
    if(!m_values.contains(name)) return false;
    m_values[name] = value;
    return true;
}
