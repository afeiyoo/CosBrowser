#include "mansignals.h"

ManSignals::ManSignals(QObject *parent)
    : QObject{parent}
{
    qRegisterMetaType<QList<MyBucket> >("QList<MyBucket>");
}

ManSignals::~ManSignals()
{
    qDebug("delete ManSignals");
}

