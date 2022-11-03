#!/bin/bash

rm -rf build
mkdir build
cd build
conan install .. --build=missing
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake ../
make -j8