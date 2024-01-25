#ifndef DBSQLITE_H
#define DBSQLITE_H

#include <QSqlDatabase>
#include <QString>

class DbSqlite
{
public:
    DbSqlite();

    ~DbSqlite();

    void connect(const QString& dbPath);

    void exec(const QString &sql);

private:
    QSqlDatabase m_db;
};

#endif // DBSQLITE_H
