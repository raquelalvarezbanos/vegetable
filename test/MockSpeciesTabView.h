#include "gmock/gmock.h"
#include "ISpeciesTabView.h"

#include <string>

class MockSpeciesTabView: public ISpeciesTabView
{
public:
    MOCK_METHOD3(askUserNewRow, std::string(const std::string &,
                                            const std::string &,
                                            const std::string &));
    MOCK_METHOD1(appendRow, void(const std::string &));
    MOCK_METHOD0(removeRows, void());
    MOCK_METHOD0(clearTable, void());
    MOCK_METHOD2(resizeTable, void(int, const std::vector<std::string> &));
    MOCK_METHOD3(setCell, void(int, int, const std::string &));
};
