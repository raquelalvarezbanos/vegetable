#ifndef SPECIESTABPRESENTER_H
#define SPECIESTABPRESENTER_H

#include "ISpeciesTabPresenter.h"
#include "DataLoader.h"

class ISpeciesTabView;
class IMainWindowPresenter;
class QAbstractTableModel;

class SpeciesTabPresenter : public ISpeciesTabPresenter
{
public:
    SpeciesTabPresenter(ISpeciesTabView *view, QAbstractTableModel *model);

    void acceptMainPresenter(IMainWindowPresenter *presenter) override;

private:
    ISpeciesTabView *m_view;
    IMainWindowPresenter *m_presenter;
    QAbstractTableModel *m_model;
    DataLoader m_loader{"species_"};
};

#endif // SPECIESTABPRESENTER_H
