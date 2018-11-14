#include <iostream>
#include <limits>
#include <sstream>
#include <string>

#include "skeletonapp.h"
#include "config.h"

namespace Application {

SkeletonApp::SkeletonApp()
{
    version({Major, Minor, Patch, Compile});
    name(project_name);
    app_description.push_back(std::string("Skeleton \n"));
    app_description.push_back(std::string("** nothing else follows ** \n"));
}

// All of the application starts here
// if any parameters are used they are handled
// with member vars.
int SkeletonApp::main()
{
    return EXIT_SUCCESS;
}

// This is the main that handles parameters
int SkeletonApp::main(std::vector<std::string>& params)
{
    // std::vector<std::string> actions;
    std::vector<std::string> dump;

    // iterate through params to remove the -- from the text
    for (std::vector<std::string>::const_iterator i = params.begin(); i != params.end(); ++i) {
        if (*i == "--help" || *i == "-h") {
            actions.push_back("help");
        } else if (*i == "--verbose" || *i == "-v") {
            actions.push_back("verbose");
        } else if (*i == "--version" || *i == "-V") {
            actions.push_back("version");
        } else {  // catch all to make sure there are no invalid parameters
            dump.push_back(*i);
        }
    }

    for (auto& c : actions) {  // handle all the prameters
        if (c == "help") {
            help();
            return 0;  // exit the app
        } else if (c == "verbose") {
            for (auto& d : actions) {
                std::cout << "--" << d << " ";
            }
            std::cout << std::endl;
            return 0;
        } else if (c == "version") {
            std::cout << app_name << " version " << version() << "\n";
            std::cout << "Compiler: " << compiler_name << " " << compiler_version << "\n";
            std::cout << "Operating System: " << operating_system << "\n";
            std::cout << "Architecture: " << cpu_family << std::endl;
            return 0;
        } else {
            dump.push_back(c);
        }
    }

    return main();
}

void SkeletonApp::help(void)
{
    std::cout << "Usage: " << app_name << " [options] files...\n\n";
    std::cout << "Options: \n";
    std::cout << " -h, --help \t\t Print this help message and exit the program.\n";
    std::cout << " -v, --verbose \t\t Print out all the valid command line "
                 "parameters\n";
    std::cout << " \t\t\t passed to the program.\n";
    std::cout << " -V, --version \t\t Print the version and exit.\n";
}

}  // namespace Application