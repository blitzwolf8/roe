cmake_minimum_required(VERSION 3.14)

project(roe LANGUAGES CXX)
set(ROE_VERSION 1.0.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH $ENV{QTDIR})

find_package(Qt6 6.2 COMPONENTS Core Quick Gui Widgets REQUIRED)
add_subdirectory(roe)

option(ROE_BUILD_TESTS "Build all roe's tests" OFF)
mark_as_advanced(ROE_BUILD_TESTS)

if(ROE_BUILD_TESTS)
  enable_testing()
  find_package(GTest REQUIRED)
  add_subdirectory(tests)
endif()