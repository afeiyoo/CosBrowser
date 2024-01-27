#ifndef MANDB_H
#define MANDB_H

#include <QObject>

#include "src/bend/dao/daologininfo.h"

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
signals:

private:
    DaoLoginInfo m_daoLoginInfo;
};

#endif // MANDB_H
