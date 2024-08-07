#!/bin/bash

cd ../../
rm -rf _buildGccRelease
mkdir _buildGccRelease
cd _buildGccRelease

cmake -G "Ninja" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release ../
