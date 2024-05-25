#pragma once

#include "bacchus/core.hpp"
#include "bacchus/events/event.hpp"

namespace bacchus {
    using EventFn = std::function<void(Event&)>;

    struct WindowProps {
        uint32_t width, height;
        const char* title;
        WindowProps(uint32_t width = 640, uint32_t height = 480, const char* title = "Bacchus") {
            this->width = width;
            this->height = height;
            this->title = title;
        }
    };

    struct Window {
        static Window* create(WindowProps props = WindowProps());
        virtual ~Window() = default;
        virtual void update() = 0;
        virtual void set_event_handler(EventFn handler) = 0;
    };
}
