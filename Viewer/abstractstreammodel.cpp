#include "abstractstreammodel.h"
#include "singlenetworkaccessmanager.h"
#include <QNetworkReply>
#include <QNetworkRequest>

AbstractStreamModel::AbstractStreamModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

AbstractStreamModel::~AbstractStreamModel()
{

}

QVariant AbstractStreamModel::data(const QModelIndex &index, int role) const
{
    if (index.row()<0 || index.row()>=m_items.count()) return QVariant();
    const AbstractStreamItem &item = m_items[index.row()];
    return item.getValue(m_roles[role]);
}

bool AbstractStreamModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.row()<0 || index.row()>=m_items.count()) return false;
    AbstractStreamItem &item = m_items[index.row()];
    return item.setValue(m_roles[role], value);
}

int AbstractStreamModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_items.size();
}

QHash<int, QByteArray> AbstractStreamModel::roleNames() const
{
    return m_roles;
}

void AbstractStreamModel::show(const int index)
{
    SingleNetworkAccessManager *net = SingleNetworkAccessManager::instance();
    QNetworkReply *r = net->get(QNetworkRequest(m_items[index].getValue(m_roles[(int)StandartStreamRoles::Url]).toUrl()));
    connect(r, SIGNAL(finished()), this, SLOT(pageLoaded()));
}

void AbstractStreamModel::addItem(const AbstractStreamItem &item)
{
    if(m_items.contains(item)) return;

    beginInsertRows(QModelIndex(),m_items.size(),m_items.size());
    m_items << item;
    endInsertRows();
}

void AbstractStreamModel::pageLoaded()
{
    QNetworkReply *r = qobject_cast<QNetworkReply *>(sender());
    r->deleteLater();
    QString page = r->readAll();
    getPlayerUrl(page);
}
