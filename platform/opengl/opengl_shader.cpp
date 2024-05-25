#include "opengl_shader.hpp"

#include <GL/glew.h>
#include <vector>

namespace bacchus {
    static GLenum batogl_type(ShaderType type) {
        switch (type) {
            case ShaderType::VERTEX: return GL_VERTEX_SHADER;
            case ShaderType::FRAGMENT: return GL_FRAGMENT_SHADER;
            default: BA_CORE_ASSERT(false, "OpenGL shader type not implemented");
        }
        return 0;
    }

    static ShaderType gltoba_type(GLenum type) {
        switch (type) {
            case GL_VERTEX_SHADER: return ShaderType::VERTEX;
            case GL_FRAGMENT_SHADER: return ShaderType::FRAGMENT;
            default: BA_CORE_ASSERT(false, "OpenGL shader type not implemented");
        }
        return ShaderType::VERTEX;
    }

    OpenGlShader::OpenGlShader(const char* src, ShaderType type) {
        _type = batogl_type(type);
        _shader = glCreateShader(_type);
        glShaderSource(_shader, 1, &src, NULL);
        glCompileShader(_shader);
        GLint ok;
        glGetShaderiv(_shader, GL_COMPILE_STATUS, &ok);
        if (!ok) {
            GLint log_len = 0;
            glGetShaderiv(_shader, GL_INFO_LOG_LENGTH, &log_len);
            auto log = std::vector<char>(log_len + 1);
            glGetShaderInfoLog(_shader, log_len, &log_len, log.data());
            log[log_len] = '\0';
            BA_CORE_ERROR("OpenGL: {}", src);
            BA_CORE_ASSERT(false, "create OpenGL shader");
        }
    }

    OpenGlShader::~OpenGlShader() {
        glDeleteShader(_shader);
    }

    ShaderType OpenGlShader::get_type() const {
        return gltoba_type(_type);
    }
}
