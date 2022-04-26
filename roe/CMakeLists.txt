cmake_minimum_required(VERSION 3.5)

project(roe VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(ROE_INCLUDE_DIR "${roe_SOURCE_DIR}/include")

include_directories(${ROE_INCLUDE_DIR})

set(PROJECT_SOURCES
    src/window.cc
    include/window.h
    src/document.cc
    include/document.h
    include/editor.h
    src/editor.cc
    include/tabwidget.h
    src/tabwidget.cc
    )

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=undefined -g -O3")
endif(CMAKE_BUILD_TYPE STREQUAL "Debug")


if(CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
endif(CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")

add_library(roeden ${PROJECT_SOURCES})

target_include_directories(roeden SYSTEM INTERFACE
    "$<BUILD_INTERFACE:${ROE_INCLUDE_DIR}>")
target_link_libraries(roeden PUBLIC Qt${QT_VERSION_MAJOR}::Widgets)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    add_executable(roe
        src/main.cc
        )
    target_link_libraries(roe PUBLIC roeden)
    # Define target properties for Android with Qt 6 as:
    #    set_property(TARGET roe APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(roe SHARED
            ${PROJECT_SOURCES}
            )
        # Define properties for Android with Qt 5 after find_package() calls as:
        #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(roe
            ${PROJECT_SOURCES}
            )
    endif()
endif()

target_link_libraries(roe PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(roe PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    )

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(roe)
endif()
