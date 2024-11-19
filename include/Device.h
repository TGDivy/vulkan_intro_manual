#pragma once

#define GLFW_INCLUDE_VULKAN
#define VK_USE_PLATFORM_METAL_EXT
#define VK_USE_PLATFORM_MACOS_MVK

#include <GLFW/glfw3.h>
#include <vector>
#include <vulkan/vulkan_beta.h>

static const std::vector<const char *> deviceExtensions = {
    VK_KHR_SWAPCHAIN_EXTENSION_NAME, VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME};

struct QueueFamilyIndices {
  std::optional<uint32_t> graphicsFamily;
  std::optional<uint32_t> presentFamily;

  bool isComplete() {
    return graphicsFamily.has_value() && presentFamily.has_value();
  }
};

class Device {
public:
  void pickPhysicalDevice(VkInstance instance);
  void createLogicalDevice(VkSurfaceKHR surface);
  VkPhysicalDevice getPhysicalDevice() const { return physicalDevice; }
  VkDevice getDevice() const { return device; }
  QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device,
                                       VkSurfaceKHR surface);
  VkQueue getGraphicsQueue() const { return graphicsQueue; }
  VkQueue getPresentQueue() const { return presentQueue; }

private:
  bool checkDeviceExtensionSupport(VkPhysicalDevice device);
  VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
  VkDevice device = VK_NULL_HANDLE;
  VkQueue graphicsQueue;
  VkQueue presentQueue;
};
