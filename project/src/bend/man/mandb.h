#ifndef MANDB_H
#define MANDB_H

#include <QObject>

#include "src/bend/dao/dbs/daologininfosqlite.h"

#define MDB ManDB::instance()

class ManDB : public QObject
{
    Q_OBJECT
public:
    explicit ManDB(QObject *parent = nullptr);

    static ManDB* instance();

    void init();

    void saveLoginInfo(const QString& name, const QString& id, const QString& key,
                       const QString& remark);

    void removeLoginInfo(const QString& id);

    int indexOfLoginInfo(const QString& secretId);

    QStringList loginNameList();

    LoginInfo loginInfoByName(const QString& name);
signals:

private:
    DaoLoginInfoSqlite m_daoLoginInfo;

    QList<LoginInfo> m_loginInfoList;
};

#endif // MANDB_H
