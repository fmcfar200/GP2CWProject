
#ifndef _CAMERA_H
#define _CAMERA_H


#include "Common.h"
#include "GameApplication.h"
class Camera
{
public:
	Camera();
	~Camera();
	void onKeyDown(SDL_Keycode keyCode);

	void OnUpdate();

	vec3& getCameraPos()
	{
		return m_CameraPosition;
	};
	vec3& getCameraViewDirection()
	{
		return m_ViewDirection;
	};
	vec3& getUP()
	{
		return m_UP;
	};


	void setCameraPosition(const vec3& pos)
	{
		m_CameraPosition = pos;
	};

	void setViewDirection(const vec3& viewDir)
	{
		m_ViewDirection = viewDir;
	};

private:
	//Camera
	vec3 m_CameraPosition;
	vec3 m_ViewDirection;
	vec3 m_UP = vec3(0.0, 1.0, 0.0);
	vec3 m_Direction;
	int m_MouseXPos;
	int m_MouseYPos;

	

	float movementSpeed = 0.25f;

};

#endif 
