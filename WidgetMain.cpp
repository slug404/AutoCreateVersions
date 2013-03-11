#include "WidgetMain.h"
#include <QProcess>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QListView>
#include <QTreeView>
#include <QStringList>
#include "Versions/VersionCreater.h"

WidgetMain::WidgetMain(QWidget *parent)
    : QWidget(parent)
    , dirPath_("")
{
    setupUi(this);
    filterFolderPaths_.clear();
}

void WidgetMain::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type())
    {
        case QEvent::LanguageChange:
            retranslateUi(this);
            break;
        default:
            break;
    }
}

void WidgetMain::on_pushButtonOpenDir_clicked()
{

    dirPath_ = QFileDialog::getExistingDirectory(this);
    //dirPath_ = ".";
    lineEditSelect->setText(dirPath_);
}

void WidgetMain::on_pushButtonOk_clicked()
{
    VersionCreater version;
    //version.start(dirPath_, filterFolderPaths_);
    version.start(".", filterFolderPaths_);

    if(version.saveXml("server.xml"))
    {
        QMessageBox::information(this, tr("information"), tr("create update.xml success!"));
    }
    else
    {
        QMessageBox::warning(this, tr("warning"), tr("create update.xml fail!"));
    }

    //序列化存储file和path的map
    version.serializeFileNameAndFilePath("./serialize.dat");
}

void WidgetMain::on_pushButtonFilter_clicked()
{
    filterFolderPaths_.clear();
    QFileDialog fileDialog(this, "select folder ", "./");
    fileDialog.setFileMode(QFileDialog::DirectoryOnly);
    fileDialog.setOption(QFileDialog::DontUseNativeDialog, true);
    QListView *pListView = fileDialog.findChild<QListView*>("listView");
    if(NULL != pListView)
    {
        qDebug() << "find listview!";
        pListView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    }

    if(fileDialog.exec())
    {
        QStringList folderPaths = fileDialog.selectedFiles();
        if(folderPaths.isEmpty())
        {
            qDebug() << "folders is empty!";
            return;
        }
#ifdef WIN32
        foreach (QString tmp, folderPaths)
        {
            filterFolderPaths_ << tmp.replace("/", "\\");
        }
#else
        filterFolderPaths_ = folderPaths;
#endif
        qDebug() << filterFolderPaths_;
    }
    QString folders;
    foreach (QString folder, filterFolderPaths_)
    {
        folders += folder + "\n";
    }
    textEditFilter->setText(folders);
}
