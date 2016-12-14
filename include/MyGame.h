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
	void SDL_GetMouseState(int, int);
	
private:
	//matrices
	mat4 m_ViewMatrix;
	mat4 m_ProjMatrix;

	vector<shared_ptr<GameObject>> m_GameObjects;
	shared_ptr<Light> m_Light;
	vec4 m_AmbientLightColour;

	float movementSpeed = 0.25f;
	vec3 m_CameraPosition;
	vec3 m_ViewDirection;
	vec3 m_Direction;
	int m_MouseXPos ;
	int m_MouseYPos ;

	int lastMouseXPos;
	int lastMouseYPos;
	
	

	float yaw;
	float pitch;
	bool FirstMouse;
	

};
#endif
