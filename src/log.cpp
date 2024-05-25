#include "bacchus/log.hpp"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace bacchus {
    std::shared_ptr<spdlog::logger> Log::_CORE_LOGGER = nullptr;
    std::shared_ptr<spdlog::logger> Log::_CLIENT_LOGGER = nullptr;

    void Log::init() {
        _CORE_LOGGER = spdlog::stdout_color_mt("CORE");
        _CORE_LOGGER->set_level(spdlog::level::trace);
        _CORE_LOGGER->set_pattern("[%Y-%m-%d %H:%M:%S.%e %n %^%l%$ %s:%#] %v");

        _CLIENT_LOGGER = spdlog::stdout_color_mt("APP");
        _CLIENT_LOGGER->set_level(spdlog::level::trace);
        _CLIENT_LOGGER->set_pattern("[%Y-%m-%d %H:%M:%S.%e %n %^%l%$ %s:%#] %v");
    }
}
