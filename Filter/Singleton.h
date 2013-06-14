#ifndef SINGLETON_H
#define SINGLETON_H

#include <QObject>
#include <QSharedPointer>
#include <QString>
#include "FilterData.h"

/**
 * @brief 创建过滤数据的单例
 */
class Singleton
{
public:
    static QSharedPointer<FilterData> &Instance(const QString &filePath);

private:
    Singleton();
    Singleton(const Singleton &other);
    Singleton & operator = (const Singleton &other);

private:
    static QSharedPointer<FilterData> pFilterData_;
};

#endif // SINGLETON_H
