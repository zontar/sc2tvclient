#ifndef SC2TVSTREAMMODEL_H
#define SC2TVSTREAMMODEL_H

#include "abstractstreammodel.h"

class QJsonObject;

class Sc2tvStreamModel : public AbstractStreamModel
{
    Q_OBJECT
public:
    explicit Sc2tvStreamModel(QObject *parent = 0);
    ~Sc2tvStreamModel();

protected:
    enum class Sc2tvStreamRoles: int
    {
        Category = Qt::UserRole + 4,
        Description = Qt::UserRole + 5,
        Id = Qt::UserRole + 6,
        Mature = Qt::UserRole + 7,
        Rating = Qt::UserRole + 8,
        Sandbox = Qt::UserRole + 9,
        Uid = Qt::UserRole + 10,
        Timestamp = Qt::UserRole + 11
    };

public slots:
    const QUrl getRelatedDelegate() const;
    void getPlayerUrl(const QString &page);

private slots:
    QString getUrl(const QJsonObject &jObj);
};

#endif // SC2TVSTREAMMODEL_H
