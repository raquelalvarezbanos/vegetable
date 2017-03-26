#include "SpeciesTabPresenter.h"
#include "IMainWindowPresenter.h"
#include "ISpeciesTabView.h"
#include "Year.h"

SpeciesTabPresenter::SpeciesTabPresenter() {}

void SpeciesTabPresenter::acceptMainPresenter(IMainWindowPresenter *presenter) {

  m_presenter = presenter;

  currentYearChanged();
}

void SpeciesTabPresenter::acceptView(ISpeciesTabView *view) { m_view = view; }

void SpeciesTabPresenter::notify(ISpeciesPresenter::Flag flag) {

  switch (flag) {
  case (ISpeciesPresenter::AddSpeciesRequested):
    addSpecies();
    break;
  case (ISpeciesPresenter::RemoveSpeciesRequested):
    removeSpecies();
    break;
  }
}

void SpeciesTabPresenter::notify(ITabPresenter::Flag flag) {

  switch (flag) {
  case (ITabPresenter::CurrentYearChanged):
    currentYearChanged();
    break;
  }
}

void SpeciesTabPresenter::addSpecies() {

  const std::string name = m_view->askUserNewRow(
      "New Species",
      "Enter a name to label the new species. Example: 'lettuce 1'",
      "New species");

  m_view->appendRow(name);

  const std::string variety = m_view->askUserNewRow(
      "New species", "Enter the species variety. Example 'romain lettuce'", "");

  int startDay, endDay, startMonth, endMonth;
  if (m_view->varietyExists(variety, startDay, startMonth, endDay, endMonth)) {
      Year year;
      int startCell = year.dayNumber(startDay, startMonth);
      int endCell = year.dayNumber(endDay, endMonth);
      for (int i=0; i<endCell+1; i++){

      }
  }
  else {
    ;
  }
}

void SpeciesTabPresenter::removeSpecies() { m_view->removeRows(); }

void SpeciesTabPresenter::currentYearChanged() {

  const std::string path = m_presenter->pathToData();
  const int year = m_presenter->currentYear();

  if (m_loader.dataExists(path, year)) {
    int nrows;
    std::vector<std::string> names;
    std::vector<TableCell> data;
    m_loader.loadData(path, year, nrows, names, data);

    m_view->resizeTable(nrows, names);

    for (const auto &cell : data) {
      m_view->setCell(cell.row(), cell.column(), cell.status());
    }
  } else {
    m_view->clearTable();
  }
}
