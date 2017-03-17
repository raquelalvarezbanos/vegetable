#include "gmock/gmock.h"
#include "IMainWindowView.h"

#include <string>

class MockMainWindowView: public IMainWindowView
{
public:
  MOCK_CONST_METHOD0(currentYear, std::string());
  MOCK_METHOD1(setCurrentYear, void(const std::string &));
  MOCK_METHOD2(showError, void(const std::string &, const std::string &));
};
