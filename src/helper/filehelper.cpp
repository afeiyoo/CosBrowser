#include "filehelper.h"

#include <QFile>

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
