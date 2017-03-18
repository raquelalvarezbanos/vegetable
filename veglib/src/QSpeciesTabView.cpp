#include "QSpeciesTabView.h"
#include "QTableModel.h"
#include "SpeciesTabPresenter.h"

#include <QTableView>
#include <QVBoxLayout>

QSpeciesTabView::QSpeciesTabView(QWidget *parent)
  : QWidget(parent)
{
  
    QVBoxLayout *layout = new QVBoxLayout(this);

    m_tableView = new QTableView;
    layout->addWidget(m_tableView);

    m_model.reset(new QTableModel());
    m_presenter.reset(new SpeciesTabPresenter(this, m_model.get()));

    m_tableView->setModel(m_model.get());
}

ISpeciesTabPresenter * QSpeciesTabView::presenter() const {

    return m_presenter.get();
}
