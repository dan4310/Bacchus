#include "opengl_renderer_api.hpp"

#include <GL/glew.h>

namespace bacchus {
    void OpenGlRendererApi::clear() const {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void OpenGlRendererApi::set_clear_color(glm::vec4& color) {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void OpenGlRendererApi::set_viewport(uint32_t width, uint32_t height) {
        glViewport(0, 0, width, height);
    }
}
