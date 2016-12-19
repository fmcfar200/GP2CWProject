#version 410

in vec2 texCoords;
out vec4 color;

uniform sampler2D screenTexture;

void main()
{ 
    color = vec4(vec3(1.0 - texture(screenTexture, texCoords)), 1.0);
}
