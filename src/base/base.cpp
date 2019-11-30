
#include "base.h"
#include "config.h"

#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::exception;
using std::string;
using std::vector;

namespace Base {

Application::Application() : app_name(project_name), version_number({Major, Minor, Patch, Compile})
{
  app_description.push_back(string("Skeleton \n"));
  app_description.push_back(string("** nothing else follows ** \n"));
}

// This is Base::Application::main
int Application::main(vector<string>& params)
{
  executable_name = params[0];
  executable_name.erase(0, 2);

  // Remove the now un-needed application name from the list of handled parameters.
  params.erase(params.begin());

  vector<string> child;

  // Process the parameters if applicable at this time.
  for (auto& param : params) {
    if (param == "--help" || param == "-h") {
      version();
      help();
      child.push_back("exit");
      break;
    } else if (param == "--version" || param == "-v") {
      version();
      child.push_back("exit");
      break;
    } else {  // Eric: set this up to pass the remainder params back to the child for the derived class to handle custom parameters
      child.push_back(param);
    }
  }

  // Pass the non default parameters to the child process that called the derived main
  params.clear();
  params = child;

  return EXIT_SUCCESS;
}

void Application::help() const
{
  cout << "Usage: " << executable_name << " [options] files...\n";
  cout << "Options: \n";
  cout << " -h, --help \t\t Print this help message and exit the program.\n";
  cout << " -v, --version \t\t Print the version and exit.\n\n";
}

void Application::version() const
{
  cout << app_name << " version " << version_number << "\n";
  cout << "Compiler: \t\t" << compiler_name << " " << compiler_version << "\n";
  cout << "Operating System: \t" << operating_system << "\n";
  cout << "Architecture: \t\t" << cpu_family << "\n\n";
}

}  // namespace Base
