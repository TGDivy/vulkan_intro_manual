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
)

# Find Vulkan SDK
find_package(Vulkan REQUIRED)

# Add GLFW
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)

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
