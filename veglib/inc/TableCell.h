#ifndef TABLECELL_H
#define TABLECELL_H

#include <string>

class TableCell
{
public:
    TableCell(int row, int col, const std::string &status, const std::string &bkg = "");
    int row() const;
    int column() const;
    std::string status() const;
    std::string background() const;

private:
    int m_row;
    int m_column;
    std::string m_status;
    std::string m_background;
};

#endif // TABLECELL_H
