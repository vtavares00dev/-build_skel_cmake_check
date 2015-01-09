#!/bin/sh

rm -Rf ./build
mkdir build
cd build
cmake ..
make
ctest --output-on-failure
