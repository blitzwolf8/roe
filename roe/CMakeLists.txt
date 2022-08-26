cmake_minimum_required(VERSION 3.14)

project(roe VERSION ${ROE_VERSION} LANGUAGES CXX)

set(RESOURCE_DIR "${roe_SOURCE_DIR}/res")
set(INCLUDE_DIR "${roe_SOURCE_DIR}/include")
set(SOURCE_DIR "${roe_SOURCE_DIR}/src")

include_directories(
  ${RESOURCE_DIR}
  ${INCLUDE_DIR}
  ${SOURCE_DIR}
)

file(GLOB_RECURSE SOURCES
    "${RESOURCE_DIR}/*.qrc"
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cc"
)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${RESOURCE_DIR})

qt_add_executable(roe
    MANUAL_FINALIZATION
    ${SOURCES}
)

target_include_directories(roe PUBLIC ${PI_INCLUDE_DIRS})
target_link_directories(roe PUBLIC ${PI_INCLUDE_DIRS})

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
  PRIVATE Qt6::Core Qt6::Widgets )

set_target_properties(roe PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER roe.xio.org
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    #qt_import_qml_plugins(roe)
    qt_finalize_executable(roe)
endif()
