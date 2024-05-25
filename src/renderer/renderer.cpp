#include "bacchus/renderer/renderer.hpp"

namespace bacchus {
    void Renderer::create() {
        RenderCommand::create();
    }

    void Renderer::shutdown() {
        RenderCommand::shutdown();
    }
}
