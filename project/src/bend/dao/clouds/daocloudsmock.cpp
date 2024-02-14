﻿#include "daocloudsmock.h"
#include "src/helper/filehelper.h"
#include "src/config/errorcode.h"
#include "src/config/exception.h"
#include "src/middle/manglobal.h"

#include <QJsonArray>
#include <QThread>
#include <QDebug>

DaoCloudsMock::DaoCloudsMock(const QString& path)
{
    m_mock = FileHelper::readAllJson(path).toJsonValue();
}

QList<MyBucket> DaoCloudsMock::buckets()
{
    QList<MyBucket> res;

    QJsonArray arr = m_mock["buckets"].toArray();
    for(int i = 0; i < arr.count(); ++i){
        QJsonValue v = arr[i];
        MyBucket bucket;
        bucket.name = v["name"].toString();
        bucket.location = v["location"].toString();
        bucket.createDate = v["create_date"].toString();

        res.append(bucket);
        mInfo(QString::fromLocal8Bit("name[%1], location[%2], date[%3]").arg(bucket.name,
                                                                             bucket.location,
                                                                             bucket.createDate));
    }

    return res;
}

QList<MyBucket> DaoCloudsMock::login(const QString &secretId, const QString &secretKey)
{
    QThread::sleep(3);
    QJsonArray arr = m_mock["users"].toArray();
    for(int i = 0; i < arr.count(); ++i){
        QJsonValue v = arr[i];
        if(secretId == v["secretId"].toString() && secretKey == v["secretKey"].toString())
            return buckets();   //登陆成功后，获取桶列表
    }

    throw BaseException(EC_211000, QString::fromLocal8Bit("请检查您的SecretId或SecretKey是否正确"));
}

bool DaoCloudsMock::isBucketExists(const QString &bucketName)
{
    return false;
}

QString DaoCloudsMock::getBucketLocation(const QString &bucketName)
{
    return QString();
}

void DaoCloudsMock::putBucket(const QString &bucketName, const QString &location)
{

}

void DaoCloudsMock::deleteBucket(const QString &bucketName)
{

}

QList<MyObject> DaoCloudsMock::getObjects(const QString &bucketName, const QString &dir)
{
    return QList<MyObject>();
}
