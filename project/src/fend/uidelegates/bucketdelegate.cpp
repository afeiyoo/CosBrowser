#include "bucketdelegate.h"

#include <QComboBox>
#include <QDebug>

BucketDelegate::BucketDelegate(QObject *parent)
    :QStyledItemDelegate(parent)
{

}

QWidget *BucketDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);

    QComboBox* box = new QComboBox(parent);
    box->addItem("ap-beijing");
    box->addItem("ap-tianjin");
    box->addItem("ap-shanghai");
    box->setFrame(false);

    //QComboBox会自动被回收
    // connect(box, &QComboBox::destroyed, this, [=]{
    //     qDebug()<<QString::fromLocal8Bit("我被释放了");
    // });
    return box;
}

void BucketDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox* box = static_cast<QComboBox*>(editor);
    QString text = index.data(Qt::EditRole).toString();
    box->setCurrentText(text);
}

void BucketDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox* box = static_cast<QComboBox*>(editor);
    model->setData(index, box->currentText());
}
