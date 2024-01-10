#include "RayMarching.h"
#include "Shader.h"

RayMarchingFrame::RayMarchingFrame(const char* vertexPath, const char* fragmentPath) : shader(vertexPath, fragmentPath) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, false, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

RayMarchingFrame::~RayMarchingFrame() {
    // glDeleteVertexArrays(1, &VAO);
    // glDeleteBuffers(1, &VBO);
    // glDeleteBuffers(1, &EBO);
}

/*
Setting uniforms is done before calling Draw()
*/
void RayMarchingFrame::Draw() {
    shader.use();
    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void RayMarchingFrame::setFloat(const std::string &name, float value) {
    shader.use();
    shader.setFloat(name, value);
}