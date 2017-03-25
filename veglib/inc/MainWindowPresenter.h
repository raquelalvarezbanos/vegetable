#ifndef MAINWINDOWPRESENTER_H
#define MAINWINDOWPRESENTER_H

#include "IMainWindowPresenter.h"

class IMainWindowView;
class ITabPresenter;

class MainWindowPresenter: public IMainWindowPresenter {

public:
  MainWindowPresenter(IMainWindowView *view,
                      ITabPresenter *speciesPresenter);

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
  ITabPresenter *m_species;
};

#endif
