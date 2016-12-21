#ifndef POSTPROCESS_EFFECT_H
#define POSTPROCESS_EFFECT_H

#include "Common.h"
/// JACK CODE
class PostProcessEffect
{
public:
	PostProcessEffect();
	virtual ~PostProcessEffect();

	bool loadShader(const string& FSFilename, const string& VSFilename);

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
