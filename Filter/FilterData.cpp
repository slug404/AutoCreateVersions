#include "FilterData.h"

#include <QSettings>
#include <QDir>
#include <QFile>
#include <QDebug>

FilterData::FilterData()
{
}

FilterData::~FilterData()
{
}

void FilterData::setFilePath(const QString &filePath)
{
    QSettings setting(filePath, QSettings::IniFormat);
    {
        QString value = setting.value("files").toString();
        filterFiles_ = value.split(",").toSet();
    }

    {
        QString value = setting.value("dirs").toString();
        filterDirs_ = value.split(",").toSet();
    }
}

QSet<QString> FilterData::getFilterFiles()
{
    return filterFiles_;
}

QSet<QString> FilterData::getFilterDirs()
{
    return filterDirs_;
}
