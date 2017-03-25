#include "QMainWindowView.h"
#include "QSettingsView.h"
#include "QSpeciesTabView.h"
#include "MainWindowPresenter.h"

#include <string>

#include <QDate>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QTabWidget>
#include <QSettings>
#include <QSplitter>
#include <QString>
#include <QVBoxLayout>

QMainWindowView::QMainWindowView(QWidget *parent)
    : QWidget(parent)
{
  setWindowTitle(tr("VegeTable"));
  resize(600, 300);

  // The tab presenters
  m_speciesPresenter.reset(new SpeciesTabPresenter());

  // The tabs
  QTabWidget *tabWidget = new QTabWidget;
  QSpeciesTabView *speciesView = new QSpeciesTabView(m_speciesPresenter.get());
  tabWidget->addTab(speciesView, tr("Species"));

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
  // Settings
  QPushButton *settingsButton = new QPushButton(tr("Settings"));
  // Save
  QPushButton *saveButton = new QPushButton(tr("Save"));

  // Horizontal layout
  QHBoxLayout *horizontalLayout = new QHBoxLayout();
  horizontalLayout->addWidget(previousYearButton);
  horizontalLayout->addWidget(m_yearLabel);
  horizontalLayout->addWidget(nextYearButton);
  horizontalLayout->addWidget(statisticsButton);
  horizontalLayout->addWidget(splitter);
  horizontalLayout->addWidget(settingsButton);
  horizontalLayout->addWidget(saveButton);

  // Vertical layout
  QVBoxLayout *verticalLayout = new QVBoxLayout(this);
  verticalLayout->addWidget(tabWidget);
  verticalLayout->addLayout(horizontalLayout);

  // The main presenter
  m_presenter.reset(new MainWindowPresenter(this, m_speciesPresenter.get()));

  // Connections
  connect(previousYearButton, SIGNAL (clicked()),this, SLOT (previousYearClicked()));
  connect(nextYearButton, SIGNAL(clicked()), this, SLOT(nextYearClicked()));
  connect(statisticsButton, SIGNAL(clicked()), this, SLOT(statisticsClicked()));
  connect(settingsButton, SIGNAL(clicked()), this, SLOT(settingsClicked()));
  connect(saveButton, SIGNAL(clicked()), this, SLOT(saveClicked()));
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

void QMainWindowView::settingsClicked() {

    QSettingsView *settings = new QSettingsView(this);
    settings->exec();
}

void QMainWindowView::saveClicked() {}

std::string QMainWindowView::currentYear() const {

    return m_yearLabel->text().toStdString();
}

void QMainWindowView::setCurrentYear(const std::string &year) {

    m_yearLabel->setText(QString::fromStdString(year));
}

std::string QMainWindowView::pathToData() const {

    QSettings settings;
    return settings.value("dataSearchDirectory").toString().toStdString();
}

void QMainWindowView::showError(const std::string &prompt,
                                const std::string &title) {

    QMessageBox::critical(this,
                          QString::fromStdString(title),
                          QString::fromStdString(prompt),
                          QMessageBox::Ok,
                          QMessageBox::Ok);
}
