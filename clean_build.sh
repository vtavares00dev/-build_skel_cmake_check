#!/bin/sh

rm -Rf ./build
mkdir build
cd build
cmake ..
make
echo
echo
ctest --output-on-failure
