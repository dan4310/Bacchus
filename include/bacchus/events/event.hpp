#pragma once

#include <string>

#define BA_EVENT_CLASS_TYPE(T)\
    static inline EventType get_static_type() { return EventType::T; }\
    virtual inline EventType get_type() const override { return get_static_type(); }

namespace bacchus {
    enum EventType {
        KEY_PRESS,
        KEY_RELEASE,
        MOUSE_MOVE,
        MOUSE_PRESS,
        MOUSE_RELEASE,
        WINDOW_RESIZE
    };

    struct Event {
        virtual inline EventType get_type() const = 0;
        virtual std::string to_string() const = 0;
    };
}
