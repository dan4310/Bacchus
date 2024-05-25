#pragma once

#include <sstream>
#include "bacchus/events/event.hpp"
#include "bacchus/keys.hpp"

namespace bacchus {
    struct KeyEvent : Event {
        KeyCode key;
    protected:
        KeyEvent(KeyCode key) { this->key = key; }
    };

    struct KeyPressEvent : KeyEvent {
        BA_EVENT_CLASS_TYPE(KEY_PRESS);
        KeyPressEvent(KeyCode key) : KeyEvent(key) {}

        virtual std::string to_string() const override {
            std::stringstream ss;
            ss << "Key Press: ";
            if (key & 0xF00) ss << key;
            else ss << static_cast<char>(key);
            ss << " (0x" << std::hex << key << ")";
            return ss.str();
        }
    };

    struct KeyReleaseEvent : KeyEvent {
        BA_EVENT_CLASS_TYPE(KEY_RELEASE);
        KeyReleaseEvent(KeyCode key) : KeyEvent(key) {}

        virtual std::string to_string() const override {
            std::stringstream ss;
            ss << "Key Release: ";
            if (key & 0xF00) ss << key;
            else ss << static_cast<char>(key);
            ss << " (0x" << std::hex << key << ")";
            return ss.str();
        }
    };
}
