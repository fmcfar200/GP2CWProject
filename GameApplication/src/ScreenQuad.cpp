#include "ScreenQuad.h"

/// JACK CODE (ALL)
ScreenQuad::ScreenQuad()
{
	m_VBO = 0;
	m_VAO = 0;
}

ScreenQuad::~ScreenQuad()
{
}

void ScreenQuad::create()
{
	float vertices[] =
	{
		-1, -1,
		1, -1,
		-1, 1,
		1, 1,
	};

	glGenBuffers(1, &m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float), vertices, GL_STATIC_DRAW);  //8 * sizeof(float)

	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
}

void ScreenQuad::render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBindVertexArray(m_VAO);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	//glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

void ScreenQuad::destroy()
{
	glDeleteVertexArrays(1, &m_VAO);
	glDeleteBuffers(1, &m_VBO);
}