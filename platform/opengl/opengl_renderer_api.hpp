#pragma once

#include "bacchus/renderer/renderer_api.hpp"

namespace bacchus {
    struct OpenGlRendererApi : RendererApi {
        virtual void clear() const override;
        virtual void set_clear_color(glm::vec4& color) override;
        virtual void set_viewport(uint32_t width, uint32_t height) override;
        virtual void draw_indexed(uint32_t count) const override;
    };
}
