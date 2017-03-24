#include <QApplication>

#include "QMainWindowView.h"

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);
  app.setOrganizationName("Phorta");
  app.setApplicationName("VegeTable");

  QMainWindowView mainWindowView;
  mainWindowView.show();
  
  return app.exec();
}
