#include <QApplication>

#include "QMainWindowView.h"

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);
  QMainWindowView mainWindowView;
  mainWindowView.show();
  
  return app.exec();
}
