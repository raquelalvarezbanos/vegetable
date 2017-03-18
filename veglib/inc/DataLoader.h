#ifndef DATALOADER_H
#define DATALOADER_H

#include <string>
#include <vector>

class DataLoader {
public:
  DataLoader(const std::string &prefix);

  // Check if file exists in directory
  bool dataExists(const std::string &path, int year);
  // Load data from file as a 2d vector
  std::vector<std::vector<std::string>> loadData(const std::string &path,
                                                 int year);

private:
  std::string m_prefix;
  const int m_daysPerYear = 365;
};

#endif // DATALOADER_H
