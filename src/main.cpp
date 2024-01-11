#include <glad/glad.h>


// std includes
#include <iostream>

// our includes
#include "main.h"
#include "RayMarching.h"
#include "Window.h"

/* 
    notes from this attempt
    make sure indices is a unsigned int

    make sure the VAO is created with glGenVertexArray
    and to bind it with glBindVertexArray

    the order for offset and amount are flipped with glDrawArrays and glDrawElements EG:
        glDrawArrays(GL_TRIANGLES, offset, amount)
        glDrawElements(GL_TRIANGLES, amount, GL_UNSIGNED_INT, offset)

*/

int main() {

    Window window(800, 600, "Raymarching", 3, 3, GLFW_OPENGL_CORE_PROFILE);
    window.setFrameBufferCallback(framebuffer_size_callback);
    RayMarchingFrame simple("../shaders/simple.vs", "../shaders/simple.fs");

    while(!window.shouldClose()) {

        // processing

        // rendering
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        simple.setFloat("aTime", glfwGetTime());
        simple.Draw();

        // check events and swap buffers
        window.swapBuffers();
        glfwPollEvents();

    }

    glfwTerminate();

    std::cout << "hello world" << "\n";
    return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}