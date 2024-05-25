#pragma once

#include "bacchus/core.hpp"

namespace bacchus {
    enum RendererApiType {
        OPENGL,
        VULKAN
    };

    struct RendererApi {
        static RendererApiType _TYPE;
        static inline RendererApiType get_type() { return _TYPE; }
        static RendererApi* create();
        virtual ~RendererApi() = default;
        virtual void clear() const = 0;
        virtual void set_clear_color(glm::vec4& color) = 0;
        virtual void set_viewport(uint32_t width, uint32_t height) = 0;
    };
}
