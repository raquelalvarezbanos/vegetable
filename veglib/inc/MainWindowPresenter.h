#ifndef MAINWINDOWPRESENTER_H
#define MAINWINDOWPRESENTER_H

#include "IMainWindowPresenter.h"

class IMainWindowView;

class MainWindowPresenter: public IMainWindowPresenter {

public:
  MainWindowPresenter(IMainWindowView *view);

  // To be used by the view
  void notify(IMainWindowPresenter::Flag flag) override;

private:
  void showPreviousYear();
  void showNextYear();
  void showStatistics();

  IMainWindowView *m_view;
};

#endif
