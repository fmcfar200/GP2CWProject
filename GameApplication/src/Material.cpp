#include "Material.h"



Material::Material()
{
	//Shader Program
	m_ShaderProgram = 0;
	m_DiffuseTexture = 0;
	m_SpecularTexture = 0;
	m_NormalTexture = 0;
	m_HeightMapTexture = 0;
	m_Sampler = 0;

	m_AmbientMaterialColour = vec4(0.2f, 0.2f, 0.2f, 1.0f);
	m_DiffuseMaterialColour = vec4(0.5f, 0.5f, 0.5f, 1.0f);
	m_SpecularMaterialColour = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_SpecularMaterialPower = 50.0f;
}


Material::~Material()
{
}

void Material::loadDiffuseTexture(const string & filename)
{
	m_DiffuseTexture = loadTextureFromFile(filename);
	glBindTexture(GL_TEXTURE_2D, m_DiffuseTexture);
	glGenerateMipmap(GL_TEXTURE_2D);

	glGenSamplers(1, &m_Sampler);
	glSamplerParameteri(m_Sampler, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glSamplerParameteri(m_Sampler, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glSamplerParameteri(m_Sampler, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glSamplerParameteri(m_Sampler, GL_TEXTURE_WRAP_T, GL_REPEAT);

}

void Material::loadSpecularTexture(const string & filename)
{
	m_SpecularTexture = loadTextureFromFile(filename);
	glBindTexture(GL_TEXTURE_2D, m_SpecularTexture);
	glGenerateMipmap(GL_TEXTURE_2D);

}

void Material::loadNormalTexture(const string & filename)
{
	m_NormalTexture = loadTextureFromFile(filename);
	glBindTexture(GL_TEXTURE_2D, m_NormalTexture);
	glGenerateMipmap(GL_TEXTURE_2D);
}


void Material::loadHeightMapTexture(const string & filename)
{
	m_HeightMapTexture = loadTextureFromFile(filename);
	glBindTexture(GL_TEXTURE_2D, m_HeightMapTexture);
	glGenerateMipmap(GL_TEXTURE_2D);
}


void Material::loadShaders(const string & vsFilename, const string & fsFilename)
{
	GLuint vertexShaderProgram = loadShaderFromFile(vsFilename, VERTEX_SHADER);

	GLuint fragmentShaderProgram = loadShaderFromFile(fsFilename, FRAGMENT_SHADER);

	m_ShaderProgram = glCreateProgram();
	glAttachShader(m_ShaderProgram, vertexShaderProgram);
	glAttachShader(m_ShaderProgram, fragmentShaderProgram);
	glLinkProgram(m_ShaderProgram);
	checkForLinkErrors(m_ShaderProgram);

	//now we can delete the VS & FS Programs
	glDeleteShader(vertexShaderProgram);
	glDeleteShader(fragmentShaderProgram);

	logShaderInfo(m_ShaderProgram);
}

void Material::onBeginRender()
{

}

void Material::onUpdate()
{
}

void Material::onRender(mat4 & view, mat4 & projection)
{

}

void Material::onInit()
{
}

void Material::onDestroy()
{
	glDeleteSamplers(1, &m_Sampler);
	glDeleteTextures(1, &m_DiffuseTexture);
	glDeleteTextures(1, &m_SpecularTexture);
	glDeleteTextures(1, &m_NormalTexture);
	glDeleteTextures(1, &m_HeightMapTexture);
	glDeleteProgram(m_ShaderProgram);
}
