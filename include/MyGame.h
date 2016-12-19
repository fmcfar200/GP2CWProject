#ifndef _MyGame_H
#define _MyGame_H

#include "GameApplication.h"
#include "Camera.h"
 class MyGame :public GameApplication
{
public:
	MyGame();
	~MyGame();

	void render();
	void update();
	void initScene();
	void destroyScene();
	
private:
	
	shared_ptr<Camera> m_Camera;

	vector<shared_ptr<GameObject>> m_GameObjects;
	vector<shared_ptr<Light>> m_Lights;
	vec4 m_AmbientLightColour;

	//matrices
	mat4 m_ViewMatrix;
	mat4 m_ProjMatrix;
	
};
#endif
