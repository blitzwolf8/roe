cmake_minimum_required(VERSION 3.14)

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

set_target_properties(roe PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER roe.xio.org
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    #qt_import_qml_plugins(roe)
    qt_finalize_executable(roe)
endif()
