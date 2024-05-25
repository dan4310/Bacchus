#include "opengl/opengl_shader_program.hpp"
#include "opengl/opengl_shader.hpp"

#include <GL/glew.h>

namespace bacchus {
    OpenGlShaderProgram::OpenGlShaderProgram(std::initializer_list<Shader*> shaders) {
        _program = glCreateProgram();
        for (auto shader : shaders) {
            auto gl_shader = static_cast<OpenGlShader*>(shader);
            glAttachShader(_program, gl_shader->_shader);
        }

        glLinkProgram(_program);
        GLint ok;
        glGetProgramiv(_program, GL_LINK_STATUS, &ok);
        if (!ok) {
            GLint log_len;
            glGetProgramiv(_program, GL_INFO_LOG_LENGTH, &log_len);
            auto info = std::vector<char>(log_len + 1);
            glGetProgramInfoLog(_program, log_len, &log_len, info.data());
            info[log_len] = '\0';
            BA_CORE_ERROR("OpenGL failed to link shader program: {}", info.data());
            BA_CORE_ASSERT(false, "create OpenGL shader program");
        }
        for (auto shader : shaders) {
            auto gl_shader = static_cast<OpenGlShader*>(shader);
            glDetachShader(_program, gl_shader->_shader);
            delete shader;
        }
    }

    OpenGlShaderProgram::~OpenGlShaderProgram() {
        glDeleteProgram(_program);
    }

    void OpenGlShaderProgram::bind() const {
        glUseProgram(_program);
    }

    void OpenGlShaderProgram::unbind() const {
        glUseProgram(_program);
    }
}
