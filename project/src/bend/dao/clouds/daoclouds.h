#ifndef DAOCLOUDS_H
#define DAOCLOUDS_H

#include <QList>
#include "src/middle/models/cloudmodels.h"

class DaoClouds{
public:
    DaoClouds(){}

    virtual QList<MyBucket> buckets() = 0;

    virtual QList<MyBucket> login(const QString& secretId, const QString& secretKey) = 0;

    virtual bool isBucketExists(const QString& bucketName) = 0;

    virtual QString getBucketLocation(const QString& bucketName) = 0;

    virtual void putBucket(const QString& bucketName, const QString& location) = 0;

    virtual void deleteBucket(const QString& bucketName) = 0;

    virtual QList<MyObject> getObjects(const QString& bucketName, const QString& dir) = 0;
};

#endif // DAOCLOUDS_H
