#include "opengl/opengl_vertex_array.hpp"

#include <GL/glew.h>

namespace bacchus {
    static GLenum batogl_type(DataType type) {
        switch (type) {
            case DataType::FLOAT:
            case DataType::FLOAT2:
            case DataType::FLOAT3:
            case DataType::FLOAT4:
                return GL_FLOAT;
            default: BA_CORE_ASSERT(false, "Unknown data type");
        }
    }

    OpenGlVertexArray::OpenGlVertexArray() {
        glGenVertexArrays(1, &_vertex_array);
    }

    OpenGlVertexArray::~OpenGlVertexArray() {
        glDeleteVertexArrays(1, &_vertex_array);
    }

    void OpenGlVertexArray::bind() const {
        glBindVertexArray(_vertex_array);
    }

    void OpenGlVertexArray::unbind() const {
        glBindVertexArray(0);
    }

    void OpenGlVertexArray::add_vertex_buffer(const VertexBuffer* buffer) {
        bind();
        buffer->bind();
        const auto& layout = buffer->get_layout();
        for (const auto& element : layout) {
            switch (element.type) {
                case DataType::FLOAT:
                case DataType::FLOAT2:
                case DataType::FLOAT3:
                case DataType::FLOAT4: {
                    glEnableVertexAttribArray(_vertex_buffer_idx);
                    glVertexAttribPointer(_vertex_buffer_idx,
                        element.get_component_count(),
                        batogl_type(element.type),
                        element.is_normalized ? GL_TRUE : GL_FALSE,
                        layout.get_stride(),
                        (void *)element.offset);
                    _vertex_buffer_idx++;
                    break;
                }
                default: BA_CORE_ASSERT(false, "Unknown buffer data type!");
            }
        }
    }
}
