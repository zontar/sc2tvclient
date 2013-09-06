#ifndef STREAMPREVIEW_H
#define STREAMPREVIEW_H

#include <QObject>
#include <QAbstractListModel>
#include "streampreviewitem.h"
#include "stream.h"

class StreamPreviewModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(int itemCount READ getItemCount WRITE setItemCount NOTIFY itemCountChanged)
public:
    explicit StreamPreviewModel(QObject *parent = 0);
    void setItemCount(const int &val);
    int getItemCount() const;
    enum Roles
    {
        NameRole = Qt::DisplayRole,
        DescriptionRole =  Qt::UserRole + 1,
        StreamerRole =  Qt::UserRole + 2,
        GameRole =  Qt::UserRole + 3,
        SectionRole =  Qt::UserRole + 4,
        LinkRole =  Qt::UserRole + 5,
        PictureLinkRole =  Qt::UserRole + 6,
        IdRole =  Qt::UserRole + 7,
        RatingRole =  Qt::UserRole + 8
    };
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
        bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
        int rowCount(const QModelIndex &parent) const;
protected:
        QHash<int, QByteArray> roleNames() const;
private:
    int itemCount;
    QList<StreamPreviewItem> items;
    QHash<int, QByteArray> roles;
    Stream stream;

signals:
    void itemCountChanged();
    void showStream(const QString &link);
    
public slots:
    void addItem(const StreamPreviewItem item);
    void addItems(QList<StreamPreviewItem> values);
    void loadStream(int id);
    void streamReady(const QString &link);
};

#endif // STREAMPREVIEW_H
