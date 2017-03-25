#include "DataLoader.h"
#include <fstream>
#include <gtest/gtest.h>

TEST(DataLoaderTest, FileDoesNotExit) {
  DataLoader loader("species_");

  EXPECT_EQ(loader.dataExists("./", 2000), false);
}

TEST(DataLoaderTest, FileExists) {
  std::ofstream outfile("species_2000.txt");
  outfile.close();

  DataLoader loader("species_");

  EXPECT_EQ(loader.dataExists("./", 2000), true);
  EXPECT_EQ(std::remove("species_2000.txt"), 0);
}

TEST(DataLoaderTest, LoadGoodFile) {
  std::ofstream outfile("species_2000.txt");

  outfile << "3\n";
  outfile << "tomatoes\n";
  outfile << "cucumber\n";
  outfile << "lettuce";
  outfile << "0 10 P\n";
  outfile << "1 11 P\n";
  outfile << "2 12 P\n";
  outfile.close();

  DataLoader loader("species_");

  EXPECT_EQ(loader.dataExists("./", 2000), true);

  int nrows;
  std::vector<std::string> names;
  std::vector<TableCell> data;
  loader.loadData("./", 2000, nrows, names, data);

  EXPECT_EQ(nrows, 3);

  EXPECT_EQ(names[0], "tomatoes");
  EXPECT_EQ(names[1], "cucumber");
  EXPECT_EQ(names[2], "lettuce");

  EXPECT_EQ(data[0].row(), 0);
  EXPECT_EQ(data[0].column(), 10);
  EXPECT_EQ(data[0].status(), "P");

  EXPECT_EQ(data[1].row(), 1);
  EXPECT_EQ(data[1].column(), 11);
  EXPECT_EQ(data[1].status(), "P");

  EXPECT_EQ(data[2].row(), 2);
  EXPECT_EQ(data[2].column(), 12);
  EXPECT_EQ(data[2].status(), "P");

  EXPECT_EQ(std::remove("species_2000.txt"), 0);
}
