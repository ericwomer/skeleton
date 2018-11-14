#include <iostream>

#include "skeletonapp.h"

Application::SkeletonApp skeleton;

int main(int argc, char* argv[])
{
    // Convert c style list of strings to a c++ vector of strings
    std::vector<std::string> params;
    for (int i = 1; i != argc; ++i) {
        params.push_back(argv[i]);
    }

    // Eric: Empty!
    try {
        skeleton.main(params);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
