#ifndef SKELETON_H
#define SKELETON_H

#include "base/base.h"
#include "log/log.h"

class Skeleton : public Base::Application { // Eric: Don't need to inherit from Log as Base::Application already does.
public:
  Skeleton()           = default;
  ~Skeleton() override = default;
  auto main(std::vector<std::string>& params) -> int override;
};

#endif  // SKELETON_H
