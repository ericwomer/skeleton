#ifndef BASE_H
#define BASE_H

#include <string>
#include <vector>

class Base {
public:  // data types
    typedef struct Version_s {
        uint8_t major;
        uint8_t minor;
        uint8_t patch;
    } Version_t, *Version_p;

    // Public Interface
    Base();
    virtual ~Base() = 0;
    virtual int main() = 0;
    virtual int main(int argv, char* argc[]) = 0;
    virtual int main(std::vector<std::string>& params) = 0;
    virtual int size() = 0;
    virtual const std::string name() = 0;
    virtual void help() = 0;
    virtual void name(std::string name) = 0;
    virtual Version_t version() = 0;

private:
    // Private data members
    std::string app_name;
    std::vector<std::string> app_description;

    Version_t versionNumber;
};

#endif  // BASE_H
