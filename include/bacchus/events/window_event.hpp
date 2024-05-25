#pragma once

#include "bacchus/events/event.hpp"
#include <sstream>

namespace bacchus {
    struct WindowResizeEvent : Event {
        unsigned int width, height;
        WindowResizeEvent(unsigned int width, unsigned int height) {
            this->width = width;
            this->height = height;
        }
        BA_EVENT_CLASS_TYPE(WINDOW_RESIZE);

        virtual std::string to_string() const override {
            std::stringstream ss;
            ss << "Window Resize: " << width << ", " << height;
            return ss.str();
        }
    };
}
