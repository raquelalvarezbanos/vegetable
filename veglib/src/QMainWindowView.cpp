#include "QMainWindowView.h"
#include "MainWindowPresenter.h"

#include <string>

#include <QDate>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QSplitter>
#include <QString>
#include <QVBoxLayout>

QMainWindowView::QMainWindowView(QWidget *parent)
    : QWidget(parent)
{
  setWindowTitle(tr("VegeTable"));
  resize(600, 300);

  // The year buttons
  QPushButton *previousYearButton = new QPushButton(tr(" < "));
  QPushButton *nextYearButton = new QPushButton(tr(" > "));
  QDate date;
  m_year = date.currentDate().year();
  m_yearLabel =
    new QLabel(QString::fromStdString(std::to_string(m_year)));

  // Splitter
  QSplitter *splitter = new QSplitter;
  splitter->setOrientation(Qt::Horizontal);
  
  // Statistics
  QPushButton *statisticsButton = new QPushButton(tr("Statistics"));

  // Horizontal layout
  QHBoxLayout *horizontalLayout = new QHBoxLayout(this);
  horizontalLayout->addWidget(previousYearButton);
  horizontalLayout->addWidget(m_yearLabel);
  horizontalLayout->addWidget(nextYearButton);
  horizontalLayout->addWidget(splitter);
  horizontalLayout->addWidget(statisticsButton);

  // The presenter
  m_presenter.reset(new MainWindowPresenter(this));

  // Connections
  connect(previousYearButton, SIGNAL (clicked()),this, SLOT (previousYearClicked()));
  connect(nextYearButton, SIGNAL(clicked()), this, SLOT(nextYearClicked()));
  connect(statisticsButton, SIGNAL(clicked()), this, SLOT(statisticsClicked()));
}

void QMainWindowView::previousYearClicked() {

    m_presenter->notify(IMainWindowPresenter::PreviousYearRequested);
}

void QMainWindowView::nextYearClicked() {

    m_presenter->notify(IMainWindowPresenter::NextYearRequested);
}

void QMainWindowView::statisticsClicked() {

    m_presenter->notify(IMainWindowPresenter::StatisticsRequested);
}

std::string QMainWindowView::currentYear() const {

    return m_yearLabel->text().toStdString();
}

void QMainWindowView::setCurrentYear(const std::string &year) {

    m_yearLabel->setText(QString::fromStdString(year));
}

void QMainWindowView::showError(const std::string &prompt,
                                const std::string &title) {

    QMessageBox::critical(this,
                          QString::fromStdString(title),
                          QString::fromStdString(prompt),
                          QMessageBox::Ok,
                          QMessageBox::Ok);
}
