#pragma once

#include "bacchus/renderer/shader.hpp"

using GLuint = unsigned int;
using GLenum = unsigned int;

namespace bacchus {
    struct OpenGlShader : Shader {
        GLuint _shader;
        GLenum _type;
        OpenGlShader(const char* src, ShaderType type);
        virtual ~OpenGlShader() override;
        virtual ShaderType get_type() const override;
    };
}
