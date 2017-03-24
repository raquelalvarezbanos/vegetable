#include "QSpeciesTabView.h"
#include "SpeciesTabPresenter.h"

#include <QHeaderView>
#include <QInputDialog>
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
  m_table->verticalHeader()->setMovable(true);
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

  // Connections
  connect(addSpecies, SIGNAL(clicked()), this, SLOT(addSpeciesClicked()));
  connect(removeSpecies, SIGNAL(clicked()), this, SLOT(removeSpeciesClicked()));
}

ISpeciesTabPresenter *QSpeciesTabView::presenter() const {

  return m_presenter.get();
}

void QSpeciesTabView::addSpeciesClicked() {

  m_presenter->notify(ISpeciesTabPresenter::AddSpeciesRequested);
}

void QSpeciesTabView::removeSpeciesClicked() {

  m_presenter->notify(ISpeciesTabPresenter::RemoveSpeciesRequested);
}

std::string QSpeciesTabView::askUserNewRow(const std::string &title,
                                           const std::string &prompt,
                                           const std::string &defaultValue) {

  bool ok;
  QString text = QInputDialog::getText(
      this, QString::fromStdString(title), QString::fromStdString(prompt),
      QLineEdit::Normal, QString::fromStdString(defaultValue), &ok);
  if (ok)
    return text.toStdString();
  return "";
}

void QSpeciesTabView::appendRow(const std::string &rowName) {

  int lastRow = m_table->rowCount();
  m_table->insertRow(lastRow);
  m_table->setVerticalHeaderItem(
      lastRow, new QTableWidgetItem(QString::fromStdString(rowName)));
}

void QSpeciesTabView::removeRows() {

  auto rows = m_table->selectionModel()->selectedRows();

  std::set<int> sortedRows;

  for (const auto &row : rows) {
    sortedRows.insert(row.row());
  }

  for (auto it = sortedRows.rbegin(); it != sortedRows.rend(); ++it)
    m_table->removeRow(*it);
}
