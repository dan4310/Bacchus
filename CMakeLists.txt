cmake_minimum_required(VERSION 3.28)
project(bacchus)

add_subdirectory(lib/spdlog)
add_subdirectory(lib/glfw)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall --pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g -DBA_ENABLE_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS}")

file(GLOB GLFW_SRC platform/glfw/*.cpp)
file(GLOB_RECURSE BACCHUS_SRC src/*.cpp)
add_library(bacchus STATIC ${BACCHUS_SRC} ${GLFW_SRC})
target_include_directories(bacchus PUBLIC include)
target_link_libraries(bacchus spdlog glfw)

add_subdirectory(test)
