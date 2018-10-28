#if !defined(SKELETON_H)
#define SKELETON_H

#include <string>
#include <vector>
#include <ostream>

/**
 * @brief Skeleton Base class
 * 
 */
class Skeleton {
public:  /// somehing ///
    typedef struct Version_s {
        int major;
        int minor;
        int patch;
        int compile;
    } Version_t, *Version_p;

    // Public Interface
    Skeleton(){};
    virtual ~Skeleton(){};
    virtual int main() = 0;
    virtual int main(int argv, char* argc[]) = 0;
    virtual int main(std::vector<std::string>& params) = 0;
    virtual int size() = 0;
    virtual const std::string name() = 0;
    virtual void help() = 0;
    virtual std::string name() const = 0;
    virtual void name(const std::string& name) = 0;
    virtual Version_t version() const = 0;
    virtual void version(const Version_t& version) = 0;

protected:
    // Private data members
    std::string app_name;
    std::vector<std::string> app_description;

    Version_t version_number;
};

/**
 * @brief Eric: Add brief
 * 
 * @param out the output stream 
 * @param obj the object being written to the output stream
 * @return std::ostream& 
 */
inline std::ostream& operator<<(std::ostream& out, const Skeleton::Version_t& obj)
{
    return out << obj.major << "." << obj.minor << "." << obj.patch << "." << obj.compile;
}

#endif  // Skeleton_H
