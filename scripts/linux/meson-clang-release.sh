#!/bin/bash

cd ../../
rm -rf _buildClangRelease

meson setup -Dbuildtype=release -Duse-mold=enabled --native-file profiles/clang-linux.ini -Dprefix=/usr/local/ _buildClangRelease
