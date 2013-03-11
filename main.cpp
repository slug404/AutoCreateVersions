#include "WidgetMain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WidgetMain w;
    w.show();
    
    return a.exec();
}
