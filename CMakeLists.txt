cmake_minimum_required(VERSION 3.10)
project(CMakeIOS)

if(IOS)
  include(ios.cmake)
  # from https://stackoverflow.com/questions/4714698/mixing-objective-c-m-mm-c-cpp-files
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -x objective-c++")
  # add_definitions(-D__IOS__)
endif()

############ bundle files ################
set(Res_DIR "./Resource" CACHE STRING "Bundle files")  # cmake -DRes_DIR="path/to/res/files"
file(GLOB Res_Files "${Res_DIR}/*.txt")
set_source_files_properties(${Res_Files} PROPERTIES MACOSX_PACKAGE_LOCATION Resources)
source_group("BundleRes" FILES ${Res_Files})

add_executable(cmakeios main.cpp ${Res_Files})

if(IOS)
  target_link_libraries(cmakeios "-framework UIKit -framework OpenGLES -framework Metal")
  SET_XCODE_PROPERTY(cmakeios CODE_SIGN_IDENTITY "iPhone Developer")
  SET_XCODE_PROPERTY(cmakeios DEVELOPMENT_TEAM "IDIDIDIDID")  # TeamID, example "CW3H47U4OR"
endif()
