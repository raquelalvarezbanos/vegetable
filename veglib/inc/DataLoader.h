#ifndef DATALOADER_H
#define DATALOADER_H

#include "TableCell.h"

#include <string>
#include <vector>

class DataLoader {
public:
  DataLoader(const std::string &prefix);

  // Check if file exists in directory
  bool dataExists(const std::string &path, int year);
  // Return the number of rows
  int numberOfRows(const std::string &path, int year);
  // Load data from file
  std::vector<TableCell> loadData(const std::string &path, int year,
                                  int &nrows);

private:
  std::string m_prefix;
  const int m_daysPerYear = 365;
};

#endif // DATALOADER_H
