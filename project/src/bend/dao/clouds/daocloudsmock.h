#ifndef DAOCLOUDSMOCK_H
#define DAOCLOUDSMOCK_H

#include "src/middle/models/cloudmodels.h"
#include "src/bend/dao/clouds/daoclouds.h"
#include <QJsonValue>
#include <QList>

class DaoCloudsMock : public DaoClouds
{
public:
    DaoCloudsMock(const QString& path);

    QList<MyBucket> buckets();

    QList<MyBucket> login(const QString& secretId, const QString& secretKey) override;

private:
    QJsonValue m_mock;
};

#endif // DAOCLOUDSMOCK_H
