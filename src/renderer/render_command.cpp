#include "bacchus/renderer/render_command.hpp"

namespace bacchus {
    RendererApi* RenderCommand::_API = nullptr;

    void RenderCommand::create() {
        BA_CORE_ASSERT(_API == nullptr, "Renderer API already created");
        _API = RendererApi::create();
    }

    void RenderCommand::shutdown() {
        delete _API;
    }
}
