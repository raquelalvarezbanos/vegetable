#ifndef QSPECIESTABVIEW_H
#define QSPECIESTABVIEW_H

#include "ISpeciesTabPresenter.h"
#include "ISpeciesTabView.h"

#include <memory>

#include <QWidget>

class QTableWidget;
class ISpeciesTabPresenter;

class QSpeciesTabView : public QWidget, public ISpeciesTabView {
  Q_OBJECT

public:
  QSpeciesTabView(QWidget *parent = 0);
  ISpeciesTabPresenter *presenter() const;

private:
  QTableWidget *m_table;
  std::unique_ptr<ISpeciesTabPresenter> m_presenter;

private:
  std::string askUserNewRow(const std::string &title,
                            const std::string &prompt,
                            const std::string &defaultValue) override;
  void appendRow(const std::string &rowName) override;

  void removeRows() override;

private slots:
  void addSpeciesClicked();
  void removeSpeciesClicked();
};

#endif
