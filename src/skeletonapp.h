#if !defined(SKELETONAPP_H)
#define SKELETONAPP_H

#include <string>
#include <vector>
#include <ostream>

#include <fstream>
#include <iostream>

#include <cstdint>
#include <algorithm>

#include "base/base.h"

namespace Application {

class SkeletonApp : public Base {
public:
    // Public Interface
    // Constructor && Destructor
    SkeletonApp();
    virtual ~SkeletonApp(){};

    // Methods
    virtual int main(std::vector<std::string>& params) override;

private:
    // Private Interface
    // Methods
    virtual int               main() override;
    virtual int               size() override { return sizeof(this); };
    virtual const std::string name() override { return app_name; };
    virtual void              help() override;
    virtual std::string       name() const override { return app_name; };
    virtual void              name(const std::string& name) override { app_name = name; };
    virtual Version_t         version() const override { return version_number; }
    virtual void              version(const Version_t& version) override { version_number = version; };

    // Data Members
    std::vector<std::string> actions;
};
}  // namespace Application
#endif  // SKELETONAPP_H