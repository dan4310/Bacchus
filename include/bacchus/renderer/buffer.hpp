#pragma once

#include "bacchus/core.hpp"
#include <initializer_list>

namespace bacchus {
    enum DataType {
        FLOAT, FLOAT2, FLOAT3, FLOAT4
    };

    static inline uint32_t data_type_component_count(DataType type) {
        switch (type) {
            case DataType::FLOAT: return 1;
            case DataType::FLOAT2: return 2;
            case DataType::FLOAT3: return 3;
            case DataType::FLOAT4: return 4;
            default: BA_CORE_ASSERT(false, "Unknown data type");
        }
        return 0;
    }

    static inline size_t data_type_size(DataType type) {
        switch (type) {
            case DataType::FLOAT: return 4;
            case DataType::FLOAT2: return 4 * 2;
            case DataType::FLOAT3: return 4 * 3;
            case DataType::FLOAT4: return 4 * 4;
            default: BA_CORE_ASSERT(false, "Uknown data type");
        }
        return 0;
    }

    struct BufferElement {
        DataType type;
        bool is_normalized = false;
        uint32_t size;
        size_t offset;
        BufferElement() = default;
        BufferElement(DataType type, bool is_normalized = false) {
            this->type = type;
            this->is_normalized = is_normalized;
        }
        inline uint32_t get_component_count() const { return data_type_component_count(type); }
        inline size_t get_size() const { return data_type_size(type); }
    };

    struct BufferLayout {
        std::vector<BufferElement> _elements;
        uint32_t _stride = 0;

        BufferLayout() {}
        BufferLayout(std::initializer_list<BufferElement> elements) {
            _elements = elements;
            size_t offset = 0, size = 0;
            _stride = 0;
            for (auto& element : _elements) {
                element.offset = offset;
                size = element.get_size();
                offset += size;
                _stride += size;
            }
        }

        inline const std::vector<BufferElement> get_elements() const { return _elements; }
        inline uint32_t get_stride() const { return _stride; }

        std::vector<BufferElement>::iterator begin() { return _elements.begin(); }
        std::vector<BufferElement>::iterator end() { return _elements.end(); }
        std::vector<BufferElement>::const_iterator begin() const { return _elements.begin(); }
        std::vector<BufferElement>::const_iterator end() const { return _elements.end(); }
    };

    struct VertexBuffer {
        static VertexBuffer* create(uint32_t size);
        static VertexBuffer* create(const void* data, uint32_t size);
        virtual ~VertexBuffer() = default;
        virtual void bind() const = 0;
        virtual void unbind() const = 0;
        virtual void set_data(const void* data, uint32_t size) = 0;
        virtual const BufferLayout& get_layout() const = 0;
        virtual void set_layout(const BufferLayout& layout) = 0;
    };

    struct IndexBuffer {
        static IndexBuffer* create(uint32_t* indices, uint32_t count);
        virtual ~IndexBuffer() = default;
        virtual uint32_t get_count() const = 0;
        virtual void bind() const = 0;
        virtual void unbind() const = 0;
    };
}
