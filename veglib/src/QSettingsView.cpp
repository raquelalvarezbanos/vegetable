#include "QSettingsView.h"

#include <QFileDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSettings>
#include <QString>

QSettingsView::QSettingsView(QWidget *parent) : QDialog(parent) {

  setWindowTitle("Data search directory");
  resize(800, 50);

  QSettings settings;
  auto lastDir = settings.value("dataSearchDirectory").toString();

  QLabel *label = new QLabel("Data search directory");
  QPushButton *browse = new QPushButton("Browse");
  QPushButton *ok = new QPushButton("OK");
  m_edit = new QLineEdit();
  m_edit->setText(lastDir);

  QHBoxLayout *layout = new QHBoxLayout(this);
  layout->addWidget(label);
  layout->addWidget(m_edit);
  layout->addWidget(browse);
  layout->addWidget(ok);

  connect(browse, SIGNAL(clicked()), this, SLOT(browseClicked()));
  connect(ok, SIGNAL(clicked()), this, SLOT(okClicked()));
}

void QSettingsView::browseClicked() {

    QString dir =
            QFileDialog::getExistingDirectory(this, "Select directory", "./");

    QSettings settings;
    settings.setValue("dataSearchDirectory", dir + "/");

    m_edit->setText(dir);
}

void QSettingsView::okClicked() {

    close();
}
