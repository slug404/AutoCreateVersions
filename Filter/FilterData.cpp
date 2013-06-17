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
    qDebug() << filePath;
//    QSettings setting(filePath, QSettings::IniFormat);
//    {
//        QString value = setting.value("files").toString();
//        qDebug() << value;
//        filterFiles_ = value.split(",").toSet();
//        qDebug() << "filter files:" << filterFiles_;
//    }

//    {
//        QString value = setting.value("dirs").toString();
//        qDebug() << value;
//        filterDirs_ = value.split(",").toSet();
//        qDebug() << "filter dirs:" << filterDirs_;
//    }
    QFile file(filePath);
    if(!file.open(QFile::ReadOnly))
    {
        qDebug() << "can't open " << filePath;
        qDebug() << file.errorString();
    }
    {
        QString files = file.readLine(1000);
        files = files.right(files.size() - 6);
        filterFiles_ = files.split(",").toSet();
        qDebug() << filterFiles_;
    }
    {
        QString dirs = file.readLine(1000);
        dirs = dirs.right(dirs.size() - 5);
        filterDirs_ = dirs.split(",").toSet();
        qDebug() << filterDirs_;
    }
    file.close();
}

QSet<QString> FilterData::getFilterFiles()
{
    return filterFiles_;
}

QSet<QString> FilterData::getFilterDirs()
{
    return filterDirs_;
}
