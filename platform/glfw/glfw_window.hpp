#pragma once

#include "bacchus/window.hpp"

struct GLFWwindow;

namespace bacchus {
    struct GlfwWindowData {
        uint32_t width, height;
        EventFn event_handler;
    };

    struct GlfwWindow : Window {
        GLFWwindow* _window;
        GlfwWindowData _data;
        GlfwWindow(WindowProps = WindowProps());
        virtual ~GlfwWindow() override;
        virtual void update() override;
        virtual inline void set_event_handler(EventFn handler) override { _data.event_handler = handler; }
    };
}
