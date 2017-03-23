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

  if (m_loader.dataExists(path, year));
  //QFile file("data/species/" + year + ".txt");
}
