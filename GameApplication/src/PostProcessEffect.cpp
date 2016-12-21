#include "PostProcessEffect.h"
#include "Shader.h"


/// JACK CODE (ALL)
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