//
//  main.cpp
//  cmake ios test
//
//  Created by wykvictor on 2018/2/9.
//  Copyright © 2018年 wykvictor. All rights reserved.
//

#ifdef __APPLE__
  #include "TargetConditionals.h"
  #if TARGET_OS_OSX
    #include <fstream>
  #else
    #import <Foundation/Foundation.h>
  #endif
#else
  #include <fstream>
#endif

#include <iostream>
#include <vector>

int main(int argc, char * argv[]) {
  std::vector<char> buffer;
#if (!__APPLE__) || TARGET_OS_OSX  // Platform: MacOS / Linux
  #if TARGET_OS_OSX
    std::ifstream ifs("../../Resource/test.txt", std::ios::binary | std::ios::ate);  // open and move to end
  #else  // linux
    std::ifstream ifs("../Resource/test.txt", std::ios::binary | std::ios::ate);  // open and move to end
  #endif
  if (!ifs.fail()) {
    buffer.resize(ifs.tellg());
    if (!ifs.seekg(0, std::ios::beg).read(buffer.data(), static_cast<std::streamsize>(buffer.size()))) {
      std::cerr << "Error Read file!" << std::endl;
      return -1;
    }
  } else {
    std::cerr << "Error Read file!" << std::endl;
    return -1;
  }
#else  // Platform: iOS
  NSString* filename = [NSString stringWithUTF8String:"test.txt"];
  NSString* pathFile = [[NSBundle mainBundle] pathForResource:filename ofType:@""];
  NSFileHandle *file = [NSFileHandle fileHandleForReadingAtPath:pathFile];
  if (file == nil) {
    std::cerr << "Error Read file!" << std::endl;
    return -1;
  }
  [file seekToFileOffset:0];
  NSData *fileData = [file readDataToEndOfFile];
  buffer.resize((int)fileData.length);
  memcpy((void*)buffer.data(),fileData.bytes, buffer.size());
  [file closeFile];
#endif
  printf("%s\n", buffer.data());
  return 0;
}
