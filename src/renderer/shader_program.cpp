#include "bacchus/renderer/shader_program.hpp"
#include "bacchus/renderer/renderer_api.hpp"
#include "opengl/opengl_shader_program.hpp"

namespace bacchus {
    ShaderProgram* ShaderProgram::create(std::initializer_list<Shader*> shaders) {
        switch (RendererApi::get_type()) {
            case RendererApiType::OPENGL: return new OpenGlShaderProgram(shaders);
            case RendererApiType::VULKAN: BA_CORE_ASSERT(false, "Vulkan shader program not implemented");
            default: BA_CORE_ASSERT(false, "Renderer API type not implemented");
        }
        return nullptr;
    }
}
