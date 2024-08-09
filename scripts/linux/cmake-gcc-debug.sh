#!/bin/bash

cd ../../
rm -rf _buildCmakeGccDebug
mkdir _buildCmakeGccDebug
cd _buildCmakeGccDebug

cmake -G "Ninja" -DUSE_MOLD=ON -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Debug ../
