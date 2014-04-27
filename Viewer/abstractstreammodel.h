#ifndef ABSTRACTSTREAMMODEL_H
#define ABSTRACTSTREAMMODEL_H

#include <QAbstractListModel>
#include "abstractstreamitem.h"

class AbstractStreamModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit AbstractStreamModel(QObject *parent = 0);
    virtual ~AbstractStreamModel();

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    int rowCount(const QModelIndex &parent) const;

protected:
    //! Определяет минимальный набор необходимых свойств модели. При этом не задает соответсвие с полями Итема, нужно определить в классе-наследнике
    //! При определении дополнительных свойств нумерацию нужно начинать не менее чем с Qt::UserRole + 4
    enum class StandartStreamRoles: int
    {
        Title = Qt::DisplayRole,    //! Заголовок
        Url = Qt::UserRole + 1,     //! Адрес страницы стрима
        Preview = Qt::UserRole + 2,  //! Адрес картинки-превью
        Streamer = Qt::UserRole + 3
    };

    QHash<int, QByteArray> roleNames() const;
    QList<AbstractStreamItem> m_items;
    QHash<int, QByteArray> m_roles;         //! Список названий свойств модели для использования в qml
private:


signals:
};

#endif // ABSTRACTSTREAMMODEL_H
