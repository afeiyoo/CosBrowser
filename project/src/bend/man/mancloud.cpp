﻿#include "mancloud.h"
#include <QDebug>
#include "src/bend/dao/clouds/daocloudsmock.h"
#include "src/plugins/manplugin.h"

//单例模式
Q_GLOBAL_STATIC(ManCloud, ins)

ManCloud::ManCloud(QObject *parent)
    : QObject{parent}
{
    m_model = new QStandardItemModel(this);
}

ManCloud *ManCloud::instance()
{
    return ins();
}

void ManCloud::setBuckets()
{
    DaoClouds* dao = MP->clouds();
    QList<MyBucket> buckets = dao->buckets();
    m_model->setRowCount(buckets.size());

    //设置表格标题内容
    QStringList labels;
    labels<<QString::fromLocal8Bit("桶名称")
           <<QString::fromLocal8Bit("地区")
           <<QString::fromLocal8Bit("创建时间");
    m_model->setColumnCount(labels.size());
    m_model->setHorizontalHeaderLabels(labels);

    for(int i = 0; i < buckets.size(); ++i){
        const MyBucket& bucket = buckets[i];
        QModelIndex index0 = m_model->index(i, 0);
        m_model->setData(index0, bucket.name);
        m_model->setData(index0, QString::fromLocal8Bit("存储桶名称: %1").arg(bucket.name), Qt::ToolTipRole);

        QModelIndex index1 = m_model->index(i, 1);
        m_model->setData(index1, bucket.location);

        QModelIndex index2 = m_model->index(i, 2);
        m_model->setData(index2, bucket.createDate);
    }

    qDebug() << "setBuckets";
}

QStandardItemModel *ManCloud::model() const
{
    return m_model;
}

void ManCloud::login(QString secretId, QString secretKey)
{
    QList<MyBucket> buckets = MP->clouds()->login(secretId, secretKey);
}
