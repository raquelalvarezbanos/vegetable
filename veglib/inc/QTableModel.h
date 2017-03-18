#ifndef QTABLEMODEL_H
#define QTABLEMODEL_H

#include <QAbstractTableModel>
#include <QVariant>

#include <string>
#include <vector>

class QTableModel : public QAbstractTableModel {
public:
  QTableModel(const std::vector<std::vector<std::string>> &data =
                  std::vector<std::vector<std::string>>());

  int rowCount(const QModelIndex & /*parent*/) const override;
  int columnCount(const QModelIndex & /*parent*/) const override;
  QVariant data(const QModelIndex &index, int role) const override;
  QVariant headerData(int section, Qt::Orientation orientation,
                      int role) const override;

private:
  void initHeaderData();

  std::vector<std::vector<std::string>> m_data;
  std::vector<std::string> m_headerData;
  std::vector<std::string> m_rowData;
  const int m_daysPerYear = 365;
};

#endif // QTABLEMODEL_H
