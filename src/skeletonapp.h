#if !defined(SKELETONAPP_H)
#define SKELETONAPP_H

#include <string>
#include <vector>
#include <ostream>

#include <fstream>
#include <iostream>

#include <cstdint>
#include <algorithm>

#include "skeleton/skeleton.h"

class SkeletonApp : public Skeleton {
public:
    SkeletonApp();
    virtual ~SkeletonApp(){};
    virtual int main() override;
    virtual int main(int argv, char* argc[]) override;
    virtual int main(std::vector<std::string>& params) override;
    virtual int size() override { return sizeof(this); };
    virtual const std::string name() override { return app_name; };
    virtual void help() override;
    virtual std::string name() const override { return app_name; };
    virtual void name(const std::string& name) override { app_name = name; };
    virtual Version_t version() const override { return version_number; }
    virtual void version(const Version_t& version) override { version_number = version; };

protected:
    std::vector<std::string> actions;

    /*
    std::string app_name;
    std::vector<std::string> app_description;

    Version_t version_number;  // set with confit.h.in */
};

#endif  // SKELETONAPP_H