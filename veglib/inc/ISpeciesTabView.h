#ifndef ISPECIESTABVIEW_H
#define ISPECIESTABVIEW_H

#include <string>
#include <vector>

class ISpeciesTabView {

public:
  virtual ~ISpeciesTabView(){};

  virtual std::string askUserNewRow(const std::string &title,
                                    const std::string &prompt,
                                    const std::string &defaultValue) = 0;

  virtual void appendRow(const std::string &rowName) = 0;

  virtual void removeRows() = 0;

  virtual void clearTable() = 0;

  virtual void
  resizeTable(int nrows,
              const std::vector<std::string> &verticalHeaderData) = 0;

  virtual void setCell(int row, int col, const std::string &value) = 0;

  virtual bool varietyExists(const std::string &name, int &startDay,
                             int &startMonth, int &endDay, int &endMonth) = 0;
};

#endif // ISPECIESTABVIEW_H
