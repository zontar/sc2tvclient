#ifndef ABSTRACTSTREAMITEM_H
#define ABSTRACTSTREAMITEM_H

#include <QVariant>
#include <QMap>

class AbstractStreamItem
{
public:
    AbstractStreamItem();
    virtual ~AbstractStreamItem();
    QVariant getValue(const QString &name) const;
    void setValue(const QString &name, const QVariant &value);

private:
    QMap<QString, QVariant> values_;
};

#endif // ABSTRACTSTREAMITEM_H
