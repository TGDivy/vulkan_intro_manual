cmake_minimum_required(VERSION 3.16)
project(MyVulkanProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add source files
set(SOURCES
    src/main.cpp
    src/VulkanApp.cpp
    src/Window.cpp
    src/Device.cpp
    src/SwapChain.cpp
    src/GraphicsPipeline.cpp
)

# Find Vulkan SDK
find_package(Vulkan REQUIRED)

# Add GLFW
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)

# Define the path to glslc
set(GLSLC /Users/dbramhecha/VulkanSDK/1.3.296.0/macOS/bin/glslc)

# Compile shaders

# Define the path to the shaders directory
set(SHADERS_DIR "${CMAKE_SOURCE_DIR}/shaders")

# Add the preprocessor definition
add_definitions(-DSHADERS_DIR=\"${SHADERS_DIR}\")

add_custom_command(
    OUTPUT ${SHADERS_DIR}/shader.vert.spv
    COMMAND ${GLSLC} ${SHADERS_DIR}/shader.vert -o ${CMAKE_CURRENT_SOURCE_DIR}/shaders/shader.vert.spv
    DEPENDS ${SHADERS_DIR}/shader.vert
)

add_custom_command(
    OUTPUT ${SHADERS_DIR}/shader.frag.spv
    COMMAND ${GLSLC} ${SHADERS_DIR}/shader.frag -o ${CMAKE_CURRENT_SOURCE_DIR}/shaders/shader.frag.spv
    DEPENDS ${SHADERS_DIR}/shader.frag
)

add_custom_target(shaders DEPENDS ${SHADERS_DIR}/shader.vert.spv ${SHADERS_DIR}/shader.frag.spv)

# Include paths
include_directories(
    ${Vulkan_INCLUDE_DIRS}
    ${GLFW_INCLUDE_DIRS}
    include
)

# Link libraries
link_directories(${GLFW_LIBRARY_DIRS})
add_definitions(${GLFW_CFLAGS_OTHER})

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Add the shaders as a dependency
add_dependencies(${PROJECT_NAME} shaders)

# Link Vulkan and GLFW
target_link_libraries(${PROJECT_NAME}
    Vulkan::Vulkan
    ${GLFW_LIBRARIES}
)

# Platform-specific settings
if(APPLE)
    target_link_libraries(${PROJECT_NAME}
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
        "-framework Metal"
        "-framework QuartzCore"
    )
endif()
