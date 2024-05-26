#include <iostream>
#include "bacchus/app.hpp"
#include "bacchus/events/key_event.hpp"
#include "bacchus/renderer/buffer.hpp"
#include "bacchus/renderer/render_command.hpp"
#include "bacchus/renderer/shader.hpp"
#include "bacchus/renderer/shader_program.hpp"
#include "bacchus/renderer/vertex_array.hpp"

using namespace bacchus;

struct Vertex {
    glm::vec3 position, color;
};

static const Vertex vertices[3] = {
    { { 0.5f, 0.5f, 0.0f }, { 1.0f, 0.0f, 0.0f } },
    { { 0.5f, -0.5f, 0.0f }, { 0.0f, 1.0f, 0.0f } },
    { { -0.5f, -0.5f, 0.0f }, { 0.0f, 0.0f, 1.0f } },
};

static uint32_t indices[3] = {
    0, 1, 2
};

static const char* vert_shader_src = "#version 430\n"
    "layout (location = 0) in vec3 v_pos;\n"
    "layout (location = 1) in vec3 v_color;\n"
    "out vec3 f_color;\n"
    "void main() {\n"
    "gl_Position = vec4(v_pos, 1.0);\n"
    "f_color = vec3(v_color);\n"
    "}\n";

static const char* frag_shader_src = "#version 430\n"
    "in vec3 f_color;\n"
    "out vec4 color;\n"
    "void main() {\n"
    "color = vec4(f_color, 1.0);\n"
    "}\n";

struct DemoLayer : Layer {
    ShaderProgram* _program;
    VertexArray* _vertex_array;
    VertexBuffer* _vertex_buffer;
    IndexBuffer* _index_buffer;
    DemoLayer() : Layer("Demo Layer") {}

    virtual void attach() override {
        auto color = glm::vec4(0.5f, 0.5f, 0.75f, 1.0f);
        RenderCommand::set_clear_color(color);
        _program = ShaderProgram::create({
            Shader::create(vert_shader_src, ShaderType::VERTEX),
            Shader::create(frag_shader_src, ShaderType::FRAGMENT),
        });
        _vertex_array = VertexArray::create();
        _vertex_buffer = VertexBuffer::create(vertices, sizeof(vertices));
        _index_buffer = IndexBuffer::create(indices, sizeof(indices));
        _vertex_buffer->set_layout(BufferLayout({
            BufferElement(DataType::FLOAT3),
            BufferElement(DataType::FLOAT3),
        }));
        _vertex_array->add_vertex_buffer(_vertex_buffer);

        _vertex_array->bind();
        _index_buffer->bind();

        BA_INFO("Demo layer attached");
    }

    virtual void detach() override {
        delete _index_buffer;
        delete _vertex_buffer;
        delete _vertex_array;
        delete _program;
        BA_INFO("Demo layer detached");
    }

    virtual void update() override {
        auto window = App::get()->get_window();
        RenderCommand::set_viewport(window->get_width(), window->get_height());
        RenderCommand::clear();
        _program->bind();
        RenderCommand::draw_indexed(sizeof(indices));
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
