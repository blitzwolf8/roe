cmake_minimum_required(VERSION 3.14)

project(roe)
set(ROE_VERSION 1.0.0)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "/opt/Qt/6.2.2/gcc_64")

set(Qt6Core_DIR "/opt/Qt/6.2.2/gcc_64/lib/cmake/Qt6Core")
set(Qt6_DIR "/opt/Qt/6.2.2/gcc_64/lib/cmake/Qt6")
set(QT_QMAKE_EXECUTABLE "/opt/Qt/6.2.2/gcc_64/bin/qmake")


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(roe)