#include "DataLoader.h"
#include <fstream>
#include <gtest/gtest.h>

TEST(DataLoaderTest, FileDoesNotExit) {
  DataLoader loader("wrong_path", "species_");

  EXPECT_EQ(loader.dataExists(2000), false);
}

TEST(DataLoaderTest, FileExists) {
  std::ofstream outfile("species_2000.txt");
  outfile.close();

  DataLoader loader("./", "species_");

  EXPECT_EQ(loader.dataExists(2000), true);
  EXPECT_EQ(std::remove("species_2000.txt"), 0);
}

TEST(DataLoaderTest, LoadBadHeaderFile) {
  std::ofstream outfile("species_2000.txt");

  outfile << "some text no number of rows" << std::endl;
  outfile.close();

  DataLoader loader("./", "species_");

  EXPECT_EQ(loader.dataExists(2000), true);
  ASSERT_THROW(loader.loadData(2000), std::runtime_error);
}

TEST(DataLoaderTest, LoadBadFileEnding) {
  std::ofstream outfile("species_2000.txt");

  outfile << "3\n";
  outfile << "0 10 P\n";
  outfile << "1 11 P\n";
  outfile << "2 12 P\n";
  outfile.close();

  DataLoader loader("./", "species_");

  EXPECT_EQ(loader.dataExists(2000), true);
  EXPECT_THROW(loader.loadData(2000), std::runtime_error);
  EXPECT_EQ(std::remove("species_2000.txt"), 0);
}

TEST(DataLoaderTest, LoadGoodFile) {
  std::ofstream outfile("species_2000.txt");

  outfile << "3\n";
  outfile << "0 10 P\n";
  outfile << "1 11 P\n";
  outfile << "2 12 P";
  outfile.close();

  DataLoader loader("./", "species_");

  EXPECT_EQ(loader.dataExists(2000), true);
  auto data = loader.loadData(2000);

  std::vector<std::vector<std::string>> expectedData(
      3, std::vector<std::string>(365, ""));
  expectedData[0][10] = "P";
  expectedData[1][11] = "P";
  expectedData[2][12] = "P";

  EXPECT_EQ(data, expectedData);
  EXPECT_EQ(std::remove("species_2000.txt"), 0);
}
