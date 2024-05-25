#include "bacchus/renderer/context.hpp"
#include "bacchus/renderer/renderer_api.hpp"
#include "opengl/opengl_context.hpp"

namespace bacchus {
    Context* Context::create(void* native_window) {
        switch (RendererApi::get_type()) {
            case RendererApiType::OPENGL: return new OpenGlContext(static_cast<GLFWwindow*>(native_window));
            case RendererApiType::VULKAN: BA_CORE_ASSERT(false, "Vulkan context not implemented"); break;
            default: throw std::runtime_error("Renderer API type is not implemented");
        }
        return nullptr;
    }
}
