#!/bin/bash

cd ../../
rm -rf _buildClangDebug
mkdir _buildClangDebug
cd _buildClangDebug

cmake -G "Ninja" -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Debug ../
