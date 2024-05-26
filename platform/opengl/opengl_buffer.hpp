#pragma once

#include "bacchus/renderer/buffer.hpp"

using GLuint = unsigned int;

namespace bacchus {
    struct OpenGlVertexBuffer : VertexBuffer {
        GLuint _vertex_buffer;
        BufferLayout _layout;
        OpenGlVertexBuffer(uint32_t size);
        OpenGlVertexBuffer(const void* data, uint32_t size);
        virtual ~OpenGlVertexBuffer();
        virtual void bind() const;
        virtual void unbind() const;
        virtual void set_data(const void* data, uint32_t size);
        virtual const BufferLayout& get_layout() const { return _layout; }
        virtual void set_layout(const BufferLayout& layout) { _layout = layout; }
    };

    struct OpenGlIndexBuffer : IndexBuffer {
        uint32_t _count;
        GLuint _index_buffer;
        OpenGlIndexBuffer(uint32_t* indicies, uint32_t count);
        virtual ~OpenGlIndexBuffer() override;
        virtual void bind() const override;
        virtual void unbind() const override;
        virtual uint32_t get_count() const override { return _count; }
    };
}
