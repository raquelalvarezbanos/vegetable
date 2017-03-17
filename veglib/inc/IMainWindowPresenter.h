#ifndef IMAINWINDOWPRESENTER_H
#define IMAINWINDOWPRESENTER_H

#include <string>

class IMainWindowPresenter {
public:
  IMainWindowPresenter(){};
  virtual ~IMainWindowPresenter(){};

  enum Flag { PreviousYearRequested,
              NextYearRequested,
              StatisticsRequested };

  // To be used by the view
  virtual void notify(IMainWindowPresenter::Flag flag) = 0;
};
#endif
