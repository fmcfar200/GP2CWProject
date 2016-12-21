#ifndef SCREEN_QUAD_H
#define SCREEN_QUAD_H

#include "Common.h"

/// JACK CODE
class ScreenQuad
{
public:
	ScreenQuad();
	~ScreenQuad();

	void create();
	void render();
	void destroy();
private:
	GLuint m_VBO;
	GLuint m_VAO;
};
#endif