
#include <iostream>
#include <vector>
#include <memory>

#include <string>
#include <exception>

#include <cstdlib>

#include "Implementation/ApplicationImplementation.h"
#include "log/log.h"

using std::cerr;
using std::cout;
using std::exception;
using std::make_unique;
using std::string;
using std::unique_ptr;
using std::vector;

auto main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) -> int
{
  // Eric: Use Log log for main until I find something better/different.
  Log log;
  log.log_init("Main");
  log.info("Starting ...");

  // ApplicationInterface class that calls main
  unique_ptr<ew::ApplicationInterface> application = make_unique<ew::ApplicationImplementation>();

  try {
    application->init(argc, argv);
  } catch(const exception &e) {
    log.error(e.what());
  }

  try {
    application->main(argc, argv);
  } catch(const exception &e) {
    log.error(e.what());
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
