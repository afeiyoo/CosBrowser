#ifndef DBSQLITE_H
#define DBSQLITE_H

#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>

class DbSqlite
{
public:
    DbSqlite();

    ~DbSqlite();


    void connect(const QString& dbPath);

    QSqlQuery exec(const QString &sql);

    bool exists(const QString &sql);
private:
    QSqlDatabase m_db;
};

#endif // DBSQLITE_H
