#ifndef _MyGame_H
#define _MyGame_H

#include "GameApplication.h"
#include "PostProcessBuffer.h"
#include "PostProcessEffect.h"
#include "ScreenQuad.h"

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
	void MoveMouse();
	
private:
	//matrices
	mat4 m_ViewMatrix;
	mat4 m_ProjMatrix;

	vector<shared_ptr<GameObject>> m_GameObjects;
	vector<shared_ptr<Light>> m_Lights;
	vec4 m_AmbientLightColour;

	//Camera control and mouse movement (Jack's code)
	vec3 m_CameraPosition;
	vec3 m_CameraTarget;
	vec3 m_CameraDirection;
	vec3 m_CameraFront;
	vec3 m_CameraUp;
	GLfloat cameraSpeed;

	GLfloat yaw;
	GLfloat pitch;
	GLfloat lastX;
	GLfloat lastY;
	GLfloat fov;
	GLfloat deltaTime;
	GLfloat lastFrame;

	//Post Processing
	shared_ptr<PostProcessBuffer> m_PostBuffer;
	shared_ptr<PostProcessEffect> m_PostEffect;
	shared_ptr<ScreenQuad> m_ScreenQuad;

};
#endif
