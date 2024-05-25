
#include <GL/glew.h>
#include <iostream>
#include "bacchus/app.hpp"
#include "bacchus/events/key_event.hpp"
#include "bacchus/renderer/render_command.hpp"
#include "bacchus/renderer/shader.hpp"
#include "bacchus/renderer/shader_program.hpp"

using namespace bacchus;

struct Vertex {
    glm::vec3 position, color;
};

static const Vertex vertices[3] = {
    { { 0.5f, 0.5f, 0.0f }, { 1.0f, 0.0f, 0.0f } },
    { { 0.5f, -0.5f, 0.0f }, { 0.0f, 1.0f, 0.0f } },
    { { -0.5f, -0.5f, 0.0f }, { 0.0f, 0.0f, 1.0f } },
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
    GLuint _vertex_array, _vertex_buffer;
    DemoLayer() : Layer("Demo Layer") {}

    virtual void attach() override {
        auto color = glm::vec4(0.5f, 0.5f, 0.75f, 1.0f);
        RenderCommand::set_clear_color(color);
        _program = ShaderProgram::create({
            Shader::create(vert_shader_src, ShaderType::VERTEX),
            Shader::create(frag_shader_src, ShaderType::FRAGMENT),
        });

        glGenBuffers(1, &_vertex_buffer);
        glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        
        glGenVertexArrays(1, &_vertex_array);
        glBindVertexArray(_vertex_array);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
                              sizeof(Vertex), (void*) offsetof(Vertex, position));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
                          sizeof(Vertex), (void*) offsetof(Vertex, color));
        BA_INFO("Demo layer attached");
    }

    virtual void detach() override {
        glDeleteVertexArrays(1, &_vertex_array);
        glDeleteBuffers(1, &_vertex_buffer);
        delete _program;
        BA_INFO("Demo layer detached");
    }
    
    virtual void update() override {
        auto window = App::get()->get_window();
        RenderCommand::set_viewport(window->get_width(), window->get_height());
        RenderCommand::clear();
        _program->bind();
        glBindVertexArray(_vertex_array);
        glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices));
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
