#ifndef MAINWINDOWPRESENTER_H
#define MAINWINDOWPRESENTER_H

#include "IMainWindowPresenter.h"

class IMainWindowView;
class ISpeciesTabPresenter;

class MainWindowPresenter: public IMainWindowPresenter {

public:
  MainWindowPresenter(IMainWindowView *view,
                      ISpeciesTabPresenter *speciesPresenter);

  // To be used by the view
  void notify(IMainWindowPresenter::Flag flag) override;
  // To be used by the tab presenters
  int currentYear() const override;
  std::string pathToData() const override;

private:
  void showPreviousYear();
  void showNextYear();
  void showStatistics();

  IMainWindowView *m_view;
  ISpeciesTabPresenter *m_speciesPresenter;
};

#endif
