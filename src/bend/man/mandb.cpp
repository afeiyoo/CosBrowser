#include "mandb.h"
#include "src/config/config.h"

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
    connect();
}

void ManDB::connect()
{
    m_db.connect(CONF::SQLITE::NAME);
}
