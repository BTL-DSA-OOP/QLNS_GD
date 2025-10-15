cmake_minimum_required(VERSION 3.16)

project(GD_NV LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt with the necessary components
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)

# Use the found package for linking
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

add_executable(GD_NV
  main.cpp
  GD_NVChung.ui
  GD_ChamCong.ui
  GD_NVChung.h
  GD_NVChung.cpp
)
# Link the executable to the Qt modules
target_link_libraries(GD_NV PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets)

include(GNUInstallDirs)
install(TARGETS GD_NV
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)