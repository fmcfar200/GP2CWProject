#ifndef _MYGAME_H
#define _MYGAME_H

#include "GameApplication.h"
#include "GameObject.h"
#include "Vertex.h"

class MyGame:public GameApplication
{
public:

	MyGame();
	~MyGame();

	void render();
	void update();
	void initScene();
	void destroyScene();
private:
	GLuint m_VBO;
	GLuint m_VAO;

	//Shader Program
	GLuint m_ShaderProgram;

	//matrices
	mat4 m_ViewMatrix;
	mat4 m_ProjMatrix;
	mat4 m_ModelMatrix;

	vec3 m_CameraPosition;

	GLuint m_Texture;
	GLuint m_ClampSampler;

	GameObject * m_TestObject;
	//GameObject * m_NewObject;
};
#endif

