#include "VulkanApp.h"
#include "Window.h"
#include <vector>

#include <GLFW/glfw3.h>

#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vulkan/vulkan_core.h>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;
const std::vector<const char *> deviceExtensions = {
    VK_KHR_SWAPCHAIN_EXTENSION_NAME};

int main() {
  Window window;
  window.initWindow(WIDTH, HEIGHT, "Vulkan");

  VulkanApp app;

  try {
    app.run();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
