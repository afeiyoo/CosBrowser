#ifndef MANBUCKETS_H
#define MANBUCKETS_H

#include <QObject>
#include <QStandardItemModel>

#define MB ManBuckets::instance()

class ManBuckets : public QObject
{
    Q_OBJECT
public:
    //不要使用ManBuckets构造函数创建对象，直接使用instance来使用对象即可
    explicit ManBuckets(QObject *parent = nullptr);

    static ManBuckets* instance();

    void setBuckets();

    QStandardItemModel *model() const;

signals:

private:
    QStandardItemModel* m_model = nullptr;
};

#endif // MANBUCKETS_H
