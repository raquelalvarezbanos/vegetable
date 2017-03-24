#include "DataLoader.h"
#include <fstream>

#include <boost/algorithm/string.hpp>

DataLoader::DataLoader(const std::string &prefix) : m_prefix(prefix) {}

bool DataLoader::dataExists(const std::string &path, int year) {

  std::ifstream file(path + m_prefix + std::to_string(year) + ".txt");
  if (file.is_open()) {
    file.close();
    return true;
  }

  else
    return false;
}

std::vector<TableCell> DataLoader::loadData(const std::string &path, int year,
                                            int &nrows) {

  const std::string fileName = path + m_prefix + std::to_string(year) + ".txt";
  std::ifstream file(fileName);

  std::vector<TableCell> data;

  if (file.is_open()) {
    std::string line;

    // Discard first line
    std::getline(file, line);
    nrows = std::stoi(line.c_str());
    if (nrows == 0)
      throw std::runtime_error("Error parsing " + fileName +
                               ". Invalid format");

    // Following lines are expected to be sets of:
    // row, column, status, (background)

    while (std::getline(file, line)) {

      std::vector<std::string> values;
      boost::algorithm::split(values, line, boost::is_any_of(" "));

      if (values.size() < 3)
        throw std::runtime_error("Error parsing " + fileName +
                                 ". File must have at least three columns\n");

      int row = std::atoi(values[0].c_str());
      if (row >= nrows)
        throw std::runtime_error("Error parsing " + fileName +
                                 ". More rows than expected");

      int col = std::atoi(values[1].c_str());
      if (col >= m_daysPerYear)
        throw std::runtime_error("Error parsing " + fileName +
                                 ". More columns than expected");

      std::string status = values[2];
      if (status == "")
        throw std::runtime_error("Error parsing " + fileName +
                                 ". Status cannot be empty");

      std::string bkg;
      if (values.size() > 3){
          bkg = values[3];
      }

      data.push_back(TableCell(row, col, status, bkg));
    }
    file.close();
  }

  return data;
}
