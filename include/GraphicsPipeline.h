

#include <Device.h>
#include <SwapChain.h>

class GraphicsPipeline {

public:
  GraphicsPipeline();
  ~GraphicsPipeline();

  void createGraphicsPipeline(Device device);
  void destroyGraphicsPipeline(Device device);

private:
};
