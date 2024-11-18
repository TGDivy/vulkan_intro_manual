#pragma once

#include <GLFW/glfw3.h>

class Window {
public:
  void initWindow(int width, int height, const char *title);
  GLFWwindow *getWindow() const;

private:
  GLFWwindow *window;
};
