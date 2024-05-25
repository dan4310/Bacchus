#include "bacchus/app.hpp"
#include "bacchus/renderer/renderer.hpp"

namespace bacchus {
    App* App::_INSTANCE = nullptr;

    void App::handle_event(Event& event) {
        for (auto layer : _layer_stack)
            if (layer->handle_event(event)) break;
    }

    App::App() {
        BA_CORE_ASSERT(_INSTANCE == nullptr, "App already created!");
        Renderer::create();
        _window = Window::create();
        _window->set_event_handler(BA_BIND_EVENT_FN(handle_event));
        _INSTANCE = this;
    }

    App::~App() {
        delete _window;
        Renderer::shutdown();
    }

    void App::run() {
        while (_is_running) {
            for (auto layer : _layer_stack)
                layer->update();
            _window->update();
        }
    }

    void App::push_layer(Layer* layer) {
        _layer_stack.push_layer(layer);
        layer->attach();
    }

    void App::push_overlay(Layer* overlay) {
        _layer_stack.push_overlay(overlay);
        overlay->attach();
    }
}
