#include "bacchus/renderer/renderer_api.hpp"
#include "opengl/opengl_renderer_api.hpp"

namespace bacchus {
    RendererApiType RendererApi::_TYPE = RendererApiType::OPENGL;

    RendererApi* RendererApi::create() {
        switch (RendererApi::get_type()) {
            case RendererApiType::OPENGL: return new OpenGlRendererApi();
            case RendererApiType::VULKAN: BA_CORE_ASSERT(false, "Vulkan Renderer API not supported"); break;
            default: throw std::runtime_error("Renderer API type is not implemented");
        }
    }
}
