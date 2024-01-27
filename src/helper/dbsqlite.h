#ifndef DBSQLITE_H
#define DBSQLITE_H

#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QMap>

typedef QMap<QString, QVariant> RECORD;

class DbSqlite
{
public:
    DbSqlite();

    ~DbSqlite();


    void connect(const QString& dbPath);

    QSqlQuery exec(const QString &sql);

    QSqlQuery exec(const QString &sql, const QVariantList& variantList);

    bool exists(const QString &sql);

    QList<RECORD> select(const QString &sql);
private:
    QSqlDatabase m_db;
};

#endif // DBSQLITE_H
