#include "MainWindowPresenter.h"
#include "IMainWindowView.h"
#include "ISpeciesTabPresenter.h"

MainWindowPresenter::MainWindowPresenter(IMainWindowView *view,
                                         ISpeciesTabPresenter *speciesPresenter)
    : m_view(view), m_speciesPresenter(speciesPresenter) {

    m_speciesPresenter->acceptMainPresenter(this);
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
  else{
      m_view->setCurrentYear(std::to_string(currYear));
      m_speciesPresenter->notify(ISpeciesTabPresenter::CurrentYearChanged);
  }
}

void MainWindowPresenter::showNextYear() {

  const std::string currYearStr = m_view->currentYear();
  int currYear = std::stoi(currYearStr) + 1;
  m_view->setCurrentYear(std::to_string(currYear));
  m_speciesPresenter->notify(ISpeciesTabPresenter::CurrentYearChanged);
}

void MainWindowPresenter::showStatistics() { ; }


int MainWindowPresenter::currentYear() const {

    return std::atoi(m_view->currentYear().c_str());
}

std::string MainWindowPresenter::pathToData() const {

    return m_view->pathToData();
}
