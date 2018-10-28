#include <iostream>

#include "skeletonapp.h"

SkeletonApp skeleton;

int main(int argv, char* argc[])
{
    if (argv == 1) {
        skeleton.main();
    } else {
        skeleton.main(argv, argc);
    }
    return 0;
}
