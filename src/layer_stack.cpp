#include "bacchus/layer_stack.hpp"
#include <algorithm>

namespace bacchus {
    LayerStack::~LayerStack() {
        for (auto layer : _layers) {
            layer->detach();
            delete layer;
        }
    }

    void LayerStack::push_layer(Layer* layer) {
        _layers.emplace(_layers.begin() + _idx, layer);
        _idx++;
    }

    void LayerStack::push_overlay(Layer* overlay) {
        _layers.emplace_back(overlay);
    }

    void LayerStack::pop_layer(Layer* layer) {
        auto it = std::find(_layers.begin(), _layers.begin() + _idx, layer);
        if (it != _layers.begin() + _idx) {
            layer->detach();
            _layers.erase(it);
            _idx--;
        }
    }

    void LayerStack::pop_overlay(Layer* overlay)
    {
        auto it = std::find(_layers.begin() + _idx, _layers.end(), overlay);
        if (it != _layers.end()) {
            overlay->detach();
            _layers.erase(it);
        }
    }
}
