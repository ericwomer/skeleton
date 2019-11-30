#include "skeleton.h"

#include <iostream>
#include <vector>
#include <memory>

using std::cerr;
using std::cout;
using std::exception;
using std::make_unique;
using std::string;
using std::unique_ptr;
using std::vector;

auto main(int argc, char* argv[]) -> int
{
  // Application class that calls main
  unique_ptr<Base::Application> application = make_unique<Skeleton>();

  // Convert c style list of strings to a c++ vector of strings
  vector<string> params;
  for (int i = 0; i != argc; ++i) {
    params.emplace_back(argv[i]); // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
  }

  try {
    application->main(params);
  } catch (const exception& e) {
    cerr << e.what() << '\n';
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
