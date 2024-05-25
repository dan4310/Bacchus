#include <iostream>
#include "bacchus/app.hpp"
#include "bacchus/events/key_event.hpp"

using namespace bacchus;

struct DemoLayer : Layer {
    DemoLayer() : Layer("Demo Layer") {}
    virtual void attach() override {
        BA_INFO("Demo layer attached");
    }

    virtual void detach() override {
        BA_INFO("Demo layer detached");
    }
    
    virtual void update() override {

    }

    virtual bool handle_event(Event& event) override {
        if (event.get_type() != EventType::MOUSE_MOVE)
            BA_CORE_TRACE("{}", event.to_string());
        
        switch (event.get_type()) {
            case EventType::KEY_PRESS: {
                auto ev = static_cast<KeyPressEvent&>(event);
                if (ev.key == BA_KEY_Q) App::get()->shutdown();
                break;
            }
            default: break;
        }
        return false;
    }
};

int main() {
    Log::init();
    auto app = App();
    app.push_layer(new DemoLayer());
    app.run();
    return 0;
}
