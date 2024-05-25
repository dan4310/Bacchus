#include "bacchus/renderer/shader.hpp"
#include "bacchus/renderer/renderer_api.hpp"
#include "opengl/opengl_shader.hpp"

namespace bacchus {
    Shader* Shader::create(const char* src, ShaderType type) {
        switch (RendererApi::get_type()) {
            case RendererApiType::OPENGL: return new OpenGlShader(src, type);
            case RendererApiType::VULKAN: BA_CORE_ASSERT(false, "Vulkan shader not implemented!");
            default: BA_CORE_ASSERT(false, "Renderer API type not implemented");
        }
        return nullptr;
    }
}
