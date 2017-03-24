set (CMAKE_CXX_STANDARD 11)
set (CMAKE_AUTOMOC ON)

# Qt required
find_package(Qt4 REQUIRED)
include (${QT_USE_FILE})

set (MOC_FILES
  inc/QMainWindowView.h
  inc/QSettingsView.h
  inc/QSpeciesTabView.h
  )

set (INC_FILES
  inc/DataLoader.h
  inc/IMainWindowPresenter.h
  inc/IMainWindowView.h
  inc/ISpeciesTabPresenter.h
  inc/ISpeciesTabView.h
  inc/MainWindowPresenter.h
  inc/SpeciesTabPresenter.h
  inc/TableCell.h
  )

set (SRC_FILES
  src/DataLoader.cpp
  src/MainWindowPresenter.cpp
  src/QMainWindowView.cpp
  src/QSettingsView.cpp
  src/QSpeciesTabView.cpp
  src/SpeciesTabPresenter.cpp
  src/TableCell.cpp
  )

include_directories(
  "${PROJECT_SOURCE_DIR}/veglib/inc")
include_directories(
  ${QT_QTCORE_INCLUDE_DIR}
  ${QT_QTGUI_INCLUDE_DIR}
  )

qt4_wrap_cpp (MOCCED_FILES ${MOC_FILES})

add_library(vegetable
  ${MOC_FILES}
  ${INC_FILES}
  ${SRC_FILES})
