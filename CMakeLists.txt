cmake_minimum_required(VERSION 3.28)
project(bacchus)

set(OpenGL_GL_PREFERENCE "GLVND")

add_subdirectory(lib/spdlog)
add_subdirectory(lib/glm)
add_subdirectory(lib/glfw)
add_subdirectory(lib/glew/build/cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall --pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g -DBA_ENABLE_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS}")

file(GLOB GLFW_SRC platform/glfw/*.cpp)
file(GLOB OPENGL_SRC platform/opengl/*.cpp)
file(GLOB_RECURSE BACCHUS_SRC src/*.cpp)

set(BACCHUS_LIBRARY_TYPE "${BACCHUS_LIBRARY_TYPE}" CACHE STRING
    "Library type override for Bacchus (SHARED, STATIC, OBJECT, or empty to follow BUILD_SHARED_LIBS)")

if (BACCHUS_LIBRARY_TYPE)
    if (BACCHUS_LIBRARY_TYPE STREQUAL "SHARED")
        set(BACCHUS_BUILD_SHARED_LIBRARY TRUE)
    else()
        set(BACCHUS_BUILD_SHARED_LIBRARY FALSE)
    endif()
else()
    set(BACCHUS_BUILD_SHARED_LIBRARY ${BUILD_SHARED_LIBS})
endif()

add_library(bacchus ${BACCHUS_LIBRARY_TYPE} ${BACCHUS_SRC} ${GLFW_SRC} ${OPENGL_SRC})
target_include_directories(bacchus PUBLIC include PRIVATE platform)
target_link_libraries(bacchus spdlog glm glfw)

add_subdirectory(test)
