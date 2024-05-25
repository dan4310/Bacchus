#pragma once

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include <spdlog/spdlog.h>
#include "bacchus/core.hpp"

namespace bacchus {
    struct Log {
        static std::shared_ptr<spdlog::logger> _CORE_LOGGER;
        static std::shared_ptr<spdlog::logger> _CLIENT_LOGGER;
        static void init();
        static inline std::shared_ptr<spdlog::logger>& get_core_logger() { return _CORE_LOGGER; }
        static inline std::shared_ptr<spdlog::logger>& get_client_logger() { return _CLIENT_LOGGER; }
    };
}


#if defined(BA_ENABLE_LOGS)
#define BA_CORE_ERROR(...) SPDLOG_LOGGER_ERROR(bacchus::Log::get_core_logger(), __VA_ARGS__)
#define BA_CORE_WARN(...) SPDLOG_LOGGER_WARN(bacchus::Log::get_core_logger(), __VA_ARGS__)
#define BA_CORE_INFO(...) SPDLOG_LOGGER_INFO(bacchus::Log::get_core_logger(), __VA_ARGS__)
#define BA_CORE_DEBUG(...) SPDLOG_LOGGER_DEBUG(bacchus::Log::get_core_logger(), __VA_ARGS__)
#define BA_CORE_TRACE(...) SPDLOG_LOGGER_TRACE(bacchus::Log::get_core_logger(), __VA_ARGS__)

#define BA_ERROR(...) SPDLOG_LOGGER_ERROR(bacchus::Log::get_client_logger(), __VA_ARGS__)
#define BA_WARN(...) SPDLOG_LOGGER_WARN(bacchus::Log::get_client_logger(), __VA_ARGS__)
#define BA_INFO(...) SPDLOG_LOGGER_INFO(bacchus::Log::get_client_logger(), __VA_ARGS__)
#define BA_DEBUG(...) SPDLOG_LOGGER_DEBUG(bacchus::Log::get_client_logger(), __VA_ARGS__)
#define BA_TRACE(...) SPDLOG_LOGGER_TRACE(bacchus::Log::get_client_logger(), __VA_ARGS__)
#else
#define BA_CORE_ERROR(...)
#define BA_CORE_WARN(...)
#define BA_CORE_INFO(...)
#define BA_CORE_DEBUG(...)
#define BA_CORE_TRACE(...)

#define BA_ERROR(...)
#define BA_WARN(...)
#define BA_INFO(...)
#define BA_DEBUG(...)
#define BA_TRACE(...)
#endif
