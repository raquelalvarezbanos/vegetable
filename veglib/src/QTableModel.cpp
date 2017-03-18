#include "QTableModel.h"

QTableModel::QTableModel(const std::vector<std::vector<std::string>> &data) : m_data(data)
{
    initHeaderData();
}

int QTableModel::rowCount(const QModelIndex & /*parent*/) const {

    return static_cast<int>(m_data.size());
}

int QTableModel::columnCount(const QModelIndex & /*parent*/) const {

    return m_daysPerYear;
}

QVariant QTableModel::data(const QModelIndex &index, int role) const {

    if (role == Qt::DisplayRole)
        return QString::fromStdString(m_data.at(index.row()).at(index.column()));
    else
        return QVariant();
}

QVariant QTableModel::headerData(int section, Qt::Orientation orientation,
                    int role) const {

    if (role == Qt::DisplayRole && orientation == Qt::Horizontal){

        return QString::fromStdString(m_headerData[section]);
    }
    else if (role == Qt::DisplayRole && orientation == Qt::Vertical){

        return QVariant();
    }
    else if (role == Qt::EditRole && orientation == Qt::Vertical){

        return QVariant();
    }
    else {
        return QVariant();
    }
}

void QTableModel::initHeaderData() {

    m_headerData.resize(m_daysPerYear);
    int cont = 0;
    for (size_t i=1; i<32; i++)
        m_headerData[cont++] = std::to_string(i) + " Jan";
    for (size_t i=1; i<29; i++)
        m_headerData[cont++] = std::to_string(i) + " Feb";
    for (size_t i=1; i<32; i++)
        m_headerData[cont++] = std::to_string(i) + " Mar";
    for (size_t i=1; i<31; i++)
        m_headerData[cont++] = std::to_string(i) + " Apr";
    for (size_t i=1; i<32; i++)
        m_headerData[cont++] = std::to_string(i) + " May";
    for (size_t i=1; i<31; i++)
        m_headerData[cont++] = std::to_string(i) + " Jun";
    for (size_t i=1; i<32; i++)
        m_headerData[cont++] = std::to_string(i) + " Jul";
    for (size_t i=1; i<32; i++)
        m_headerData[cont++] = std::to_string(i) + " Aug";
    for (size_t i=1; i<31; i++)
        m_headerData[cont++] = std::to_string(i) + " Sep";
    for (size_t i=1; i<32; i++)
        m_headerData[cont++] = std::to_string(i) + " Oct";
    for (size_t i=1; i<31; i++)
        m_headerData[cont++] = std::to_string(i) + " Nov";
    for (size_t i=1; i<32; i++)
        m_headerData[cont++] = std::to_string(i) + " Dec";

}

