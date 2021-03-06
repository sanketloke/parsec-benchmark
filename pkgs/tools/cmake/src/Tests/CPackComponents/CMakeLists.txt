# CPack Example: User-selectable Installation Components
#
# In this example, we have a simple library (mylib) with an example
# application (mylibapp). We create a binary installer that allows
# users to select which pieces will be installed: the example
# application, the library binaries, and/or the header file.
cmake_minimum_required(VERSION 2.6)
project(CPackComponents)

# Create the mylib library
add_library(mylib mylib.cpp)

# Create the mylibapp application
add_executable(mylibapp mylibapp.cpp)
target_link_libraries(mylibapp mylib)

# Create installation targets. Note that we put each kind of file
# into a different component via COMPONENT. These components will 
# be used to create the installation components.
install(TARGETS mylib 
  ARCHIVE
  DESTINATION lib
  COMPONENT libraries)
install(TARGETS mylibapp
  RUNTIME
  DESTINATION bin
  COMPONENT applications)
install(FILES mylib.h
  DESTINATION include
  COMPONENT headers)

# CPack boilerplate for this project
set(CPACK_PACKAGE_NAME "MyLib")
set(CPACK_PACKAGE_VENDOR "CMake.org")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "MyLib - CPack Component Installation Example")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "CPack Component Example")

# Include CPack to introduce the appropriate targets
include(CPack)

# Installation types
cpack_add_install_type(Full
  DISPLAY_NAME "Everything")
cpack_add_install_type(Developer)

# Component groups
cpack_add_component_group(Runtime)
cpack_add_component_group(Development
  EXPANDED
  DESCRIPTION "All of the tools you'll ever need to develop software")

# Components
cpack_add_component(applications
  DISPLAY_NAME "MyLib Application"
  DESCRIPTION "An extremely useful application that makes use of MyLib"
  GROUP Runtime
  INSTALL_TYPES Full)
cpack_add_component(libraries
  DISPLAY_NAME "Libraries"
  DESCRIPTION "Static libraries used to build programs with MyLib"
  GROUP Development
  INSTALL_TYPES Developer Full)
cpack_add_component(headers
  DISPLAY_NAME "C++ Headers"
  DESCRIPTION "C/C++ header files for use with MyLib"
  GROUP Development
  DEPENDS libraries
  INSTALL_TYPES Developer Full)
