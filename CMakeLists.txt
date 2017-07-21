# project
# ******************************************************************************
cmake_minimum_required(VERSION 3.0)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake;")
include(Functions)

set(TEMPLATE_APPLICATION_NAME "App" CACHE STRING "Application name")
set(PROJECT_NAME ${TEMPLATE_APPLICATION_NAME})

project(${PROJECT_NAME})

set(TEMPLATE_USE_CPP11 ON CACHE BOOL "Use C++11")

# project directories
# ******************************************************************************
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install)
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(PROJECT_INSTALL_DIR ${CMAKE_INSTALL_PREFIX})
set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)

# output directories
# ******************************************************************************
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BUILD_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${BUILD_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${BUILD_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${BUILD_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${BUILD_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${BUILD_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${BUILD_DIR})

# meta
# ******************************************************************************
set(TEMPLATE_VERSION_MAJOR 1 CACHE INT "Version Major")
set(TEMPLATE_VERSION_MINOR 0 CACHE INT "Version Minor")
set(TEMPLATE_VERSION_PATCH 0 CACHE INT "Version Patch")
set(TEMPLATE_ORGANIZATION "organization" CACHE STRING "Organization")
set(TEMPLATE_DOMAIN "domain" CACHE STRING "Domain")

# Qt
# ******************************************************************************
set(TEMPLATE_QT_VERSION "5.9.1" CACHE STRING "Qt Version")
set(TEMPLATE_QT_MODULES Core Gui Widgets Quick Qml Concurrent Network DBus PrintSupport)

find_package(Qt5 ${TEMPLATE_QT_VERSION} EXACT CONFIG REQUIRED ${TEMPLATE_QT_MODULES})
set(CMAKE_AUTOMOC true)

# configure files
# ******************************************************************************
configure_file(${ROOT_DIR}/cmake/meta.hpp.in ${BINARY_DIR}/meta.hpp)

if(APPLE)
    configure_file(${ROOT_DIR}/cmake/info.plist.in ${BINARY_DIR}/info.plist)
endif()

# definitions
# ******************************************************************************
add_definitions(${QT_DEFINITIONS})
add_definitions(-DUSE_INSTALL_TARGET)

# apple rpath
# ******************************************************************************
if(APPLE)
    set(CMAKE_SKIP_BUILD_RPATH false)
    set(CMAKE_BUILD_WITH_INSTALL_RPATH false)
    set(CMAKE_INSTALL_RPATH "@executable_path/../Frameworks")
    set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)
endif()

# sources
# ******************************************************************************
AddSources("${SOURCE_DIR}/App" "App" list_app_src)

# target
# ******************************************************************************
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(APPLE)
    set(MACOSX_BUNDLE_BUNDLE_VERSION 1)
    set(MACOSX_BUNDLE_LONG_VERSION_STRING ${TEMPLATE_VERSION_MAJOR}.${TEMPLATE_VERSION_MINOR}.${TEMPLATE_VERSION_PATCH})
    set(MACOSX_BUNDLE_SHORT_VERSION_STRING ${TEMPLATE_VERSION_MAJOR}.${TEMPLATE_VERSION_MINOR}.${TEMPLATE_VERSION_PATCH})
    set(MACOSX_BUNDLE_ICON_FILE Icon.icns)
    set(MACOSX_BUNDLE_BUNDLE_NAME ${PROJECT_NAME})
    set(MACOSX_BUNDLE_RESOURCES ${BUILD_DIR}/${PROJECT_NAME}.app/Contents/Resources)
    set(MACOSX_BUNDLE_ICON ${ROOT_DIR}/res/icons/develop/${MACOSX_BUNDLE_ICON_FILE})

    add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${list_app_src} ${MACOSX_BUNDLE_ICON})
	set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${BINARY_DIR}/info.plist)
else()
    add_executable(${PROJECT_NAME} ${list_app_src})
endif()

target_include_directories(${PROJECT_NAME} PUBLIC ${BINARY_DIR})

# c++11
# ******************************************************************************
if(${TEMPLATE_USE_CPP11})
    if(${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION} GREATER 3.0)
        set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
        set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
    else()
        if(APPLE)
            list(APPEND CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -stdlib=libc++")
        endif()
        if(UNIX AND NOT APPLE)
            list(APPEND CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
        endif()
    endif()
endif()

# copy resources
# ******************************************************************************
if(APPLE)
    execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${MACOSX_BUNDLE_RESOURCES})
    execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different ${MACOSX_BUNDLE_ICON} ${MACOSX_BUNDLE_RESOURCES})
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory "${ROOT_DIR}/res" ${BUILD_DIR}/${PROJECT_NAME}.app/Contents/Resources)
else()
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory "${ROOT_DIR}/res" ${BUILD_DIR}/Resources)
    add_custom_target(CopyResources ALL COMMAND ${CMAKE_COMMAND} -E copy_directory "${ROOT_DIR}/res" ${BUILD_DIR}/Resources)
endif()

# link
# ******************************************************************************
target_link_libraries(${PROJECT_NAME} PUBLIC Qt5::Core PUBLIC Qt5::Widgets PUBLIC Qt5::Gui PUBLIC Qt5::Quick PUBLIC Qt5::Qml PUBLIC Qt5::Concurrent)
