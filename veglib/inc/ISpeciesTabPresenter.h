#ifndef ISPECIESTABPRESENTER_H
#define ISPECIESTABPRESENTER_H

class IMainWindowPresenter;

class ISpeciesTabPresenter {

public:
    virtual void acceptMainPresenter(IMainWindowPresenter *presenter) = 0;
};

#endif // ISPECIESTABPRESENTER_H

