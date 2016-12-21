#pragma once

#include"Common.h"

//Stevens Shadow map Code

class ShadowMapFBO
{
	public:
		ShadowMapFBO();
		
		~ShadowMapFBO();

		bool Init(unsigned int WindowWidth, unsigned int WindowHeight);

		void MeshMultiplication();

		void Render();

	private:
		GLuint m_fbo;
		GLuint m_shadowMap;
};