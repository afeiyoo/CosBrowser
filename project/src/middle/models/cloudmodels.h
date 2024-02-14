#ifndef CLOUDMODELS_H
#define CLOUDMODELS_H

#include <QString>

struct BaseObject{
    bool isValid() const{
        return !isInvalid();
    }
    bool isInvalid() const{
        return name.isNull() || name.isEmpty();
    }

    QString name;
};

struct MyBucket: public BaseObject
{
    MyBucket();

    QString location;
    QString createDate;
};

struct MyObject: public BaseObject
{
    QString lastmodified;
    qulonglong size = 0;
    QString dir;
};

#endif // CLOUDMODELS_H
