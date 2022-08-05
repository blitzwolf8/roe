cmake_minimum_required(VERSION 3.14)

if(CMAKE_VERSION VERSION_LESS 3.0)
  project(roe CXX C)
  set(PROJECT_VERSION ${ROE_VERSION})
else()
  cmake_policy(SET CMP0048 NEW)
  project(roe VERSION ${ROE_VERSION} LANGUAGES CXX C )
endif()

find_package(Qt6 6.2 COMPONENTS Core Widgets REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O3")

set(ROE_INCLUDE_DIRS 
    "${roe_SOURCE_DIR}/include"
)

include_directories(ROE_INLCUDE_DIRS)

set(ROE_SOURCE_DIR "${roe_SOURCE_DIR}/src")

set(PROJECT_SOURCES
        ${ROE_SOURCE_DIR}/main.cc
        ${ROE_SOURCE_DIR}/editor.cc
        ${ROE_SOURCE_DIR}/document.cc
        ${ROE_SOURCE_DIR}/tabwidget.cc
        ${ROE_SOURCE_DIR}/window.cc  
        
        
        ${roe_SOURCE_DIR}/include/document.h
        ${roe_SOURCE_DIR}/include/editor.h
        ${roe_SOURCE_DIR}/include/tabwidget.h
        ${roe_SOURCE_DIR}/include/window.h   
)


qt_add_executable(roe
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

target_include_directories(roe PUBLIC ${ROE_INCLUDE_DIRS})
target_link_directories(roe PUBLIC ${ROE_INCLUDE_DIRS})

target_compile_definitions(roe
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

if(CMAKE_BUILD_TYPE STREQUAL "Asan")  
  target_compile_options(roe PRIVATE -fsanitize=address)
  target_link_options(roe PRIVATE -fsanitize=address)
endif(CMAKE_BUILD_TYPE STREQUAL "Asan")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  target_compile_options(roe PRIVATE -g -O3)
  target_link_options(roe PRIVATE -g -O3)
endif(CMAKE_BUILD_TYPE STREQUAL "Debug")


if(CMAKE_BUILD_TYPE STREQUAL "Tsan")
  target_compile_options(roe PRIVATE -fsanitize=thread)
  target_link_options(roe PRIVATE -fsanitize=thread)
endif(CMAKE_BUILD_TYPE STREQUAL "Tsan")

target_link_libraries(roe
  PRIVATE Qt6::Core Qt6::Widgets)

set_target_properties(roe PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER roe.xio.org
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    #qt_import_qml_plugins(roe)
    qt_finalize_executable(roe)
endif()
