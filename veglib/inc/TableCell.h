#ifndef TABLECELL_H
#define TABLECELL_H

#include <string>

class TableCell
{
public:
    TableCell(int row, int col, const std::string &status);
    int row() const;
    int column() const;
    std::string status() const;

private:
    int m_row;
    int m_column;
    std::string m_status;
};

#endif // TABLECELL_H
