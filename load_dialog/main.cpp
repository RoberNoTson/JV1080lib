#include <QtGui/QApplication>
#include "load_dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LOAD_DIALOG w;
    w.show();
    return a.exec();
}
