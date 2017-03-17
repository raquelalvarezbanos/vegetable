#include "MainWindowPresenter.h"
#include "IMainWindowView.h"

MainWindowPresenter::MainWindowPresenter(IMainWindowView *view)
    : m_view(view) {
}

void MainWindowPresenter::notify(IMainWindowPresenter::Flag flag) {

  switch (flag) {
  case (IMainWindowPresenter::PreviousYearRequested):
    showPreviousYear();
    break;
  case (IMainWindowPresenter::NextYearRequested):
    showNextYear();
    break;
  case (IMainWindowPresenter::StatisticsRequested):
    showStatistics();
    break;
  }
}

void MainWindowPresenter::showPreviousYear() {

  const std::string currYearStr = m_view->currentYear();
  int currYear = std::stoi(currYearStr) - 1;
  if (currYear < 0)
      m_view->showError("Only B.C is allowed", "Invalid year");
  else
      m_view->setCurrentYear(std::to_string(currYear));
}

void MainWindowPresenter::showNextYear() {

  const std::string currYearStr = m_view->currentYear();
  int currYear = std::stoi(currYearStr) + 1;
  m_view->setCurrentYear(std::to_string(currYear));
}

void MainWindowPresenter::showStatistics() { ; }
