#ifndef FILEHELPER_H
#define FILEHELPER_H

#include <QString>


class FileHelper
{
public:
    FileHelper();

    //读取文件的方法
    static QString readAllTxt(const QString& filePath);
};

#endif // FILEHELPER_H
