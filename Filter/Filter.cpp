#include "Filter.h"
#include "Singleton.h"
#include "FilterData.h"

bool Filter::isFilterDir(const QString dirPath)
{
    QSharedPointer<FilterData> pFileData = Singleton::Instance("filter.ini");
    return pFileData->getFilterDirs().contains(dirPath);
}

bool Filter::isFilterFiles(const QString filePath)
{
    QSharedPointer<FilterData> pFileData = Singleton::Instance("filter.ini");
    return pFileData->getFilterFiles().contains(filePath);
}


