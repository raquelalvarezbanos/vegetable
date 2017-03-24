#include "gmock/gmock.h"
#include "ISpeciesTabPresenter.h"

#include <string>

class MockSpeciesTabPresenter: public ISpeciesTabPresenter
{
public:
  void acceptMainPresenter(IMainWindowPresenter *presenter) override {}
  void notify(ISpeciesTabPresenter::Flag flag) override {}
};
