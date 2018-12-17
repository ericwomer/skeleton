#ifndef SKELETON_H
#define SKELETON_H

#include "base/base.h"

class Skeleton : public Base::Application {
public:
  Skeleton();
  virtual ~Skeleton();
  int main(std::vector<std::string>& params) override;
};

#endif  // SKELETON_H
