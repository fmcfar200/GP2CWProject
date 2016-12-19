#include "PostProcessBuffer.h"

PostProcessBuffer::PostProcessBuffer()
{
	m_Texture = 0;
	texColourBuffer = 0;
	m_FBO = 0;
	m_RBO = 0;
}

PostProcessBuffer::~PostProcessBuffer()
{

}

bool PostProcessBuffer::create(unsigned int width, unsigned int height)
{
	
	glGenFramebuffers(1, &m_FBO);
	//glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);

	glGenTextures(1, &texColourBuffer);
	glBindTexture(GL_TEXTURE_2D, texColourBuffer);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texColourBuffer, 0);

	glGenRenderbuffers(1, &m_RBO);
	glBindRenderbuffer(GL_RENDERBUFFER, m_RBO);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_RBO);

	GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	if (status != GL_FRAMEBUFFER_COMPLETE)
	{
		LOG(ERROR, "%s", "Framebuffer incomplete");
		return false;
	}
	//glBindFramebuffer(GL_FRAMEBUFFER, 0);

	return true;
}

void PostProcessBuffer::destroy()
{
	glDeleteFramebuffers(1, &m_FBO);
	glDeleteRenderbuffers(1, &m_RBO);
	glDeleteTextures(1, &texColourBuffer);
}

void PostProcessBuffer::bind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

}

void PostProcessBuffer::unbind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}