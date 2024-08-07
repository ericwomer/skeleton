#!/bin/bash

cd ../../
rm -rf _buildGccDebug

meson setup -Dbuildtype=debug -Duse-mold=enabled --native-file profiles/gcc-linux.ini -Dprefix=/usr/local/ _buildGccDebug
