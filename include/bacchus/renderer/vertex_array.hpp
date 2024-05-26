#pragma once

#include "bacchus/renderer/buffer.hpp"

namespace bacchus {
    struct VertexArray {
        static VertexArray* create();
        virtual ~VertexArray() = default;
        virtual void bind() const = 0;
        virtual void unbind() const = 0;
        virtual void add_vertex_buffer(const VertexBuffer* buffer) = 0;
    };
}
