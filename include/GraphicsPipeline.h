

#include <Device.h>
#include <SwapChain.h>

class GraphicsPipeline {

public:
  GraphicsPipeline();
  ~GraphicsPipeline();

  void createRenderPass(Device device, SwapChain swapChain);
  void destroyRenderPass(Device device);

  void createGraphicsPipeline(Device device, SwapChain swapChain);
  void destroyGraphicsPipeline(Device device);

  VkPipelineLayout getPipelineLayout() { return pipelineLayout; }

private:
  VkRenderPass renderPass;
  VkPipelineLayout pipelineLayout;
};
