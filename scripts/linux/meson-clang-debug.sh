#!/bin/bash

cd ../../
rm -rf _buildClangDebug

meson setup -Dbuildtype=debug -Duse-mold=enabled --native-file profiles/clang-linux.ini -Dprefix=/usr/local/ _buildClangDebug
