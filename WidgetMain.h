#ifndef WIDGETMAIN_H
#define WIDGETMAIN_H

#include "ui_WidgetMain.h"

class WidgetMain : public QWidget, private Ui::WidgetMain
{
    Q_OBJECT

public:
    explicit WidgetMain(QWidget *parent = 0);

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_pushButtonOpenDir_clicked();

    void on_pushButtonOk_clicked();

    void on_pushButtonFilter_clicked();

private:
    QString dirPath_;
    QStringList filterFolderPaths_;
};

#endif // WIDGETMAIN_H
