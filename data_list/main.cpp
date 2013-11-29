#include <QtGui/QApplication>
#include "data_list.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DATA_LIST w;
    w.show();
    return a.exec();
}
