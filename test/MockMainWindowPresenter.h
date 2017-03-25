#include "gmock/gmock.h"
#include "IMainWindowPresenter.h"

#include <string>

class MockMainWindowPresenter: public IMainWindowPresenter
{
public:

    MOCK_CONST_METHOD0(currentYear, int());
    MOCK_CONST_METHOD0(pathToData, std::string());

    void notify(IMainWindowPresenter::Flag flag) override {};
};
