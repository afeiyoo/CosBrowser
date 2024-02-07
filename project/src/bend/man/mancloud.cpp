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
    emit MG->mSignal->bucketSuccess(buckets);
    // setBuckets();
}

ManCloud::~ManCloud()
{
    qDebug("delete ManCloud ");
}
