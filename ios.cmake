# from https://public.kitware.com/Bug/view.php?id=15329
set(CMAKE_MACOSX_BUNDLE YES)

# from https://gitlab.kitware.com/cmake/cmake/issues/17353
set(CMAKE_XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET "10.0" CACHE STRING "Minimum OS X deployment version" FORCE)

# from https://github.com/sheldonth/ios-cmake/blob/master/CMakeLists.txt
set(MACOSX_BUNDLE_GUI_IDENTIFIER "wykvictor.cmaketios")

# from https://stackoverflow.com/questions/822404/how-to-set-up-cmake-to-build-an-app-for-the-iphone
set(CMAKE_OSX_SYSROOT iphoneos)

# https://stackoverflow.com/questions/40664125/cmake-and-code-signing-in-xcode-8-for-ios-projects?answertab=votes#tab-top
# This little macro lets you set any XCode specific property
macro (set_xcode_property TARGET XCODE_PROPERTY XCODE_VALUE)
  set_property (TARGET ${TARGET} PROPERTY XCODE_ATTRIBUTE_${XCODE_PROPERTY} ${XCODE_VALUE})
endmacro (set_xcode_property)
