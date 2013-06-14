#ifndef FILTERDATA_H
#define FILTERDATA_H

#include <QString>
#include <QSet>

/**
 * @brief 过滤用到的数据
 */
class FilterData
{
public:
    FilterData();
    ~FilterData();

    void setFilePath(const QString &filePath);
    QSet<QString> getFilterFiles();
    QSet<QString> getFilterDirs();

private:
    FilterData(const FilterData &other);
    FilterData & operator = (const FilterData &other);

private:
    QSet<QString> filterFiles_;
    QSet<QString> filterDirs_;
};

#endif // FILTERDATA_H
