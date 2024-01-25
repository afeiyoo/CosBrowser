#ifndef MANDB_H
#define MANDB_H

#include <QObject>

#include "src/helper/dbsqlite.h"

#define MDB ManDB::instance()

class ManDB : public QObject
{
    Q_OBJECT
public:
    explicit ManDB(QObject *parent = nullptr);

    static ManDB* instance();

    void init();
signals:

private:
    void connect();

    void createLoginInfoTable();

    DbSqlite m_db;
};

#endif // MANDB_H
