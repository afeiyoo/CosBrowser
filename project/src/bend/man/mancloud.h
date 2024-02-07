#ifndef MANCLOUD_H
#define MANCLOUD_H

#include <QObject>

class ManCloud : public QObject
{
    Q_OBJECT
public:
    //不要使用ManBuckets构造函数创建对象，直接使用instance来使用对象即可
    explicit ManCloud(QObject *parent = nullptr);

    void login(QString secretId, QString secretKey);

    ~ManCloud();

signals:


};

#endif // MANCLOUD_H
