#include <GraphicsPipeline.h>
#include <fstream>

namespace {

static std::vector<char> readFile(const std::string &filename) {
  std::ifstream file(filename, std::ios::ate | std::ios::binary);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file!");
  }
  size_t fileSize = (size_t)file.tellg();
  std::vector<char> buffer(fileSize);
  file.seekg(0);

  file.read(buffer.data(), fileSize);
  file.close();

  return buffer;
}

}; // namespace

GraphicsPipeline::GraphicsPipeline() {}

GraphicsPipeline::~GraphicsPipeline() {}

void GraphicsPipeline::createGraphicsPipeline(Device device) {
  auto vertShaderCode = readFile(SHADERS_DIR "/shader.vert.spv");
  auto fragShaderCode = readFile(SHADERS_DIR "/shader.frag.spv");
}

void GraphicsPipeline::destroyGraphicsPipeline(Device device) {}
