#pragma once

#include "bacchus/renderer/renderer.hpp"
#include "bacchus/renderer/renderer_api.hpp"

namespace bacchus {
    struct RenderCommand {
        static RendererApi* _API;
        static inline RendererApi* get_api() { return _API; }
        static void create();
        static void shutdown();
        static inline void clear() { _API->clear(); }
        static inline void set_clear_color(glm::vec4& color) { _API->set_clear_color(color); }
        static inline void set_viewport(uint32_t width, uint32_t height) { _API->set_viewport(width, height); }
    };
}
