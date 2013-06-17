#include "Singleton.h"

QSharedPointer<FilterData> Singleton::pFilterData_;

QSharedPointer<FilterData> &Singleton::Instance(const QString &filePath)
{
    if(NULL == pFilterData_)
    {
        pFilterData_ = QSharedPointer<FilterData>(new FilterData());
        pFilterData_->setFilePath(filePath);
    }

    return pFilterData_;
}

