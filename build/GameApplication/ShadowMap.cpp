#include "ShadowMap.h"

//Stevens Shadow map Code

ShadowMapFBO::ShadowMapFBO()
{
}

ShadowMapFBO::~ShadowMapFBO()
{
}

bool ShadowMapFBO::Init(unsigned int WindowWidth, unsigned int WindowHeight)
{
	//Framebuffer that regroups textures and depth buffer
	GLuint FramebufferName = 0;
	glGenFramebuffers(1, &FramebufferName);
	glBindFramebuffer(GL_FRAMEBUFFER, FramebufferName);

	//Depth texture
	GLuint depthTexture;
	glGenTextures(1, &depthTexture);
	glBindTexture(GL_TEXTURE_2D, depthTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT16, 1024, 1024, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, depthTexture, 0);

	//No colour buffer is drawn to
	glDrawBuffer(GL_NONE);

	//Check the frame buffer is working
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	{
		return false;
	}
}

void ShadowMapFBO::MeshMultiplication()
{
	glm::vec3 lightDir = glm::vec3(0.5f, 2, 2);

	//Create matrix from the lights view
	glm::mat4 depthProjectionMatrix = glm::ortho<float>(-10, 10, -10, 10, -10, 20);
	glm::mat4 depthViewMatrix = glm::lookAt(lightDir, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	glm::mat4 depthModelMatrix = glm::mat4(1.0);
	glm::mat4 depthMVP = depthProjectionMatrix * depthViewMatrix * depthModelMatrix; //Multiply all matrices together

	//Send the transformation to the shader
}

void ShadowMapFBO::Render()
{
	

}