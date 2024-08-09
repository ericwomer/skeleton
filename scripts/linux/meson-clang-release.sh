#!/bin/bash

cd ../../
rm -rf _buildMesonClangRelease

meson setup -Dbuildtype=release -Duse-mold=true --native-file profiles/clang-linux.ini -Dprefix=/usr/local/ _buildMesonClangRelease
