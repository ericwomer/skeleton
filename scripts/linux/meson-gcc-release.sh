#!/bin/bash

cd ../../
rm -rf _buildMesonGccRelease

meson setup -Dbuildtype=release -Duse-mold=true --native-file profiles/gcc-linux.ini -Dprefix=/usr/local/ _buildMesonGccRelease
