#ifndef QSPECIESTABVIEW_H
#define QSPECIESTABVIEW_H

#include "ISpeciesTabView.h"
#include "ISpeciesTabPresenter.h"

#include <memory>

#include <QWidget>

class QTableWidget;
class ISpeciesTabPresenter;

class QSpeciesTabView : public QWidget, public ISpeciesTabView
{
    Q_OBJECT

public:
    QSpeciesTabView(QWidget *parent = 0);
    ISpeciesTabPresenter *presenter() const;

private:
    QTableWidget *m_table;
    std::unique_ptr<ISpeciesTabPresenter> m_presenter;
};

#endif
