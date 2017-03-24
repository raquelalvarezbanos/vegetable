#include "SpeciesTabPresenter.h"
#include "IMainWindowPresenter.h"
#include "ISpeciesTabView.h"

#include <QFile>

SpeciesTabPresenter::SpeciesTabPresenter(ISpeciesTabView *view)
    : m_view(view) {}

void SpeciesTabPresenter::acceptMainPresenter(IMainWindowPresenter *presenter) {

  m_presenter = presenter;

  const std::string path = m_presenter->pathToData();
  const int year = m_presenter->currentYear();

  if (m_loader.dataExists(path, year))
    ;
  // QFile file("data/species/" + year + ".txt");
}

void SpeciesTabPresenter::notify(ISpeciesTabPresenter::Flag flag) {

  switch (flag) {
  case (ISpeciesTabPresenter::AddSpeciesRequested):
    addSpecies();
    break;
  case (ISpeciesTabPresenter::RemoveSpeciesRequested):
    removeSpecies();
    break;
  }
}

void SpeciesTabPresenter::addSpecies() {

  const std::string name = m_view->askUserNewRow(
      "New Species", "Name of new species", "New species");

  m_view->appendRow(name);
}

void SpeciesTabPresenter::removeSpecies() {

  m_view->removeRows();
}
