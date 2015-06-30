include(BundleUtilities)

message("post-install script for @EXECUTABLE@")

execute_process(COMMAND ${CMAKE_COMMAND} -E copy_directory "@QT_DIR_QML@" "@INSTALL_QML_DIR@")
execute_process(COMMAND chmod 777 "@ROOT_DIR@/CMake/FixQt.sh")
execute_process(COMMAND chmod 777 "@INSTALL_DIR@/@EXECUTABLE@")
execute_process(COMMAND "@QT_DIR_BIN@/macdeployqt" "@INSTALL_DIR@/@EXECUTABLE@")
execute_process(COMMAND otool -L "@INSTALL_DIR@/@EXECUTABLE@/Contents/MacOS/@TEMPLATE_NAME@")
