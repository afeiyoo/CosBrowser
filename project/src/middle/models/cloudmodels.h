#ifndef CLOUDMODELS_H
#define CLOUDMODELS_H

#include <QString>

struct MyBucket
{
    MyBucket();

    QString name;
    QString location;
    QString createDate;
};

#endif // CLOUDMODELS_H
