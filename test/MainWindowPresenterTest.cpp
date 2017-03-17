#include "MainWindowPresenter.h"
#include "MockMainWindowView.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::Return;
using ::testing::Mock;
using ::testing::_;

TEST(MainWindowPresenterTest, UninterestingNextYear) {
    MockMainWindowView view;
    MainWindowPresenter presenter(&view);

    EXPECT_CALL(view, currentYear()).Times(1).WillOnce(Return("2001"));
    EXPECT_CALL(view, setCurrentYear("2002"));
    presenter.notify(IMainWindowPresenter::NextYearRequested);

    Mock::VerifyAndClearExpectations(&view);
}

TEST(MainWindowPresenterTest, UninterestingPreviousYear) {
    MockMainWindowView view;
    MainWindowPresenter presenter(&view);

    EXPECT_CALL(view, currentYear()).Times(1).WillOnce(Return("2001"));
    EXPECT_CALL(view, setCurrentYear("2000"));
    presenter.notify(IMainWindowPresenter::PreviousYearRequested);

    Mock::VerifyAndClearExpectations(&view);
}

TEST(MainWindowPresenterTest, YearZero) {
    MockMainWindowView view;
    MainWindowPresenter presenter(&view);

    EXPECT_CALL(view, currentYear()).Times(1).WillOnce(Return("0"));
    EXPECT_CALL(view, setCurrentYear(_)).Times(0);
    EXPECT_CALL(view, showError(_,_)).Times(1);
    presenter.notify(IMainWindowPresenter::PreviousYearRequested);

    Mock::VerifyAndClearExpectations(&view);
}
