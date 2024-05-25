#pragma once

#include "bacchus/events/event.hpp"
#include "bacchus/buttons.hpp"
#include <sstream>

namespace bacchus {
    struct MouseMoveEvent : Event {
        double xpos, ypos;
        MouseMoveEvent(double xpos, double ypos) {
            this->xpos = xpos;
            this->ypos = ypos;
        }
        BA_EVENT_CLASS_TYPE(MOUSE_MOVE);
        virtual std::string to_string() const override {
            std::stringstream ss;
            ss << "Mouse Move: " << xpos << ", " << ypos;
            return ss.str();
        }
    };

    struct MouseButtonEvent : MouseMoveEvent {
        ButtonCode button;
    protected:
        MouseButtonEvent(ButtonCode button, double xpos, double ypos) : MouseMoveEvent(xpos, ypos) { this->button = button; }
    };

    struct MousePressEvent : MouseButtonEvent {
        MousePressEvent(ButtonCode button, double xpos, double ypos) : MouseButtonEvent(button, xpos, ypos) {}
        BA_EVENT_CLASS_TYPE(MOUSE_PRESS);

        virtual std::string to_string() const override {
            std::stringstream ss;
            ss << "Mouse Press: " << button << " (" << xpos << ", " << ypos << ")";
            return ss.str();
        }
    };

    struct MouseReleaseEvent : MouseButtonEvent {
        MouseReleaseEvent(ButtonCode button, double xpos, double ypos) : MouseButtonEvent(button, xpos, ypos) {}
        BA_EVENT_CLASS_TYPE(MOUSE_RELEASE);

        virtual std::string to_string() const override {
            std::stringstream ss;
            ss << "Mouse Release: " << button << " (" << xpos << ", " << ypos << ")";
            return ss.str();
        }
    };
}
