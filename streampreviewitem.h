#ifndef STREAMPREVIEWITEM_H
#define STREAMPREVIEWITEM_H

#include <QObject>


class StreamPreviewItem : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(QString decription READ getDescription WRITE setDescription)
    Q_PROPERTY(QString streamername  READ getStreamerName WRITE setStreamerName)
    Q_PROPERTY(QString gamename READ getGameName WRITE setGameName)
    Q_PROPERTY(QString section READ getSection WRITE setSection)
    Q_PROPERTY(QString link READ getLink WRITE setLink)
    Q_PROPERTY(QString picturelink READ getPictureLink WRITE setPictureLink)
    Q_PROPERTY(int rating READ getRating WRITE setRating)
    Q_PROPERTY(int id READ getId WRITE setId)

public:
    explicit StreamPreviewItem(QObject *parent = 0);
    StreamPreviewItem(const StreamPreviewItem &right);
    StreamPreviewItem& operator=(const StreamPreviewItem &right);
    void setName(const QString &val);
    QString getName() const;
    void setDescription(const QString &val);
    QString getDescription() const;
    void setStreamerName(const QString &val);
    QString getStreamerName() const;
    void setGameName(const QString &val);
    QString getGameName() const;
    void setSection(const QString &val);
    QString getSection() const;
    void setLink(const QString &val);
    QString getLink() const;
    void setPictureLink(const QString &val);
    QString getPictureLink() const;
    void setRating(const int val);
    int getRating() const;
    void setId(const int val);
    int getId() const;

private:
    QString name;
    QString description;
    QString streamer;
    QString game;
    QString section;
    QString link;
    QString picturelink;
    int id;
    int rating;

signals:
    
public slots:

};

#endif // STREAMPREVIEWITEM_H
