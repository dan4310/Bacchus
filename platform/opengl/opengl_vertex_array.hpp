#pragma once

#include "bacchus/renderer/vertex_array.hpp"

using GLuint = unsigned int;

namespace bacchus {
    struct OpenGlVertexArray : VertexArray {
        uint32_t _vertex_buffer_idx;
        GLuint _vertex_array;
        OpenGlVertexArray();
        virtual ~OpenGlVertexArray() override;
        virtual void bind() const override;
        virtual void unbind() const override;
        virtual void add_vertex_buffer(const VertexBuffer* buffer) override;
    };
}
