#include "daocloudsmock.h"
#include "src/helper/filehelper.h"

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
        qDebug() << bucket.name << bucket.location << bucket.createDate;
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
    throw QString::fromLocal8Bit("用户名错误");
}
