#ifndef QSPECIESTABVIEW_H
#define QSPECIESTABVIEW_H

#include "ISpeciesTabView.h"
#include "ISpeciesTabPresenter.h"

#include <memory>

#include <QAbstractTableModel>
#include <QWidget>

class QTableView;
class ISpeciesTabPresenter;

class QSpeciesTabView : public QWidget, public ISpeciesTabView
{
    Q_OBJECT

public:
    QSpeciesTabView(QWidget *parent = 0);
    ISpeciesTabPresenter *presenter() const;

private:
    QTableView *m_tableView;
    std::unique_ptr<ISpeciesTabPresenter> m_presenter;
    std::shared_ptr<QAbstractTableModel> m_model;
};

#endif
