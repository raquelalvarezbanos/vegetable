#ifndef SPECIESTABPRESENTER_H
#define SPECIESTABPRESENTER_H

#include "ISpeciesTabPresenter.h"
#include "DataLoader.h"

class ISpeciesTabView;
class IMainWindowPresenter;

class SpeciesTabPresenter : public ISpeciesTabPresenter
{
public:
    SpeciesTabPresenter(ISpeciesTabView *view);

    void acceptMainPresenter(IMainWindowPresenter *presenter) override;

private:
    ISpeciesTabView *m_view;
    IMainWindowPresenter *m_presenter;
    DataLoader m_loader{"species_"};
};

#endif // SPECIESTABPRESENTER_H
