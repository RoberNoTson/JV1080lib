#include <QtGui/QApplication>
#include "patch_list.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PATCH_LIST w;
    w.show();
    return a.exec();
}
