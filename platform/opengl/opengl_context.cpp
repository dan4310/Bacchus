#include "opengl_context.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace bacchus {
    OpenGlContext::OpenGlContext(GLFWwindow* window) {
        this->_window = window;
        glfwMakeContextCurrent(_window);
        auto ok = glewInit();
        BA_CORE_ASSERT(ok == GLEW_OK, "initialize GLEW");
    }

    void OpenGlContext::set_current() {
        glfwMakeContextCurrent(_window);
    }

    void OpenGlContext::swap() const {
        glfwSwapBuffers(_window);
    }
}
