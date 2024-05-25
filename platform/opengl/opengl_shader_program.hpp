#pragma once

#include "bacchus/renderer/shader_program.hpp"

using GLuint = unsigned int;

namespace bacchus {
    struct OpenGlShaderProgram : ShaderProgram {
        GLuint _program;
        OpenGlShaderProgram(std::initializer_list<Shader*> shaders);
        virtual ~OpenGlShaderProgram() override;
        virtual void bind() const override;
        virtual void unbind() const override;
    };
}
