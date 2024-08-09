#!/bin/bash

cd ../../
rm -rf _buildMesonClangDebug

meson setup -Dbuildtype=debug -Duse-mold=true --native-file profiles/clang-linux.ini -Dprefix=/usr/local/ _buildMesonClangDebug
