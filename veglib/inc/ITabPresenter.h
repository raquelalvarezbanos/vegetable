#ifndef ITABPRESENTER_H
#define ITABPRESENTER_H

class IMainWindowPresenter;

class ITabPresenter {

public:
  enum Flag { CurrentYearChanged };

  virtual void notify(ITabPresenter::Flag flag) = 0;

  virtual void acceptMainPresenter(IMainWindowPresenter *presenter) = 0;
};

#endif // ITABPRESENTER_H
