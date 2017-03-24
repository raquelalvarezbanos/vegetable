#ifndef QMAINWINDOWVIEW_H
#define QMAINWINDOWVIEW_H

#include "IMainWindowView.h"
#include "IMainWindowPresenter.h"

#include <memory>
#include <QWidget>

class IMainWindowPresenter;
class QLabel;

class QMainWindowView : public QWidget, public IMainWindowView {
  Q_OBJECT

public:
  QMainWindowView(QWidget *parent = 0);

  // Returns current year
  std::string currentYear() const override;
  // Sets current year
  void setCurrentYear(const std::string &year) override;
  // Path to data
  std::string pathToData() const override;
  // Shows an error message
  void showError(const std::string &prompt,
                 const std::string &title);


private:
  // Label showing current year
  QLabel *m_yearLabel;
  // current year
  int m_year;
  // The presenter
  std::unique_ptr<IMainWindowPresenter> m_presenter;

private slots:
  void previousYearClicked();
  void nextYearClicked();
  void statisticsClicked();
  void settingsClicked();
  void saveClicked();
};

#endif
