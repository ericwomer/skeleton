//
// Created by eric on 1/13/20.
//
// #include <unordered_set>

#include "log.h"

bool Log::m_sinks_created = false;

std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> Log::m_console_sink =
    std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
std::shared_ptr<spdlog::sinks::basic_file_sink_mt> Log::m_file_sink =
    std::make_shared<spdlog::sinks::basic_file_sink_mt>("skeleton.log", true);  // Eric: Fix this with XDG in mind

auto Log::info(std::string msg) -> void
{
  m_logger->info(msg);
}

auto Log::warn(std::string msg) -> void
{
  m_logger->warn(msg);
}

auto Log::error(std::string msg) -> void
{
  m_logger->error(msg);
}

auto Log::log_init(std::string name) -> void
{
  if (!m_sinks_created) {
    m_console_sink->set_level(spdlog::level::warn);
    m_console_sink->set_pattern("[%n] [%^%l%$] %v");

    m_file_sink->set_level(spdlog::level::trace);
    m_sinks_created = true;
  }
  spdlog::sinks_init_list sink_lists = {m_file_sink, m_console_sink};

  m_logger = std::make_shared<spdlog::logger>(name, sink_lists);
  m_logger->set_level(spdlog::level::debug);

  spdlog::register_logger(m_logger);
}
