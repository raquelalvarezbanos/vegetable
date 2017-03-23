#ifndef QSETTINGSVIEW_H
#define QSETTINGSVIEW_H

#include <QDialog>
#include <QLineEdit>

class QSettingsView : public QDialog {
  Q_OBJECT

public:
  QSettingsView(QWidget *parent = 0);

private:
  QLineEdit *m_edit;

private slots:
  void browseClicked();
  void okClicked();
};

#endif // QSETTINGSVIEW_H
