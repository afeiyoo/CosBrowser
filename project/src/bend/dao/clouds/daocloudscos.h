#ifndef DAOCLOUDSCOS_H
#define DAOCLOUDSCOS_H

#include "src/bend/dao/clouds/daoclouds.h"

namespace qcloud_cos{
class CosConfig;
class CosResult;
class GetBucketResp;
}

class DaoCloudsCos : public DaoClouds
{
public:
    DaoCloudsCos();

    ~DaoCloudsCos();

    QList<MyBucket> buckets() override;

    QList<MyBucket> login(const QString& secretId, const QString& secretKey) override;

    bool isBucketExists(const QString& bucketName) override;

    QString getBucketLocation(const QString& bucketName) override;

    void putBucket(const QString& bucketName, const QString& location) override;

    void deleteBucket(const QString& bucketName) override;

    QList<MyObject> getObjects(const QString &bucketName, const QString &dir) override;

    void putObject(const QString& bucketName,
                   const QString& key,
                   const QString& localPath,
                   const TransProgressCallback& callback) override;

    void getObject(const QString& bucketName,
                   const QString& key,
                   const QString& localPath,
                   const TransProgressCallback& callback) override;

private:
    QList<MyObject> getDirList(qcloud_cos::GetBucketResp& resp, const QString& dir);

    QList<MyObject> getFileList(qcloud_cos::GetBucketResp& resp, const QString& dir);

    void throwError(const QString& code, qcloud_cos::CosResult& result);

    MyBucket getBucketByName(const QString& bucketName);

private:
    qcloud_cos::CosConfig* m_config = nullptr;
};

#endif // DAOCLOUDSCOS_H
