
#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
    public:
        Window(int width, int height, const char* title, int versionMajor, int versionMinor, int openGlProfile);
        ~Window();

        bool initSuccess;

        void setName(const char* name);
        void setFrameBufferCallback(void (*callback)(GLFWwindow*, int, int));

        bool shouldClose();

        void swapBuffers();
    private:
        GLFWwindow* _window;
};

#endif