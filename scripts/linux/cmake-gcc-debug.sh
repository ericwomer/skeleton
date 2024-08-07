#!/bin/bash

cd ../../
rm -rf _buildGccDebug
mkdir _buildGccDebug
cd _buildGccDebug

cmake -G "Ninja" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Debug ../
