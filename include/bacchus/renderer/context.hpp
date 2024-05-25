#pragma once

#include "bacchus/core.hpp"

namespace bacchus {
    struct Context {
        static Context* create(void* native_window);
        virtual ~Context() = default;
        virtual void set_current() = 0;
        virtual void swap() const = 0;
    };
}
