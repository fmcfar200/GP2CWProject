#version 410

in vec2 texCoords;
out vec4 color;

uniform sampler2D screenTexture;

void main()
{ 
    color = texture(screenTexture, texCoords);
}