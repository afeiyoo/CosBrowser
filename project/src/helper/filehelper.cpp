#include "filehelper.h"

#include <QFile>
#include <QJsonDocument>
#include <QDir>

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

QList<QStringList> FileHelper::readAllCsv(const QString& filePath)
{
    QList<QStringList> records;
    QFile file(filePath);
    if(file.exists() && file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        while(!stream.atEnd()){
            QString line = stream.readLine();
            QStringList row = line.split(',');
            records.append(row);
        }

        file.close();
    }
    return records;
}

void FileHelper::writeFile(const QStringList lines, const QString &filePath)
{
    QFile file(filePath);
    if(file.open(QIODevice::WriteOnly)){
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        for(const auto& line: lines){
            stream << line << endl;
        }
        file.close();
        return;
    }
    throw "写入文件失败";
}

QString FileHelper::joinPath(const QString &path1, const QString &path2)
{
    QString path = path1 + "/" + path2;
    QStringList pathList = path.split(QRegExp("[/\\\\]"), Qt::SkipEmptyParts);
    path = pathList.join("/");
    return QDir::cleanPath(path);   //清理无效路径 C://./../def -> C:/def
}

bool FileHelper::mkPath(const QString &path)
{
    QDir dir;
    return dir.mkpath(path);
}
