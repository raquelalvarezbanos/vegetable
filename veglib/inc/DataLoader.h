#ifndef DATALOADER_H
#define DATALOADER_H

#include "TableCell.h"

#include <vector>
#include <string>

class DataLoader {
public:
  DataLoader(const std::string &prefix);

  // Check if file exists in directory
  bool dataExists(const std::string &path, int year);
  // Load data from file
  void loadData(const std::string &path,
                int year,
                int &nrows,
                std::vector<std::string> &speciesNames,
                std::vector<TableCell> &nonEmptyCells);

private:
  std::string m_prefix;
  const int m_daysPerYear = 365;
};

#endif // DATALOADER_H
