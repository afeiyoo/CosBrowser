#ifndef MANSIGNALS_H
#define MANSIGNALS_H

#include <QObject>
#include "src/middle/models/cloudmodels.h"

class ManSignals : public QObject
{
    Q_OBJECT
public:
    explicit ManSignals(QObject *parent = nullptr);

    ~ManSignals();

signals:
    void loginSuccess();
    void error(int api, const QString& msg);
    void bucketSuccess(const QList<MyBucket>& buckets);
    void unLogin();
};

#endif // MANSIGNALS_H
