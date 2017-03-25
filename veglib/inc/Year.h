#ifndef YEAR_H
#define YEAR_H

#include <map>

class Year {
public:
  Year();

  int totalDays() const;
  int daysInMonth(int month) const;
  int dayNumber(int day, int month) const;

private:
  int m_days{365};
  std::map<int, int> m_daysInMonth{{1, 31}, {2, 28},  {3, 31},  {4, 30},
                                   {5, 31}, {6, 30},  {7, 31},  {8, 31},
                                   {9, 30}, {10, 31}, {11, 30}, {12, 31}};
};

#endif // YEAR_H
