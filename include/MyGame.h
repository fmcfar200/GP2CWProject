#ifndef _MyGame_H
#define _MyGame_H

#include "GameApplication.h"

class MyGame:public GameApplication
{
public:
	MyGame();
	~MyGame();

	void render();
	void update();
	void initScene();
	void destroyScene();
	void onKeyDown(SDL_Keycode keyCode);
	
private:
	//matrices
	mat4 m_ViewMatrix;
	mat4 m_ProjMatrix;

	vector<shared_ptr<GameObject>> m_GameObjects;
	vector<shared_ptr<Light>> m_Lights;
	vec4 m_AmbientLightColour;

	float movementSpeed = 0.25f;

	//Camera
	vec3 m_CameraPosition;
	vec3 m_ViewDirection;
	vec3 m_UP = vec3(0.0,1.0,0.0);
<<<<<<< HEAD
	vec3 m_Direction;
	int m_MouseXPos ;
	int m_MouseYPos ;


=======
>>>>>>> refs/remotes/origin/Fraser-PointLight
};
#endif
