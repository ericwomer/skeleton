#include <iostream>

#include "skeletonapp.h"
#include "config.h"

SkeletonApp skeleton;

int main(int argv, char* argc[])
{
    Skeleton::Version_t version = {1, 2, 3, 4};
    skeleton.version(version);
    if (argv == 1) {
        skeleton.main();
    } else {
        skeleton.main(argv, argc);
    }
    return 0;
}
