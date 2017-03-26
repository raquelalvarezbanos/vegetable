#ifndef YEAR_H
#define YEAR_H

#include <vector>

class Year {
public:
  Year();

  int totalDays() const;
  int daysInMonth(int month) const;
  int dayNumber(int day, int month) const;

private:
  int m_days{365};
  std::vector<int> m_daysInMonth{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};

#endif // YEAR_H
