#include "SpeciesTabPresenter.h"
#include "MockMainWindowPresenter.h"
#include "MockSpeciesTabView.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <fstream>

using ::testing::Return;
using ::testing::Mock;
using ::testing::_;

TEST(SpeciesTabPresenterTest, AcceptMainPresenter) {

  MockSpeciesTabView view;
  MockMainWindowPresenter mainPresenter;
  SpeciesTabPresenter presenter;

  presenter.acceptView(&view);

  EXPECT_CALL(mainPresenter, pathToData()).Times(1).WillOnce(Return("./"));
  EXPECT_CALL(mainPresenter, currentYear()).Times(1).WillOnce(Return(2017));
  EXPECT_CALL(view, clearTable()).Times(1);
  presenter.acceptMainPresenter(&mainPresenter);

  Mock::VerifyAndClearExpectations(&view);
  Mock::VerifyAndClearExpectations(&mainPresenter);
}

TEST(SpeciesTabPresenterTest, AcceptMainPresenterExistingData) {

  std::ofstream outfile("species_2017.txt");
  outfile << "3\n";
  outfile << "tomatoes\n";
  outfile << "cucumber\n";
  outfile << "lettuce\n";
  outfile << "0 10 P\n";
  outfile << "1 11 P\n";
  outfile << "2 12 P\n";
  outfile.close();

  MockSpeciesTabView view;
  MockMainWindowPresenter mainPresenter;
  SpeciesTabPresenter presenter;

  presenter.acceptView(&view);

  EXPECT_CALL(mainPresenter, pathToData()).Times(1).WillOnce(Return("./"));
  EXPECT_CALL(mainPresenter, currentYear()).Times(1).WillOnce(Return(2017));
  EXPECT_CALL(view,
              resizeTable(3, std::vector<std::string>{"tomatoes", "cucumber",
                                                      "lettuce"}))
      .Times(1);
  EXPECT_CALL(view, setCell(0, 10, "P")).Times(1);
  EXPECT_CALL(view, setCell(1, 11, "P")).Times(1);
  EXPECT_CALL(view, setCell(2, 12, "P")).Times(1);
  presenter.acceptMainPresenter(&mainPresenter);

  Mock::VerifyAndClearExpectations(&view);
  Mock::VerifyAndClearExpectations(&mainPresenter);

  EXPECT_EQ(std::remove("species_2017.txt"), 0);
}

TEST(SpeciesTabPresenterTest, AddSpecies) {
  MockSpeciesTabView view;
  SpeciesTabPresenter presenter;
  presenter.acceptView(&view);

  EXPECT_CALL(
      view, askUserNewRow("New Species", "Name of new species", "New species"))
      .Times(1)
      .WillOnce(Return("lettuce"));
  EXPECT_CALL(view, appendRow("lettuce")).Times(1);
  presenter.notify(ISpeciesPresenter::AddSpeciesRequested);

  Mock::VerifyAndClearExpectations(&view);
}

TEST(SpeciesTabPresenterTest, RemoveSpecies) {
  MockSpeciesTabView view;
  SpeciesTabPresenter presenter;
  presenter.acceptView(&view);

  EXPECT_CALL(view, removeRows()).Times(1);
  presenter.notify(ISpeciesPresenter::RemoveSpeciesRequested);

  Mock::VerifyAndClearExpectations(&view);
}
