#include "TableCell.h"

TableCell::TableCell(int row, int col, const std::string &status)
    : m_row(row), m_column(col), m_status(status) {}

int TableCell::row() const {

    return m_row;
}

int TableCell::column() const {

    return m_column;
}

std::string TableCell::status() const {

    return m_status;
}
