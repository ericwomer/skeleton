#!/bin/bash

cd ../../
rm -rf _buildMesonGccDebug

meson setup -Dbuildtype=debug -Duse-mold=true --native-file profiles/gcc-linux.ini -Dprefix=/usr/local/ _buildMesonGccDebug
