cmake_minimum_required(VERSION 3.0)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(Functions)

# system & generator check
# ******************************************************************************************************************************************************************
if(NOT APPLE)
	message(FATAL_ERROR "Currently configured for Mac OS X only")
endif()

if(NOT ${CMAKE_GENERATOR} MATCHES "Xcode")
	message(FATAL_ERROR "Currently configured for XCode only")
endif()

# definitions & compiler flags
# ******************************************************************************************************************************************************************
option(USE_CPP11 "Use C++ 11" ON)
if(USE_CPP11)
	list(APPEND CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
endif()
add_definitions(-DUSE_INSTALL_TARGET)

# project setup
# ******************************************************************************************************************************************************************
set(TEMPLATE_NAME "BaseApp" CACHE STRING "app name")

project(${TEMPLATE_NAME})
set(EXECUTABLE "${TEMPLATE_NAME}.app")

set(TEMPLATE_BUNDLE_INFO "info" CACHE STRING "bundle info string")
set(TEMPLATE_BUNDLE_VENDOR "vendor" CACHE STRING "vendor")
set(TEMPLATE_BUNDLE_COPYRIGHT "2015 vendor" CACHE STRING "copyright")
set(TEMPLATE_BUNDLE_VERSION_MAJOR "0" CACHE STRING "major version")
set(TEMPLATE_BUNDLE_VERSION_MINOR "0" CACHE STRING "minor version")
set(TEMPLATE_BUNDLE_VERSION_PATCH "1" CACHE STRING "patch version")

option(CMAKE_AUTOMOC "Use Automoc" ON)
option(TEMPLATE_USE_QT "Use Qt" ON)

set_property(GLOBAL PROPERTY AUTOGEN_TARGETS_FOLDER autogen)

# central paths
# ******************************************************************************************************************************************************************
SET(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_INSTALL_PREFIX ${ROOT_DIR}/install)

set(INSTALL_DIR ${CMAKE_INSTALL_PREFIX})
set(BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(BUILD_DIR ${ROOT_DIR}/build)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BUILD_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${BUILD_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${BUILD_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${BUILD_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${BUILD_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${BUILD_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${BUILD_DIR})

# setup os x bundle
# ******************************************************************************************************************************************************************
set(MACOSX_BUNDLE_INFO_STRING ${TEMPLATE_BUNDLE_INFO})
set(MACOSX_BUNDLE_BUNDLE_VERSION ${TEMPLATE_BUNDLE_VERSION})
set(MACOSX_BUNDLE_LONG_VERSION_STRING ${TEMPLATE_BUNDLE_VERSION_MAJOR}.${TEMPLATE_BUNDLE_VERSION_MINOR}.${TEMPLATE_BUNDLE_VERSION_PATCH})
set(MACOSX_BUNDLE_SHORT_VERSION_STRING ${TEMPLATE_BUNDLE_VERSION_MAJOR}.${TEMPLATE_BUNDLE_VERSION_MINOR}.${TEMPLATE_BUNDLE_VERSION_PATCH})
set(MACOSX_BUNDLE_COPYRIGHT ${TEMPLATE_BUNDLE_COPYRIGHT})
set(MACOSX_BUNDLE_ICON_FILE ${TEMPLATE_NAME}.icns)
set(MACOSX_BUNDLE_GUI_IDENTIFIER "org.${TEMPLATE_BUNDLE_VENDOR}")
set(MACOSX_BUNDLE_BUNDLE_NAME ${TEMPLATE_NAME})
set(MACOSX_BUNDLE_RESOURCES ${BINARY_DIR}/${EXECUTABLE}/Contents/Resources)
set(MACOSX_BUNDLE_ICON ${ROOT_DIR}/res/icons/${MACOSX_BUNDLE_ICON_FILE})

# bundle directories & resources
# ******************************************************************************************************************************************************************
execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${MACOSX_BUNDLE_RESOURCES})
execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different ${MACOSX_BUNDLE_ICON} ${MACOSX_BUNDLE_RESOURCES})

# version
# ******************************************************************************************************************************************************************
configure_file(${ROOT_DIR}/cmake/info.in.cpp ${ROOT_DIR}/src/app/AppInfo.cpp)

# add source dirs
# ******************************************************************************************************************************************************************
AddSrc("src/app" "app" list_app_src)

AddRes("res/asset" "asset" list_app_res)
AddRes("res/font/font-awesome" "font" list_app_res)
AddRes("res/font/roboto" "font" list_app_res)
AddRes("res/qml/lib" "qml" list_app_res)
AddRes("res/qml/view" "qml" list_app_res)

PrintList("app sources" "${list_app_src}")
PrintList("app resources" "${list_app_res}")

# add executable
# ******************************************************************************************************************************************************************
add_executable(${TEMPLATE_NAME} MACOSX_BUNDLE ${list_app_src} ${MACOSX_BUNDLE_ICON})

# qt
# ******************************************************************************************************************************************************************
if(TEMPLATE_USE_QT)
	set(TEMPLATE_QT_VERSION "5.4.0" CACHE STRING "Qt version")
	find_package(Qt5 ${TEMPLATE_QT_VERSION} CONFIG REQUIRED Core Gui Widgets Quick Qml Concurrent)
	add_definitions(${QT_DEFINITIONS})
	target_link_libraries(${TEMPLATE_NAME} Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Quick Qt5::Qml Qt5::Concurrent)

	get_filename_component(Q_DIR_CONFIG ${Qt5_DIR} DIRECTORY)
	get_filename_component(Q_DIR_LIB ${Q_DIR_CONFIG} DIRECTORY)
	get_filename_component(Q_DIR_INSTALL ${Q_DIR_LIB} DIRECTORY)

	set(QT_DIR_BIN ${Q_DIR_INSTALL}/bin)
	set(QT_DIR_QML ${Q_DIR_INSTALL}/qml)
	set(INSTALL_QML_DIR ${INSTALL_DIR}/${EXECUTABLE}/Contents/MacOS)

	message(STATUS "> install qml libs: ${QT_DIR_QML} => ${INSTALL_QML_DIR}")
endif()

# install
# ******************************************************************************************************************************************************************
configure_file(${ROOT_DIR}/cmake/PostInstall.in.cmake ${BINARY_DIR}/PostInstall.cmake)
install(TARGETS ${TEMPLATE_NAME} BUNDLE DESTINATION . COMPONENT Runtime RUNTIME DESTINATION bin COMPONENT Runtime)
install(FILES ${MACOSX_BUNDLE_ICON} DESTINATION "${INSTALL_DIR}/${EXECUTABLE}/Contents/Resources")

if(TEMPLATE_USE_QT)
	install(SCRIPT ${BINARY_DIR}/PostInstall.cmake)
endif()

# post-build: pack resources
# ******************************************************************************************************************************************************************
add_custom_command(TARGET ${TEMPLATE_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory "${ROOT_DIR}/res" ${BUILD_DIR}/${EXECUTABLE}/Contents/Resources)

