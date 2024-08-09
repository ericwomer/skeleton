#!/bin/bash

cd ../../
rm -rf _buildCmakeGccRelease
mkdir _buildCmakeGccRelease
cd _buildCmakeGccRelease

cmake -G "Ninja" -DUSE_MOLD=ON -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release ../
