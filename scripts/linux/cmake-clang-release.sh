#!/bin/bash

cd ../../
rm -rf _buildClangRelease
mkdir _buildClangRelease
cd _buildClangRelease

cmake -G "Ninja" -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Release ../
