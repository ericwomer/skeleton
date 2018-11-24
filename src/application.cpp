#include <iostream>
#include <limits>
#include <sstream>
#include <string>

#include "application.h"
#include "config.h"

namespace Skeleton {

Application::Application()
{
    version({Major, Minor, Patch, Compile});
    name(project_name);
    app_description.push_back(std::string("Skeleton \n"));
    app_description.push_back(std::string("** nothing else follows ** \n"));
}

// All of the application starts here
// if any parameters are used they are handled
// with member vars.
int Application::main()
{
    return EXIT_SUCCESS;
}

// This is the main that handles parameters
int Application::main(std::vector<std::string>& params)
{
    executable_name = params[0].data();
    executable_name.erase(0, 2);

    std::vector<std::string> dump;

    // iterate through params to remove the -- from the text
    for (std::vector<std::string>::const_iterator i = params.begin(); i != params.end(); ++i) {
        if (*i == "--help" || *i == "-h") {
            version();
            help();
            return EXIT_SUCCESS;
        } else if (*i == "--version" || *i == "-v") {
            version();  // Eric: BUG: Not able to return EXIT_SUCCESS here atm!
        } else {        // catch all to make sure there are no invalid parameters
            if (*i != params[0].data()) {
                std::cout << *i << " was an unknown parameter! \n";
                help();
            }
            dump.push_back(*i);
        }
    }

    return main();
}

void Application::help(void)
{
    std::cout << "Usage: " << executable_name << " [options] files...\n\n";
    std::cout << "Options: \n";
    std::cout << " -h, --help \t\t Print this help message and exit the program.\n";
    std::cout << " -v, --version \t\t Print the version and exit.\n";
}

void Application::version() const
{
    std::cout << app_name << " version " << version_number << "\n";
    std::cout << "Compiler: " << compiler_name << " " << compiler_version << "\n";
    std::cout << "Operating System: " << operating_system << "\n";
    std::cout << "Architecture: " << cpu_family << std::endl;
}

}  // namespace Skeleton
