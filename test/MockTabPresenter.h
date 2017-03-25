#include "gmock/gmock.h"
#include "ITabPresenter.h"

#include <string>

class MockTabPresenter: public ITabPresenter
{
public:
  void acceptMainPresenter(IMainWindowPresenter *presenter) override {}
  void notify(ITabPresenter::Flag flag) override {}
};
