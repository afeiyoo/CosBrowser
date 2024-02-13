#ifndef DAOCLOUDSCOS_H
#define DAOCLOUDSCOS_H

#include "src/bend/dao/clouds/daoclouds.h"

namespace qcloud_cos{
class CosConfig;
}

class DaoCloudsCos : public DaoClouds
{
public:
    DaoCloudsCos();

    ~DaoCloudsCos();

    QList<MyBucket> buckets() override;

    QList<MyBucket> login(const QString& secretId, const QString& secretKey) override;

private:
    qcloud_cos::CosConfig* m_config = nullptr;
};

#endif // DAOCLOUDSCOS_H
