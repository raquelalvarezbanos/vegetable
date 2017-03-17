set (CMAKE_CXX_STANDARD 11)

# Qt required
find_package(Qt4 REQUIRED)
include (${QT_USE_FILE})

include_directories(
  "${PROJECT_SOURCE_DIR}/veglib/inc")
include_directories(
  ${QT_QTCORE_INCLUDE_DIR}
  ${QT_QTGUI_INCLUDE_DIR}
  )

# vegetable app
add_executable(vegetable-app main.cpp)
target_link_libraries (vegetable-app
  vegetable
  ${QT_LIBRARIES})
