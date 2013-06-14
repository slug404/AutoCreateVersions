#ifndef VERSIONCREATER_H
#define VERSIONCREATER_H

#include "VersionBase.h"
#include <QMap>
#include "dptr.h"

class VersionCreaterPrivate;
class QHostAddress;

class VersionCreater : public VersionBase
{
    DPTR_DECLARE_PRIVATE(VersionCreater);
public:
    VersionCreater();
    virtual ~VersionCreater();
    bool serializeFileNameAndFilePath(const QString &savePath);

protected:
    VersionCreater(VersionCreaterPrivate &data);
    virtual void initDomTree();
    virtual void traveDomTree(const QString &parentDirPath, const QStringList &filterFolderPaths);
    QString & getLocalIpAddress() const;
    QString getHostIp();
    bool isLinkLocalAddress(QHostAddress addr);
    bool isLocalIp(QHostAddress addr);

private:
    QMap<QString, QString> map_name_filePath_;
};

#endif // VERSIONCREATER_H
