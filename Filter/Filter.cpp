#include "Filter.h"
#include "Singleton.h"
#include "FilterData.h"

bool Filter::isFilterDir(const QString dirPath)
{
    QSharedPointer<FilterData> pFileData = Singleton::instance("filter.ini");
    //return pFileData->getFilterDirs().contains(dirPath);
    //没有处理子路径
    foreach (const QString &path, pFileData->getFilterDirs())
    {
        if(dirPath.contains(path))
        {
            return true;
        }
    }

    return false;
}

bool Filter::isFilterFiles(const QString filePath)
{
    QSharedPointer<FilterData> pFileData = Singleton::instance("filter.ini");
    return pFileData->getFilterFiles().contains(filePath);
}


