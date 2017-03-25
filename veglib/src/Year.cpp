#include "Year.h"

Year::Year() {}

int Year::totalDays() const { return m_days; }

int Year::daysInMonth(int month) const { return m_daysInMonth.at(month); }

int Year::dayNumber(int day, int month) const {

  int sum = 0;
  for (int i = 1; i < month; i++)
    sum += m_daysInMonth.at(i);
  sum += day;

  return sum;
}
