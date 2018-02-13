# ios-cmake-tiny
A tiny CMake project for cross-platform MacOS/iOS App: setting target version, bundle file, code signing...

#### Linux
```
1. cd ios-cmake-tiny
2. mkdir release && cd release
3. cmake -DCMAKE_BUILD_TYPE=Release .. && make -j8
4. ./cmakeios
```

#### Xcode: target -> MacOS
```
1. cd ios-cmake-tiny
2. mkdir build && cd build
3. cmake -GXcode ..
4. open CMakeIOS.xcodeproj
5. build target cmakeios with Xcode
6. run with Xcode or (cd Debug && ./cmakeios) from command line
```

#### Xcode: target -> IOS
```
1. cd ios-cmake-tiny
2. mkdir build && cd build
3. cmake -GXcode -DIOS=1 -DRes_DIR="path/to/model/feature/files" ..
4. open CMakeIOS.xcodeproj
5. build and run target cmakeios with Xcode
```
