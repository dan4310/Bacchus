#pragma once

#include "bacchus/events/event.hpp"

namespace bacchus {
    struct Layer {
        const char* _name;
        Layer(const char* name) { this->_name = name; }
        virtual ~Layer() = default;
        virtual void attach() {}
        virtual void detach() {}
        virtual void update() {}
        virtual bool handle_event(Event& event) { return false; }
    };
}
