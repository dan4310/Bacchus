#pragma once

#include "bacchus/core.hpp"
#include "bacchus/window.hpp"
#include "bacchus/layer_stack.hpp"

namespace bacchus {
    struct App {
        static App* _INSTANCE;
        static inline App* get() { return _INSTANCE; }
        Window* _window;
        LayerStack _layer_stack;
        bool _is_running = true;
        App();
        ~App();
        void run();
        void handle_event(Event& event);
        void push_layer(Layer* layer);
        void push_overlay(Layer* overlay);
        inline void shutdown() { _is_running = false; }
        inline Window* get_window() { return _window; }
    };
}
