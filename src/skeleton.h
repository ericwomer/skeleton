#ifndef SKELETON_H
#define SKELETON_H

#include "base/base.h"

class Skeleton : public Base::Application {
public:
  Skeleton() = default;
  ~Skeleton() = default ;
  int main(std::vector<std::string>& params) override;
};

#endif  // SKELETON_H
