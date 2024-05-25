#pragma once

#include "bacchus/renderer/context.hpp"
#include "bacchus/window.hpp"

struct GLFWwindow;

namespace bacchus {
    struct GlfwWindowData {
        uint32_t width, height;
        EventFn event_handler;
    };

    struct GlfwWindow : Window {
        Context* _context;
        GLFWwindow* _window;
        GlfwWindowData _data;
        GlfwWindow(WindowProps = WindowProps());
        virtual ~GlfwWindow() override;
        virtual void update() override;
        virtual inline void set_event_handler(EventFn handler) override { _data.event_handler = handler; }
        virtual inline uint32_t get_width() const override { return _data.width; }
        virtual inline uint32_t get_height() const override { return _data.height; } 
    };
}
