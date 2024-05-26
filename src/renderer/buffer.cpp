#include "bacchus/renderer/buffer.hpp"
#include "bacchus/renderer/renderer_api.hpp"
#include "opengl/opengl_buffer.hpp"

namespace bacchus {
    VertexBuffer* VertexBuffer::create(uint32_t size) {
        switch (RendererApi::get_type()) {
            case RendererApiType::OPENGL: return new OpenGlVertexBuffer(size);
            default: BA_CORE_ASSERT(false, "Unknown renderer type");
        }
        return nullptr;
    }

    VertexBuffer* VertexBuffer::create(const void* data, uint32_t size) {
        switch (RendererApi::get_type()) {
            case RendererApiType::OPENGL: return new OpenGlVertexBuffer(data, size);
            default: BA_CORE_ASSERT(false, "Unknown renderer type");
        }
        return nullptr;
    }

    IndexBuffer* IndexBuffer::create(uint32_t* indices, uint32_t count) {
        switch (RendererApi::get_type()) {
            case RendererApiType::OPENGL: return new OpenGlIndexBuffer(indices, count);
            default: BA_CORE_ASSERT(false, "Unknown renderer type");
        }
        return nullptr;
    }
}
