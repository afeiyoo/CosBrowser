#include "dbsqlite.h"
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

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

QSqlQuery DbSqlite::exec(const QString &sql, const QVariantList &variantList)
{
    QSqlQuery query;
    if(!query.prepare(sql)){
        throw QString::fromLocal8Bit("预编译sql失败: %1 %2").arg(sql, query.lastError().text());
    }

    for(const auto& var : variantList){
        query.addBindValue(var);
    }

    if(!query.exec()){
        throw QString::fromLocal8Bit("执行sql bindvalue失败: %1 %2").arg(sql, query.lastError().text());
    }
    return query;
}

bool DbSqlite::exists(const QString &sql)
{
    QSqlQuery query = exec(sql);
    return query.next();    //有数据返回true，没有返回false
}

QList<RECORD> DbSqlite::select(const QString& sql)
{
    QList<RECORD> retList;
    QSqlQuery query = exec(sql);

    while(query.next()){
        RECORD ret;

        QSqlRecord record = query.record(); //一条记录
        for(int i = 0; i < record.count(); ++i){
            QString name = record.fieldName(i); //获取字段名
            QVariant value = record.value(i);   //获取值
            ret[name] = value;
        }
        qDebug() << QString::fromLocal8Bit("查询出结果")<<ret;
        retList.append(ret);
    }

    return retList;
}
