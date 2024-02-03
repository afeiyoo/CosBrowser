#ifndef DAOCLOUDS_H
#define DAOCLOUDS_H

#include <QList>
#include "src/middle/models/cloudmodels.h"

class DaoClouds{
public:
    DaoClouds(){}


    virtual QList<MyBucket> buckets() = 0;
};

#endif // DAOCLOUDS_H
