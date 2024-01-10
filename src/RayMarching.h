#ifndef RAYMARCHING_H
#define RAYMARCHING_H

#include "Shader.h"
#include <string>

class RayMarchingFrame {
    public:
        RayMarchingFrame(const char* vertexPath, const char* fragmentPath);
        ~RayMarchingFrame();

        void Draw();
        void setFloat(const std::string &name, float value);

    private:
        Shader shader;

        unsigned int VBO, VAO, EBO;

        float vertices[12] = {
            1.0f,  1.0f, 0.0f,  // top right
            1.0f, -1.0f, 0.0f,  // bottom right
            -1.0f, -1.0f, 0.0f,  // bottom left
            -1.0f,  1.0f, 0.0f   // top left 
        };

        unsigned int indices[6] = {
        0,1,3,
        1,2,3,
        };

};

#endif