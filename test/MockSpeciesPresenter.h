#include "gmock/gmock.h"
#include "ISpeciesPresenter.h"

#include <string>

class MockSpeciesPresenter: public ISpeciesPresenter
{
public:
  void acceptMainPresenter(IMainWindowPresenter *presenter) override {}
  void notify(ISpeciesPresenter::Flag flag) override {}
};
