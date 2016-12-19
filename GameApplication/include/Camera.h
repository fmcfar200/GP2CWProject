
#ifndef _CAMERA_H
#define _CAMERA_H


#include "Common.h"
#include "GameApplication.h"
class Camera
{
public:
	Camera();
	~Camera();
	void MoveForward();
	void MoveBackwards();
	void MoveLeft();
	void MoveRight();
	void LookUp();
	void LookDown();
	void LookLeft();
	void LookRight();

	void OnUpdate();

	void setCameraPosition(const vec3& pos);

	void setViewDirection(const vec3 & viewDir);

	vec3 & getCameraPos();

	vec3 & getCameraViewDirection();

	vec3 & getUP();

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
