#pragma once

#include <cstdint>
#include <vulkan/vulkan_core.h>
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

  void createFramebuffers();
  void createCommandPool();
  void createCommandBuffer();
  void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

  GLFWwindow *window;
  VkInstance instance;
  VkSurfaceKHR surface;
  VkCommandPool commandPool;
  VkCommandBuffer commandBuffer;
  std::vector<VkFramebuffer> swapChainFramebuffers;

  Device device;
  SwapChain swapChain;
  GraphicsPipeline graphicsPipeline;
};
