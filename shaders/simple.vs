#version 330 core
layout (location = 0) in vec3 aPos;
uniform float aTime;
out float time;
out vec2 fragCoord;

void main() {
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    time = aTime;
    fragCoord = aPos.xy;
}