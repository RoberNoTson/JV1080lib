// main.cpp for JVlib

#include	<QtGui/QApplication>
#include	"JVlibForm.h"

int main(int argc, char * argv[]) {
  QApplication app(argc, argv);
  
  app.setApplicationName("JVlib");
  JVlibForm jv;

  jv.show();
  return app.exec();
}
