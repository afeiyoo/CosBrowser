﻿#include "dbsqlite.h"
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

QSqlQuery DbSqlite::exec(const QString &sql)
{
    QSqlQuery query;
    if(!query.exec(sql)){
        throw QString::fromLocal8Bit("执行失败: %1 %2").arg(sql, query.lastError().text());
    }

    return query;
}

bool DbSqlite::exists(const QString &sql)
{
    QSqlQuery query = exec(sql);
    return query.next();    //有数据返回true，没有返回false
}
