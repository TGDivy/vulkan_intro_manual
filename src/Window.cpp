#include <Window.h>

void Window::initWindow(int width, int height, const char *title) {
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  window = glfwCreateWindow(width, height, title, nullptr, nullptr);
}

GLFWwindow *Window::getWindow() const { return window; }
