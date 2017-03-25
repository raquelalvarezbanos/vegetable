#ifndef SPECIESTABPRESENTER_H
#define SPECIESTABPRESENTER_H

#include "ITabPresenter.h"
#include "ISpeciesPresenter.h"
#include "DataLoader.h"

class ISpeciesTabView;
class IMainWindowPresenter;

class SpeciesTabPresenter : public ISpeciesPresenter, public ITabPresenter
{
public:
    SpeciesTabPresenter();

    void acceptMainPresenter(IMainWindowPresenter *presenter) override;
    void acceptView(ISpeciesTabView *view) override;

    void notify(ISpeciesPresenter::Flag flag) override;
    void notify(ITabPresenter::Flag flag) override;

private:
    ISpeciesTabView *m_view;
    IMainWindowPresenter *m_presenter;
    DataLoader m_loader{"species_"};

private:
    void addSpecies();
    void removeSpecies();
    void currentYearChanged();
};

#endif // SPECIESTABPRESENTER_H
