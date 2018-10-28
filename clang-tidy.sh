#!/bin/bash

clang-tidy `find . -type f \( -name '*.h' -o -name '*.cpp' \) -not -path "./thirdparty/*" ` -config='' -p builddir/ "$@" 
# -- -std=c++11 -stdlib=libc++ -I/usr/lib/llvm-8/include/c++/v1/ -x c++
