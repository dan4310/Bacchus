#pragma once

#include "bacchus/renderer/context.hpp"

struct GLFWwindow;

namespace bacchus {
    struct OpenGlContext : Context {
        GLFWwindow* _window;
        OpenGlContext(GLFWwindow* window);
        virtual void set_current() override;
        virtual void swap() const override;
    };
}
