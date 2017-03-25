#ifndef ISPECIESPRESENTER_H
#define ISPECIESPRESENTER_H

class IMainWindowPresenter;
class ISpeciesTabView;

class ISpeciesPresenter {

public:
  enum Flag { AddSpeciesRequested, RemoveSpeciesRequested};

  virtual void notify(ISpeciesPresenter::Flag flag) = 0;

  virtual void acceptView(ISpeciesTabView *view) = 0;
};

#endif // ISPECIESPRESENTER_H
