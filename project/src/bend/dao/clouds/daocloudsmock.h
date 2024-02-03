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

private:
    QJsonValue m_mock;
};

#endif // DAOCLOUDSMOCK_H
