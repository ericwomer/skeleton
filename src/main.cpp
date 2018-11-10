#include <iostream>

#include "skeletonapp.h"

SkeletonApp skeleton;

int main(int argv, char* argc[])
{
    if (argv == 1) {
        try {
            skeleton.main();
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    } else {
        try {
            skeleton.main(argv, argc);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}
