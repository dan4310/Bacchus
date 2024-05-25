#include "glfw_window.hpp"
#include "bacchus/events/key_event.hpp"
#include "bacchus/events/mouse_event.hpp"
#include "bacchus/events/window_event.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace bacchus {
    static uint32_t _NUM_WINDOWS = 0;

    static void error_callback(int error, const char* description) {
        BA_CORE_ERROR("GLFW Error ({}): {}", error, description);
    }

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        auto data = static_cast<GlfwWindowData*>(glfwGetWindowUserPointer(window));
        if (data == nullptr || data->event_handler == nullptr) return;

        switch (action) {
            case GLFW_PRESS: {
                auto ev = KeyPressEvent(key);
                data->event_handler(ev);
                break;
            }
            case GLFW_RELEASE: {
                auto ev = KeyReleaseEvent(key);
                data->event_handler(ev);
                break;
            }
            default: break;
        }
    }

    static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
        auto data = static_cast<GlfwWindowData*>(glfwGetWindowUserPointer(window));
        if (data == nullptr || data->event_handler == nullptr) return;
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        switch (action) {
            case GLFW_PRESS: {
                auto ev = MousePressEvent(button, xpos, ypos);
                data->event_handler(ev);
                break;
            }
            case GLFW_RELEASE: {
                auto ev = MouseReleaseEvent(button, xpos, ypos);
                data->event_handler(ev);
                break;
            }
        }
    }

    static void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos) {
        auto data = static_cast<GlfwWindowData*>(glfwGetWindowUserPointer(window));
        if (data == nullptr || data->event_handler == nullptr) return;
        auto ev = MouseMoveEvent(xpos, ypos);
        data->event_handler(ev);
    }

    static void window_size_callback(GLFWwindow* window, int width, int height) {
        auto data = static_cast<GlfwWindowData*>(glfwGetWindowUserPointer(window));
        if (data == nullptr || data->event_handler == nullptr) return;
        data->height = height;
        data->width = width;
        auto ev = WindowResizeEvent(width, height);
        data->event_handler(ev);
    }

    GlfwWindow::GlfwWindow(WindowProps props) {
        if (_NUM_WINDOWS == 0) {
            glfwSetErrorCallback(error_callback);
            auto ok = glfwInit();
            BA_CORE_ASSERT(ok, "initialize GLFW");
            BA_CORE_INFO("successfully initialize GLFW");
        }
        _window = glfwCreateWindow(props.width, props.height, props.title, NULL, NULL);
        BA_CORE_ASSERT(_window, "create GLFW window");
        _NUM_WINDOWS++;
        BA_CORE_INFO("successfully created GLFW window");

        _data.width = props.width;
        _data.height = props.height;
        glfwSetWindowUserPointer(_window, &_data);
        glfwSetKeyCallback(_window, key_callback);
        glfwSetMouseButtonCallback(_window, mouse_button_callback);
        glfwSetCursorPosCallback(_window, cursor_pos_callback);
        glfwSetWindowSizeCallback(_window, window_size_callback);
    }

    GlfwWindow::~GlfwWindow() {
        glfwDestroyWindow(_window);
        _NUM_WINDOWS--;
        BA_CORE_INFO("destroyed GLFW window");
        if (_NUM_WINDOWS == 0) {
            glfwTerminate();
            BA_CORE_INFO("terminated GLFW window");
        }
    }

    void GlfwWindow::update() {
        glfwPollEvents();
    }

    Window* Window::create(WindowProps props) {
        return new GlfwWindow(props);
    }
}
