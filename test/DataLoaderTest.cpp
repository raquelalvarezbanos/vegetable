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
  outfile << "0 10 P\n";
  outfile << "1 11 P\n";
  outfile << "2 12 P\n";
  outfile.close();

  DataLoader loader("species_");

  EXPECT_EQ(loader.dataExists("./", 2000), true);

  int nrows;
  auto data = loader.loadData("./", 2000, nrows);

  EXPECT_EQ(nrows, 3);

  EXPECT_EQ(data[0].row(), 0);
  EXPECT_EQ(data[0].column(), 10);
  EXPECT_EQ(data[0].status(), "P");
  EXPECT_EQ(data[0].background(), "");

  EXPECT_EQ(data[1].row(), 1);
  EXPECT_EQ(data[1].column(), 11);
  EXPECT_EQ(data[1].status(), "P");
  EXPECT_EQ(data[1].background(), "");

  EXPECT_EQ(data[2].row(), 2);
  EXPECT_EQ(data[2].column(), 12);
  EXPECT_EQ(data[2].status(), "P");
  EXPECT_EQ(data[2].background(), "");

  EXPECT_EQ(std::remove("species_2000.txt"), 0);
}

TEST(DataLoaderTest, LoadGoodFileFourColumns) {
  std::ofstream outfile("species_2000.txt");

  outfile << "3\n";
  outfile << "0 10 P B\n";
  outfile << "1 11 P B\n";
  outfile << "2 12 P B\n";
  outfile.close();

  DataLoader loader("species_");

  EXPECT_EQ(loader.dataExists("./", 2000), true);

  int nrows;
  auto data = loader.loadData("./", 2000, nrows);

  EXPECT_EQ(nrows, 3);

  EXPECT_EQ(data[0].row(), 0);
  EXPECT_EQ(data[0].column(), 10);
  EXPECT_EQ(data[0].status(), "P");
  EXPECT_EQ(data[0].background(), "B");

  EXPECT_EQ(data[1].row(), 1);
  EXPECT_EQ(data[1].column(), 11);
  EXPECT_EQ(data[1].status(), "P");
  EXPECT_EQ(data[1].background(), "B");

  EXPECT_EQ(data[2].row(), 2);
  EXPECT_EQ(data[2].column(), 12);
  EXPECT_EQ(data[2].status(), "P");
  EXPECT_EQ(data[2].background(), "B");

  EXPECT_EQ(std::remove("species_2000.txt"), 0);
}
