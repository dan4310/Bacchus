#pragma once

#include "bacchus/core.hpp"

namespace bacchus {
    enum ShaderType {
        VERTEX,
        FRAGMENT
    };

    struct Shader {
        static Shader* create(const char* src, ShaderType type);
        virtual ~Shader() = default;
        virtual ShaderType get_type() const = 0;
    };
}
