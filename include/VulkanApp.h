#pragma once

#define GLFW_INCLUDE_VULKAN
#define VK_USE_PLATFORM_METAL_EXT
#define VK_USE_PLATFORM_MACOS_MVK

#include <Device.h>
#include <GLFW/glfw3.h>
#include <GraphicsPipeline.h>
#include <SwapChain.h>

class VulkanApp {
public:
  void run();

  VulkanApp(GLFWwindow *window) : window(window) {}

private:
  void initVulkan();
  void mainLoop();
  void cleanup();

  void createInstance();
  void createSurface();

  void createGraphicsPipeline();
  void createRenderPass();
  void createFramebuffers();
  void createCommandPool();

  GLFWwindow *window;
  VkInstance instance;
  VkSurfaceKHR surface;
  Device device;
  SwapChain swapChain;
  GraphicsPipeline graphicsPipeline;
};
