#!/bin/bash

cd ../../
rm -rf _buildCmakeClangDebug
mkdir _buildCmakeClangDebug
cd _buildCmakeClangDebug

cmake -G "Ninja" -DUSE_MOLD=ON -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Debug ../
