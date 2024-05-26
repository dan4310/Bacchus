#include "bacchus/renderer/vertex_array.hpp"
#include "bacchus/renderer/renderer_api.hpp"
#include "opengl/opengl_vertex_array.hpp"

namespace bacchus {
    VertexArray* VertexArray::create() {
        switch (RendererApi::get_type()) {
            case RendererApiType::OPENGL: return new OpenGlVertexArray();
            default: BA_CORE_ASSERT(false, "Vertex Array not implemented for that Renderer");
        }
        return nullptr;
    }
}
