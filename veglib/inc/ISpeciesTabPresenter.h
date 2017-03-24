#ifndef ISPECIESTABPRESENTER_H
#define ISPECIESTABPRESENTER_H

class IMainWindowPresenter;

class ISpeciesTabPresenter {

public:

    enum Flag { AddSpeciesRequested,
                RemoveSpeciesRequested };

    // To be used by the view
    virtual void notify(ISpeciesTabPresenter::Flag flag) = 0;

    virtual void acceptMainPresenter(IMainWindowPresenter *presenter) = 0;
};

#endif // ISPECIESTABPRESENTER_H

