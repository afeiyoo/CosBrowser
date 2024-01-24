#include "dbsqlite.h"
#include <QSqlError>

DbSqlite::DbSqlite() {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
}

DbSqlite::~DbSqlite()
{
    if(m_db.isOpen()){
        m_db.close();
    }
}

void DbSqlite::connect(const QString &dbPath)
{
    m_db.setDatabaseName(dbPath);
    if(!m_db.open()){
        throw QString::fromLocal8Bit("打开数据库失败：%1 %2").arg(dbPath, m_db.lastError().text());
    }
}
