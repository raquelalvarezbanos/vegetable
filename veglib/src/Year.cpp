#include "Year.h"

#include <stdexcept>

Year::Year() {}

int Year::totalDays() const { return m_days; }

int Year::daysInMonth(int month) const {

  if (month < 1 || month > 12)
    throw std::invalid_argument(
        "Month must be specified as a number ranging from 1 to 12.");

  return m_daysInMonth.at(month - 1);
}

int Year::dayNumber(int day, int month) const {

  if (day < 1 || day > daysInMonth(month))
    throw std::invalid_argument("Month " + std::to_string(month) +
                                " does not have " + std::to_string(day) +
                                " days");

  int sum = 0;
  for (int i = 0; i < month - 1; i++)
    sum += m_daysInMonth[i];
  sum += day;

  return sum;
}
