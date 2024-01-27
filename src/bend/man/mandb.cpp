#include "mandb.h"
#include <QDateTime>
#include <QDebug>

//单例模式
Q_GLOBAL_STATIC(ManDB, ins)

ManDB::ManDB(QObject *parent)
    : QObject{parent}
{

}

ManDB *ManDB::instance()
{
    return ins();
}

void ManDB::init()
{
    m_daoLoginInfo.connect();
    m_daoLoginInfo.createTable();
}

void ManDB::saveLoginInfo(const QString &name, const QString &id, const QString &key, const QString &remark)
{
    LoginInfo info;
    info.name = (name == "" ? id : name);
    info.secret_id = id.trimmed();
    info.secret_key = key.trimmed();
    info.remark = remark.trimmed();
    info.timestamp = QDateTime::currentDateTimeUtc().toTime_t();
    if(m_daoLoginInfo.exists(info.secret_id)){
        m_daoLoginInfo.update(info);
    }else{
        m_daoLoginInfo.insert(info);
    }
}

void ManDB::removeLoginInfo(const QString &id)
{
    if(m_daoLoginInfo.exists(id))
        m_daoLoginInfo.remove(id);
}
