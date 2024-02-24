#include "mancloud.h"
#include <QDebug>
#include "src/bend/dao/clouds/daocloudsmock.h"
#include "src/plugins/manplugin.h"
#include "src/middle/manglobal.h"
#include "src/middle/signals/mansignals.h"

ManCloud::ManCloud(QObject *parent)
    : QObject{parent}
{

}

void ManCloud::login(QString secretId, QString secretKey)
{
    QList<MyBucket> buckets = MG->mPlugin->clouds()->login(secretId, secretKey);
    emit MG->mSignal->bucketsSuccess(buckets);
    bucketsAlready(buckets);
}

ManCloud::~ManCloud()
{
    qDebug("delete ManCloud ");
}

void ManCloud::getBuckets()
{
    QList<MyBucket> buckets = MG->mPlugin->clouds()->buckets();
    bucketsAlready(buckets);
}

void ManCloud::putBucket(const QString &bucketName, const QString &location)
{
    MG->mPlugin->clouds()->putBucket(bucketName, location);
    getBuckets();
}

void ManCloud::deleteBucket(const QString &bucketName)
{
    MG->mPlugin->clouds()->deleteBucket(bucketName);
    getBuckets();
}

void ManCloud::getObjects(const QString &bucketName, const QString &dir)
{
    QList<MyObject> objs = MG->mPlugin->clouds()->getObjects(bucketName, dir);
    emit MG->mSignal->objectsSuccess(objs);
}

void ManCloud::getObject(const QString &jobId, const QString &bucketName, const QString &key, const QString &localPath)
{
    auto callback = [=](qulonglong transferred_size, qulonglong total_size, void *){
        assert(transferred_size < total_size);
        if(0 == transferred_size % (1024 * 1024)){
            emit MG->mSignal->downloadProcess(jobId, transferred_size, total_size);
        }
    };
    MG->mPlugin->clouds()->getObject(bucketName, key, localPath, callback);
    emit MG->mSignal->downloadSuccess(jobId);
}

void ManCloud::putObjcet(const QString &jobId, const QString &bucketName, const QString &key, const QString &localPath)
{
    auto callback = [=](qulonglong transferred_size, qulonglong total_size, void *){
        assert(transferred_size <= total_size);
        if(0 == transferred_size % (1024 * 1024)){
            emit MG->mSignal->uploadProcess(jobId, transferred_size, total_size);
        }
    };
    MG->mPlugin->clouds()->putObject(bucketName, key, localPath, callback);
    emit MG->mSignal->uploadSuccess(jobId);
}

void ManCloud::bucketsAlready(const QList<MyBucket> &buckets)
{
    emit MG->mSignal->bucketsSuccess(buckets);
}
