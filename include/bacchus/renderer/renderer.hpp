#pragma once

#include "bacchus/renderer/render_command.hpp"

namespace bacchus {
    struct Renderer {
        static void create();
        static void shutdown();
    };
}
