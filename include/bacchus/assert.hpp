#pragma once

#include "bacchus/core.hpp"

#if defined(BA_ENABLE_ASSERTS)
#define BA_CORE_ASSERT(x, ...) if (!(x)) { BA_CORE_ERROR("Assertion failed: " __VA_ARGS__); exit(1); }
#define BA_ASSERT(x, ...) if (!(x)) { BA_ERROR("Assertion failed: " __VA_ARGS__); exit(1); }
#else
#define BA_CORE_ASSERT(x, ...) if (!(x)) { BA_CORE_ERROR("Assertion failed: " __VA_ARGS__); throw std::runtime_error("assertion failed"); }
#define BA_ASSERT(x, ...) if (!(x)) { BA_ERROR("Assertion failed: " __VA_ARGS__); throw std::runtime_error("assertion failed"); }
#endif
