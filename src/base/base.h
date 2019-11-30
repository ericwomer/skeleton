#if !defined(BASE_H)
#define BASE_H

#include <string>
#include <iostream>
#include <vector>
#include <ostream>

namespace Base {

/**
 * @brief Base Base class
 *
 */
class Application {
public:
  // Data Types
  // Version Struct
  struct Version {
    int major;
    int minor;
    int patch;
    int compile;
  };

  // Public Interface
  // Constructor && Destructor
  Application();
  virtual ~Application() = default;

  // Methods
  virtual int               main(std::vector<std::string>& params);
  virtual int               size() { return sizeof(*this); };
  virtual std::string       name() const { return app_name; };
  virtual const std::string name() { return app_name; };
  virtual void              name(const std::string& name) { app_name = name; };
  virtual void              help() const;
  virtual void              version() const;
  virtual void              version(const Version& version) { version_number = version; };

private:
  // Data Members
  std::string              app_name;
  std::string              executable_name;
  std::vector<std::string> app_description;
  Version                  version_number;
  std::vector<std::string> actions;
};

/**
 * @brief Eric: Add brief
 *
 * @param out the output stream
 * @param obj the object being written to the output stream
 * @return std::ostream&
 */
inline std::ostream& operator<<(std::ostream& out, const Application::Version& obj)
{
  return out << obj.major << "." << obj.minor << "." << obj.patch << "." << obj.compile;
}

}  // namespace Base

#endif  // BASE_H
