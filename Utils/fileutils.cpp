#include "fileutils.h"

FileUtils::FileUtils()
{
}

QStringList FileUtils::listFilesInFolder(QString fullFolderPath){
    QStringList fileFilters;
    fileFilters <<"*";
    return listFilesInFolder(fullFolderPath, fileFilters);
}

QStringList FileUtils::listFilesInFolder(QString fullFolderPath, QStringList fileFilters){
    QDir modelsDir(fullFolderPath);
    QStringList folderFilter;
    folderFilter <<"*";
    QStringList fileList = modelsDir.entryList(fileFilters, QDir::Files); //List all models of the directory;
    QStringList folderList = modelsDir.entryList(folderFilter, QDir::Dirs); //List all models of the directory
    QStringList fileListFolder;
    QString path;

    for(int i = 2; i < folderList.size(); i++){ //Starting at 2 avoiding back folders /. and /..
        path = (fullFolderPath + folderList[i] + "/");
        fileListFolder = listFilesInFolder(path, fileFilters);

        for(int j = 0; j < fileListFolder.size(); j++){
            fileList.push_back(folderList[i] + "/" + fileListFolder[j]);
        }
    }

    for(int i = 0; i < fileList.size(); i++){ //Starting at 2 avoiding back folders /. and /..
        fileList[i] = fullFolderPath + fileList[i];
    }

    return fileList;
}
