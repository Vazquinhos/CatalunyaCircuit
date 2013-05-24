#ifndef FILEUTILS_H
#define FILEUTILS_H
#include <QStringList>
#include <QDir>


class FileUtils
{
public:
    FileUtils();
    static QStringList listFilesInFolder(QString fullFolderPath, QStringList fileFilters);
    static QStringList listFilesInFolder(QString fullFolderPath);
};

#endif // FILEUTILS_H
