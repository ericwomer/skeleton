#!/bin/bash

clang-format -i -style=file -assume-filename=../.clang-format -verbose `find . -type f \( -name '*.h' \)` # -not -path "./libs/*" `
clang-format -i -style=file -assume-filename=../.clagn-format -verbose `find . -type f \( -name '*.cpp' -o -name '*.inl' \)` # ! -wholename './d3xp/gamesys/SysCvar.cpp' ! -wholename './d3xp/gamesys/Callbacks.cpp' ! -wholename './sys/win32/win_cpu.cpp' ! -wholename './sys/win32/win_main.cpp' -not -path './libs/*' `

