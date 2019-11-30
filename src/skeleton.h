#ifndef SKELETON_H
#define SKELETON_H

#include "base/base.h"

class Skeleton : public Base::Application {
public:
  Skeleton() = default;
  ~Skeleton() override = default ;
  auto main(std::vector<std::string>& params) -> int override;
};

#endif  // SKELETON_H
