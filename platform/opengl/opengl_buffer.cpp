#include "opengl/opengl_buffer.hpp"

#include <GL/glew.h>

namespace bacchus {
    OpenGlVertexBuffer::OpenGlVertexBuffer(uint32_t size) {
        glGenBuffers(1, &_vertex_buffer);
        glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer);
        glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
    }

    OpenGlVertexBuffer::OpenGlVertexBuffer(const void* data, uint32_t size) {
        glGenBuffers(1, &_vertex_buffer);
        glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer);
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }

    OpenGlVertexBuffer::~OpenGlVertexBuffer() {
        glDeleteBuffers(1, &_vertex_buffer);
    }


    void OpenGlVertexBuffer::bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer);
    }

    void OpenGlVertexBuffer::unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }


    void OpenGlVertexBuffer::set_data(const void* data, uint32_t size) {
        bind();
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
    }


    OpenGlIndexBuffer::OpenGlIndexBuffer(uint32_t* indices, uint32_t count) {
        _count = count;
        glCreateBuffers(1, &_index_buffer);
        glBindBuffer(GL_ARRAY_BUFFER, _index_buffer);
        glBufferData(GL_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
    }

    OpenGlIndexBuffer::~OpenGlIndexBuffer() {
        glDeleteBuffers(1, &_index_buffer);
    }

    void OpenGlIndexBuffer::bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _index_buffer);
    }

    void OpenGlIndexBuffer::unbind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}
