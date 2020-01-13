/**
 *  Log.h
 */

#ifndef SKELETON_LOG_H
#define SKELETON_LOG_H

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

/**
 * Every class that wants/needs to print ot log or fancy stdout should inherit from this class publicly.
 */
class Log {
public:
  auto info(std::string msg) -> void;
  auto warn(std::string msg) -> void;
  auto error(std::string msg) -> void;
  auto log_init(std::string name) -> void;
private:
  std::shared_ptr<spdlog::logger> m_logger;

  static std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> m_console_sink;
  static std::shared_ptr<spdlog::sinks::basic_file_sink_mt> m_file_sink;

  static bool m_sinks_created;
};

#endif  //SKELETON_LOG_H
