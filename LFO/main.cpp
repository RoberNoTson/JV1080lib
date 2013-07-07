#include <QtGui/QApplication>
#include "lfo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LFO w;
    w.show();
    return a.exec();
}
