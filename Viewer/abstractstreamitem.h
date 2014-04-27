#ifndef ABSTRACTSTREAMITEM_H
#define ABSTRACTSTREAMITEM_H

#include <QVariant>
#include <QMap>

class AbstractStreamItem
{
public:
    AbstractStreamItem();
    AbstractStreamItem(const QVariantMap &map);
    virtual ~AbstractStreamItem();
    QVariant getValue(const QString &name) const;
    bool setValue(const QString &name, const QVariant &value);

protected:
    QVariantMap m_values;
};

#endif // ABSTRACTSTREAMITEM_H
