#include "sc2tvstreammodel.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>

Sc2tvStreamModel::Sc2tvStreamModel(QObject *parent) :
    AbstractStreamModel(parent)
{
    m_roles[(int)StandartStreamRoles::Title] = "title";
    m_roles[(int)StandartStreamRoles::Url] = "path";
    m_roles[(int)StandartStreamRoles::Preview] = "img";
    m_roles[(int)StandartStreamRoles::Streamer] = "streamer_name";
    m_roles[(int)Sc2tvStreamRoles::Category] = "category";
    m_roles[(int)Sc2tvStreamRoles::Description] = "description";
    m_roles[(int)Sc2tvStreamRoles::Id] = "id";
    m_roles[(int)Sc2tvStreamRoles::Mature] = "mature";
    m_roles[(int)Sc2tvStreamRoles::Rating] = "rating";
    m_roles[(int)Sc2tvStreamRoles::Sandbox] = "sandbox";
    m_roles[(int)Sc2tvStreamRoles::Uid] = "streamer_uid";
    m_roles[(int)Sc2tvStreamRoles::Timestamp] = "timestamp";
}

Sc2tvStreamModel::~Sc2tvStreamModel()
{

}

const QUrl Sc2tvStreamModel::getRelatedDelegate() const
{
    return QUrl("qrc:///sc2tv/Sc2tvDelegate.qml");
}

void Sc2tvStreamModel::getPlayerUrl(const QString &page)
{
    QRegularExpression re("var current_players = (\\[.*\\])", QRegularExpression::InvertedGreedinessOption);
    QRegularExpressionMatch match = re.match(page);
    if(!match.hasMatch())
    {
        emit error("Couldn't found player on page");
        return;
    }
    QString data = match.captured(1);
    QJsonDocument jDoc = QJsonDocument::fromJson(data.toLocal8Bit());
    if(jDoc.isEmpty())
    {
        emit error("Couldn't create JSON Document from player var");
        return;
    }
    QStringList players;
    if(jDoc.isArray())
    {
        QJsonArray jArr = jDoc.array();
        for(auto iter = jArr.begin(); iter != jArr.end(); ++iter)
        {
            if(!(*iter).isObject()) continue;
            QString player = getUrl((*iter).toObject());
            if(!player.isEmpty()) players << player;
        }
    }
    else
    {
         QString player = getUrl(jDoc.object());
         players << player;
    }

    emit foundUrls(players);

}

QString Sc2tvStreamModel::getUrl(const QJsonObject &jObj)
{
    QString playerName = jObj.find("name").value().toString();
    QString playerHtml = jObj.find("html").value().toString();
    QRegularExpression re;
    re.setPatternOptions(QRegularExpression::InvertedGreedinessOption);

    if(playerName == "GoodGame")
    {
        re.setPattern("src=\"(.*)\"");
    }
    else if(playerName == "TwitchTv")
    {
        re.setPattern("data=\"(.*)\"");
    }
    else if(playerName == "Cybergame")
    {
        re.setPattern("src=\"(.*)\\&");
    }
    else
    {
        emit error("Unsupported player: " + playerName);
        return QString();
    }
    QRegularExpressionMatch match = re.match(playerHtml);
    if(!match.hasMatch())
    {
        emit error("Couldn't found player src");
        return QString();
    }
    return match.captured(1);
}

