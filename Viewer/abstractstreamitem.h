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
    void setValue(const QString &name, const QVariant &value);

protected:
    QVariantMap values_;
};

#endif // ABSTRACTSTREAMITEM_H
