#pragma once

#include "bacchus/renderer/shader.hpp"
#include <initializer_list>

namespace bacchus {
    struct ShaderProgram {
        static ShaderProgram* create(std::initializer_list<Shader*> shaders);
        virtual ~ShaderProgram() = default;
        virtual void bind() const = 0;
        virtual void unbind() const = 0;
    };
}
