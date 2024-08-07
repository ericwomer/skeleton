#!/bin/bash

cd ../../
rm -rf _buildGccRelease

meson setup -Dbuildtype=release -Duse-mold=enabled --native-file profiles/gcc-linux.ini -Dprefix=/usr/local/ _buildGccRelease
