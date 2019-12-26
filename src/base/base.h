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
  virtual auto main(std::vector<std::string>& params) -> int;
  virtual auto size() -> int { return sizeof(*this); };
  virtual auto name() -> const std::string { return app_name; };
  virtual auto name(const std::string& name) -> void { app_name = name; };

  virtual auto help() const -> void;
  virtual auto version() const -> void;

  virtual auto version(const Version& version) -> void { version_number = version; };

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
inline auto operator<<(std::ostream& out, const Application::Version& obj) -> std::ostream&
{
  return out << obj.major << "." << obj.minor << "." << obj.patch << "." << obj.compile;
}

}  // namespace Base

#endif  // BASE_H
