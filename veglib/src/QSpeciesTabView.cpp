#include "QSpeciesTabView.h"
#include "SpeciesTabPresenter.h"

#include <QPushButton>
#include <QSplitter>
#include <QTableWidget>
#include <QVBoxLayout>

QSpeciesTabView::QSpeciesTabView(QWidget *parent) : QWidget(parent) {

  QVBoxLayout *vlayout = new QVBoxLayout(this);
  QHBoxLayout *hlayout = new QHBoxLayout;

  QPushButton *addSpecies = new QPushButton(" + ");
  QPushButton *removeSpecies = new QPushButton(" - ");
  QSplitter *splitter = new QSplitter(Qt::Horizontal);
  hlayout->addWidget(addSpecies);
  hlayout->addWidget(removeSpecies);
  hlayout->addWidget(splitter);

  m_table = new QTableWidget;
  m_table->setColumnCount(365);
  QList<QString> header;
  for (size_t i = 1; i < 32; i++)
    header << QString::fromStdString(std::to_string(i) + " Jan");
  for (size_t i = 1; i < 29; i++)
    header << QString::fromStdString(std::to_string(i) + " Feb");
  for (size_t i = 1; i < 32; i++)
    header << QString::fromStdString(std::to_string(i) + " Mar");
  for (size_t i = 1; i < 31; i++)
    header << QString::fromStdString(std::to_string(i) + " Apr");
  for (size_t i = 1; i < 32; i++)
    header << QString::fromStdString(std::to_string(i) + " May");
  for (size_t i = 1; i < 31; i++)
    header << QString::fromStdString(std::to_string(i) + " Jun");
  for (size_t i = 1; i < 32; i++)
    header << QString::fromStdString(std::to_string(i) + " Jul");
  for (size_t i = 1; i < 32; i++)
    header << QString::fromStdString(std::to_string(i) + " Aug");
  for (size_t i = 1; i < 31; i++)
    header << QString::fromStdString(std::to_string(i) + " Sep");
  for (size_t i = 1; i < 32; i++)
    header << QString::fromStdString(std::to_string(i) + " Oct");
  for (size_t i = 1; i < 31; i++)
    header << QString::fromStdString(std::to_string(i) + " Nov");
  for (size_t i = 1; i < 32; i++)
    header << QString::fromStdString(std::to_string(i) + " Dec");
  m_table->setHorizontalHeaderLabels(header);


  vlayout->addLayout(hlayout);
  vlayout->addWidget(m_table);

  m_presenter.reset(new SpeciesTabPresenter(this));
}

ISpeciesTabPresenter *QSpeciesTabView::presenter() const {

  return m_presenter.get();
}
