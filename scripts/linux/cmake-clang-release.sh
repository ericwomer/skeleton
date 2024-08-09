#!/bin/bash

cd ../../
rm -rf _buildCmakeClangRelease
mkdir _buildCmakeClangRelease
cd _buildCmakeClangRelease

cmake -G "Ninja" -DUSE_MOLD=ON -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Release ../
