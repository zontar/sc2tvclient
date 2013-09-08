#ifndef STREAMSORTFILTERPROXYMODEL_H
#define STREAMSORTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>

class StreamSortFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit StreamSortFilterProxyModel(QObject *parent = 0);

signals:
    void showStream(const QString &link);

public slots:

};

#endif // STREAMSORTFILTERPROXYMODEL_H
