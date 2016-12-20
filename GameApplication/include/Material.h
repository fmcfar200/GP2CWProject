#pragma once

#include "Common.h"
#include "Component.h"
#include "Shader.h"
#include "Texture.h"

class Material: public BaseComponent
{
public:
	Material();
	~Material();

	void loadDiffuseTexture(const string& filename);
	void loadSpecularTexture(const string& filename);
	void loadNormalTexture(const string& filename);
	void loadHeightMapTexture(const string& filename);
	void loadShaders(const string& vsFilename, const string& fsFilename);

	void onBeginRender();

	void onUpdate();
	void onRender(mat4& view, mat4& projection);
	void onInit();
	void onDestroy();

	GLuint& getShaderProgram()
	{
		return m_ShaderProgram;
	};

	GLuint& getSampler()
	{
		return m_Sampler;
	};
	GLuint& getDiffuseTexture()
	{
		return m_DiffuseTexture;
	};
	GLuint& getSpecularTexture()
	{
		return m_SpecularTexture;
	};
	GLuint& getNormalTexture()
	{
		return m_NormalTexture;
	};
	GLuint& getHeightTexture()
	{
		return m_HeightMapTexture;
	};
	vec4 getAmbientMaterialColour()
	{
		return m_AmbientMaterialColour;
	};
	vec4 getDiffuseMaterialColour()
	{
		return m_DiffuseMaterialColour;
	};
	vec4 getSpecularMaterialColour()
	{
		return m_SpecularMaterialColour;
	};
	float getSpecularMaterialPower()
	{
		return m_SpecularMaterialPower;
	};

	void setAmbientMaterialColour(const vec4& colour)
	{
		m_AmbientMaterialColour = colour;
	};

	void setDiffuseMaterialColour(const vec4& colour)
	{
		m_DiffuseMaterialColour = colour;
	};

	void setSpecularMaterialColour(const vec4& colour)
	{
		m_SpecularMaterialColour = colour;
	};

	void setSpecularPower(float power)
	{
		m_SpecularMaterialPower = power;
	};

private:
	GLuint m_ShaderProgram;
	GLuint m_DiffuseTexture;
	GLuint m_NormalTexture;
	GLuint m_SpecularTexture;
	GLuint m_HeightMapTexture;
	GLuint m_Sampler;

	//Materials
	vec4 m_AmbientMaterialColour;
	vec4 m_DiffuseMaterialColour;
	vec4 m_SpecularMaterialColour;
	float m_SpecularMaterialPower;
};

