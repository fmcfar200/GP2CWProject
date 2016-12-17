#ifndef POSTPROCESS_EFFECT_H
#define POSTPROCESS_EFFECT_H

#include "Common.h"

class PostProcessEffect
{
public:
	PostProcessEffect();
	virtual ~PostProcessEffect();

	bool loadShader(const string& FSFilename);

	GLuint getShaderProgram()
	{
		return m_ShaderProgram;
	}

	virtual void bind()
	{
		glUseProgram(m_ShaderProgram);
	};

	void destroy()
	{
		glDeleteProgram(m_ShaderProgram);
	};

private:
	GLuint m_ShaderProgram;
};
#endif