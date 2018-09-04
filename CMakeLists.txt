cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(qpclvisualizer)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# PCL
find_package(PCL REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# QT
find_package (Qt5 REQUIRED COMPONENTS  Core Gui Widgets)

# VTK
find_package (VTK REQUIRED)

# Add code
QT5_WRAP_CPP(qpclvisualizer_moc src/qpclvisualizer.h)
add_library(qpclvisualizer src/qpclvisualizer.cpp src/qpclvisualizer.h ${qpclvisualizer_moc})
target_link_libraries(qpclvisualizer Qt5::Core Qt5::Gui Qt5::Widgets ${PCL_LIBRARIES} ${VTK_LIBRARIES})
add_executable(pcl_visualizer src/pclviewer_main.cpp)
target_link_libraries(pcl_visualizer Qt5::Core Qt5::Gui Qt5::Widgets ${PCL_LIBRARIES} ${VTK_LIBRARIES} qpclvisualizer)
