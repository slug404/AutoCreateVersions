#ifndef FILTER_H
#define FILTER_H

#include <QString>
/**
 * @brief 过滤工具类
 */
class Filter
{
public:
    static bool isFilterDir(const QString dirPath);
    static bool isFilterFiles(const QString filePath);
};

#endif // FILTER_H
