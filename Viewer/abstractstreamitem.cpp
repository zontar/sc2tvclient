#include "abstractstreamitem.h"

AbstractStreamItem::AbstractStreamItem()
{
}

AbstractStreamItem::~AbstractStreamItem()
{

}

QVariant AbstractStreamItem::getValue(const QString &name) const
{
    return values_.contains(name)?values_[name]:QVariant();
}

void AbstractStreamItem::setValue(const QString &name, const QVariant &value)
{
    values_[name] = value;
}
