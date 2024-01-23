#include "manbuckets.h"
#include <QDebug>
#include "src/bend/dao/daobuckets.h"

//单例模式
Q_GLOBAL_STATIC(ManBuckets, ins);

ManBuckets::ManBuckets(QObject *parent)
    : QObject{parent}
{
    m_model = new QStandardItemModel(this);
}

ManBuckets *ManBuckets::instance()
{
    return ins();
}

void ManBuckets::setBuckets()
{
    DaoBuckets dao;
    QList<MyBucket> buckets = dao.bucketsFromMock(":/static/testing/buckets2.json");
    m_model->setRowCount(buckets.size());
    m_model->setColumnCount(3);
    for(int i = 0; i < buckets.size(); ++i){
        const MyBucket& bucket = buckets[i];
        QModelIndex index0 = m_model->index(i, 0);
        m_model->setData(index0, bucket.name);
        m_model->setData(index0, QString::fromLocal8Bit("存储桶名称: %1").arg(bucket.name), Qt::ToolTipRole);

        QModelIndex index1 = m_model->index(i, 1);
        m_model->setData(index1, bucket.name);

        QModelIndex index2 = m_model->index(i, 2);
        m_model->setData(index2, bucket.name);
    }

    qDebug() << "setBuckets";
}

QStandardItemModel *ManBuckets::model() const
{
    return m_model;
}
