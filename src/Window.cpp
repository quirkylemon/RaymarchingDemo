// #include <glad/glad.h>

#include "Window.h"
#include <GLFW/glfw3.h>
#include <iostream>

Window::Window(int width, int height, const char* title, int versionMajor, int versionMinor, int openGlProfile) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, versionMajor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, versionMinor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, openGlProfile);

    _window = glfwCreateWindow(width, height, title, NULL, NULL);

    if (_window == NULL) {
        initSuccess = false;
        std::cout << "Failed to create window" << "\n";
        glfwTerminate();  
        return;
    }

    glfwMakeContextCurrent(_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        initSuccess = false;
        std::cout << "Failed to load GLAD" << "\n";
        return;
    }

    glViewport(0, 0, width, height);
}

Window::~Window() {
    glfwTerminate();
}

bool Window::shouldClose() {
    return glfwWindowShouldClose(_window);
}

void Window::swapBuffers() {
    glfwSwapBuffers(_window);
}

void Window::setFrameBufferCallback(void (*callback)(GLFWwindow*, int, int)) {
    glfwSetFramebufferSizeCallback(_window, callback);
}