
#include <string>
#include <algorithm>

#include "ApplicationImplementation.h"
#include "config.h"

using std::cout;
using std::string;
using std::vector;

namespace ew {

auto ApplicationImplementation::main(int argc, char** argv) -> int
{
  vector<string> processed = process_flags();

  // If one of the default parameters was called and it is supposed to exit at this time, exit.
  if (std::count(processed.begin(), processed.end(), "exit")) {
    return EXIT_SUCCESS;
  }

  /** Do your work here. **/

  return EXIT_SUCCESS;
}

auto ApplicationImplementation::process_flags() -> vector<string>
{
  std::vector<string> processed;

  // Process the parameters if applicable at this time.
  for (auto& flag : flags()) {
    if (flag == "--help" || flag == "-h") {
      help();
      processed.emplace_back("exit");
      break;
    } else if (flag == "--version" || flag == "-v") {
      print_version();
      processed.emplace_back("exit");
      break;
    } else {  // Eric: set this up to pass the remainder flags back to the child for the derived class to handle custom parameters
      processed.emplace_back(flag);
    }
  }
  return processed;
}

auto ApplicationImplementation::init(int argc, char** argv) -> int
{  // TODO Eric: clean this up
  this->log_init("ApplicationInterface");

  for (int i = 0; i != argc; ++i) {
    this->flags().emplace_back(argv[i]);  // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
  }

  std::string executable_name = this->flags().data()[0];  // Eric: does this even work?
  executable_name.erase(0, 2);

  Info information = {executable_name,
                      executable_name,
                      std::vector<std::string>(),
                      {Major, Minor, Patch, Compile},
                      std::vector<std::string>()};

  this->info(information);

  // Remove the now un-needed application name from the list of handled parameters.
  this->flags().erase(this->flags().begin());
  return EXIT_SUCCESS;
}

auto ApplicationImplementation::help() const -> void
{
  print_version();

  std::cout << "Usage: " << name() << " [options] files...\n";
  std::cout << "Options: \n";
  std::cout << " -h, --help \t\t Print this help message and exit the program.\n";
  std::cout << " -v, --version \t\t Print the version and exit.\n\n";
};

auto ApplicationImplementation::print_version() const -> void
{
  std::cout << name() << " version " << info().version_number << "\n";
  std::cout << "Compiler: \t\t" << compiler_name << " " << compiler_version << "\n";
  std::cout << "Operating System: \t" << operating_system << "\n";
  std::cout << "Architecture: \t\t" << cpu_family << "\n\n";
};

}  // namespace ew