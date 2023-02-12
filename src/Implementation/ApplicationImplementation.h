#if !defined(APPLICATIONIMPLEMENTATION_H)
#define APPLICATIONIMPLEMENTATION_H

#include "Interface/ApplicationInterface.h"
#include "log/log.h"

namespace ew {
class ApplicationImplementation
    : public ApplicationInterface {  // Eric: Don't need to inherit from Log as ew::ApplicationInterface already does.
public:
  ApplicationImplementation()           = default;
  ~ApplicationImplementation() override = default;
  auto main(int argc, char** argv) -> int override;

  auto help() const -> void override;
  auto size() -> int override { return sizeof(*this); };

  auto print_version() const -> void;

  auto init(int argc, char** argv) -> int override;
  auto process_flags() -> std::vector<std::string>;
};
}  // namespace ew
#endif  // APPLICATIONIMPLEMENTATION_H
