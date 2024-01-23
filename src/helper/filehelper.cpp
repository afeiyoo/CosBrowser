#include "filehelper.h"

#include <QFile>
#include <QJsonDocument>

FileHelper::FileHelper() {}

QString FileHelper::readAllTxt(const QString &filePath)
{
    QFile file(filePath);
    if(file.exists() && file.open(QIODevice::ReadOnly)){

        QByteArray data = file.readAll();
        file.close();
        return data;
    }
    throw "读取文件失败";
}

QVariant FileHelper::readAllJson(const QString &filePath)
{
    QString data = FileHelper::readAllTxt(filePath);
    QJsonDocument doc = QJsonDocument::fromJson(data.toLocal8Bit());
    return doc.toVariant();
}
