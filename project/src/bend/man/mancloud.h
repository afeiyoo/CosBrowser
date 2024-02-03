#ifndef MANCLOUD_H
#define MANCLOUD_H

#include <QObject>
#include <QStandardItemModel>

#define MC ManCloud::instance()

class ManCloud : public QObject
{
    Q_OBJECT
public:
    //不要使用ManBuckets构造函数创建对象，直接使用instance来使用对象即可
    explicit ManCloud(QObject *parent = nullptr);

    static ManCloud* instance();

    void setBuckets();

    QStandardItemModel *model() const;

signals:

private:
    QStandardItemModel* m_model = nullptr;
};

#endif // MANCLOUD_H
