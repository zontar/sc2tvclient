#include "sc2tvstreammodel.h"

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
