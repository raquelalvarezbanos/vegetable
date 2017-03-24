#include "TableCell.h"
#include <gtest/gtest.h>

TEST(TableCellTest, TestConstructor) {
  TableCell cell(5, 10, "P", "G");

  EXPECT_EQ(cell.row(), 5);
  EXPECT_EQ(cell.column(), 10);
  EXPECT_EQ(cell.status(), "P");
  EXPECT_EQ(cell.background(), "G");
}
