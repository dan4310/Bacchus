#pragma once

#include <inttypes.h>
#include <functional>

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#if defined(BA_ENABLE_DEBUG)
#define BA_ENABLE_LOGS
#define BA_ENABLE_ASSERTS
#endif

#define BA_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

#include "bacchus/log.hpp"
#include "bacchus/assert.hpp"
