#include "PostProcessEffect.h"
#include "Shader.h"

/*const string postProcessVSShaderCode =
"#version 410\n"
"\n"
"layout(location=0) in vec2 vertexPosition;\n"
"\n"
"out vec2 textureCoords;\n"
"\n"
"void main()\n"
"{\n"
"	textureCoords = (vertexPosition + 1.0) / 2.0;\n"
"	gl_Position = vec4(vertexPosition, 0.0, 1.0);\n"
"}\n";*/

PostProcessEffect::PostProcessEffect()
{
	m_ShaderProgram = 0;
}

PostProcessEffect::~PostProcessEffect()
{
}

bool PostProcessEffect::loadShader(const string & FSFilename, const string & VSFilename)
{
	GLuint vertexShaderProgram = loadShaderFromFile(VSFilename, VERTEX_SHADER);
	GLuint fragmentShaderProgram = loadShaderFromFile(FSFilename, FRAGMENT_SHADER);

	m_ShaderProgram = glCreateProgram();
	glAttachShader(m_ShaderProgram, vertexShaderProgram);
	glAttachShader(m_ShaderProgram, fragmentShaderProgram);
	glLinkProgram(m_ShaderProgram);
	checkForLinkErrors(m_ShaderProgram);

	glDeleteShader(vertexShaderProgram);
	glDeleteShader(fragmentShaderProgram);

	logShaderInfo(m_ShaderProgram);

	return false;
}