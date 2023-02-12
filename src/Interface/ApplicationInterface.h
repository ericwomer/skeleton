#if !defined(APPLICATIONINTERFACE_H)
#define APPLICATIONINTERFACE_H

#include <string>
#include <iostream>
#include <vector>
#include <ostream>

#include "log/log.h"

namespace ew {


class ApplicationInterface : public Log {
public:
  // Data Types
  // Version Struct
  struct Version {
    int major;
    int minor;
    int patch;
    int compile;
  };

  struct Info {
    std::string              app_name;
    std::string              executable_name;  // Exists if the app name is different than the executable
    std::vector<std::string> app_description;
    Version                  version_number;
    std::vector<std::string> actions;  // Eric: What the heck is this?
  };

  // Public Interface
  // Constructor && Destructor
  ApplicationInterface()          = default;
  virtual ~ApplicationInterface() = default;

  // Methods
  /**
   * main The main entry point for the application
   * @param argc
   * @param argv
   * @return
   */
  virtual auto main(int argc, char** argv) -> int = 0;
  virtual auto size() -> int                      = 0;
  virtual auto help() const -> void               = 0;
  virtual auto init(int argc, char** argv) -> int = 0;

  virtual auto info() const -> const Info& { return m_info; };
  virtual auto info(Info info) -> void { m_info = info; };

  virtual auto flags() -> std::vector<std::string>& { return m_flags; };
  virtual auto flags(std::vector<std::string> flags) -> void { m_flags = flags; }

  virtual auto name() const -> const std::string& { return m_info.app_name; };
  virtual auto name(const std::string& name) -> void { m_info.app_name = name; };

  virtual auto description() const -> const std::vector<std::string>& { return m_info.app_description; };
  virtual auto description(std::vector<std::string> desc) -> void { m_info.app_description = desc; };

  virtual auto version() const -> const Version& { return m_info.version_number; };
  virtual auto version(Version version) -> void { m_info.version_number = version; };

private:
  // Data Members
  Info                     m_info;
  std::vector<std::string> m_flags;  // terminal flag parameters.
};

/**
 * @brief Eric: Add brief
 *
 * @param out the output stream
 * @param obj the object being written to the output stream
 * @return std::ostream&
 */
inline auto operator<<(std::ostream& out, const ApplicationInterface::Version& obj) -> std::ostream&
{
  return out << obj.major << "." << obj.minor << "." << obj.patch << "." << obj.compile;
}

template <typename T>
inline auto operator<<(std::ostream& out, const std::vector<T>& obj) -> std::ostream&
{
  out << "[";
  for (auto i = 0; i < obj.size() - 1; ++i) {
    out << obj[i] << ", ";
  }
  out << obj[obj.size() - 1] << "]";
  return out;
}

}  // namespace ew

#endif