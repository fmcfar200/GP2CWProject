#version 410

layout(location=0) in vec3 vertexPosition;
layout(location=1) in vec4 vertexColours;
layout(location=2) in vec2 vertexTextureCoords;

out vec4 vertexColoursOut;
out vec2 vertexTextureCoordsOut;

uniform mat4 MVP;

void main()
{
	gl_Position = MVP * vec4(vertexPosition, 1.0);
	vertexColoursOut=vertexColours;
	vertexTextureCoordsOut=vertexTextureCoords;
}
