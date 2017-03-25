#ifndef QSPECIESTABVIEW_H
#define QSPECIESTABVIEW_H

#include "ISpeciesPresenter.h"
#include "ISpeciesTabView.h"

#include <memory>

#include <QWidget>

class QTableWidget;
class ISpeciesPresenter;

class QSpeciesTabView : public QWidget, public ISpeciesTabView {
  Q_OBJECT

public:
  QSpeciesTabView(ISpeciesPresenter *presenter, QWidget *parent = 0);

private:
  QTableWidget *m_table;
  ISpeciesPresenter *m_presenter;

private:
  std::string askUserNewRow(const std::string &title, const std::string &prompt,
                            const std::string &defaultValue) override;
  void appendRow(const std::string &rowName) override;

  void removeRows() override;

  void clearTable() override;

  void resizeTable(int nrows,
                   const std::vector<std::string> &verticalHeaderData) override;

  void setCell(int row, int col, const std::string &value) override;

private slots:
  void addSpeciesClicked();
  void removeSpeciesClicked();
};

#endif
