#ifndef POSTPROCESSBUFFER_H
#define POSTPROCESSBUFFER_H

#include "Common.h"

class PostProcessBuffer
{
public:
	PostProcessBuffer();
	~PostProcessBuffer();

	bool create(unsigned int width, unsigned int height);
	void destroy();

	void bind();
	void unbind();

	GLuint GetTexture()
	{
		return texColourBuffer;
	}

private:
	GLuint m_Texture;
	GLuint texColourBuffer;
	GLuint m_RBO;
	GLuint m_FBO;
};

#endif
