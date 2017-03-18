#include "DataLoader.h"
#include <fstream>

DataLoader::DataLoader(const std::string &fullPath, const std::string &prefix)
    : m_path(fullPath), m_prefix(prefix) {}

bool DataLoader::dataExists(int year) {

  std::ifstream file(m_path + m_prefix + std::to_string(year) + ".txt");
  if (file.is_open()) {
    file.close();
    return true;
  }

  else
    return false;
}

std::vector<std::vector<std::string>> DataLoader::loadData(int year) {

  const std::string fileName =
      m_path + m_prefix + std::to_string(year) + ".txt";
  std::ifstream file(fileName);

  if (file.is_open()) {
    std::string line;

    // First line is a single number indicating number of rows
    int nrows;
    file >> nrows;
    if (nrows == 0)
      throw std::runtime_error(
          "Error reading " + fileName +
          ". Could not determine number of rows in the table");

    std::vector<std::vector<std::string>> data(
        nrows, std::vector<std::string>(m_daysPerYear, std::string()));

    // Following lines are expected to be sets of three elements:
    // row, column, status

    while (std::getline(file, line)) {

      int row;
      int col;
      std::string status;
      file >> row >> col >> status;

      if (row >= nrows)
        throw std::runtime_error("Error parsing " + fileName +
                                 ". Invalid format");

      if (col >= m_daysPerYear)
        throw std::runtime_error("Error parsing " + fileName +
                                 ". Invalid format");

      if (status == std::string())
          throw std::runtime_error("Error parsing " + fileName +
                                   ". Invalid format");

      data[row][col] = status;
    }
    file.close();

    return data;
  } else
    return std::vector<std::vector<std::string>>();
}
