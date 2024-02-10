#ifndef FILEHELPER_H
#define FILEHELPER_H

#include <QString>
#include <QVariant>


class FileHelper
{
public:
    FileHelper();

    //读取文件的方法
    static QString readAllTxt(const QString& filePath);

    static QVariant readAllJson(const QString& filePath);

    static QList<QStringList> readAllCsv(const QString& filePath);

    static void writeFile(const QStringList lines, const QString& filePath);

    //拼接目录
    static QString joinPath(const QString& path1, const QString& path2);

    //创建目录
    static bool mkPath(const QString& path);
};

#endif // FILEHELPER_H
