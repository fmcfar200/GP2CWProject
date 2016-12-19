#include "Camera.h"



Camera::Camera()
{
	 m_CameraPosition = vec3(0.0f, 0, 0);
	 m_ViewDirection = vec3(0.0f, 0.0f, 0);
	 m_UP = vec3(0.0, 1.0, 0.0);
	 m_Direction = vec3(0,0,0);
}


Camera::~Camera()
{
}

void Camera::onKeyDown(SDL_Keycode keyCode)
{
	//controls rotation of camera

	if (keyCode == SDLK_w)
	{
		m_CameraPosition += movementSpeed * m_ViewDirection;

	}
	else if (keyCode == SDLK_s)
	{
		m_CameraPosition += -movementSpeed * m_ViewDirection;

	}
	else if (keyCode == SDLK_a)
	{
		vec3 m_StrafeDirection = cross(m_ViewDirection, m_UP);
		m_CameraPosition += -movementSpeed*m_StrafeDirection;
	}
	else if (keyCode == SDLK_d)
	{
		vec3 m_StrafeDirection = cross(m_ViewDirection, m_UP);
		m_CameraPosition += movementSpeed*m_StrafeDirection;

	}

	if (keyCode == SDLK_DOWN)
	{

		m_ViewDirection.y += -movementSpeed * 2;
		m_ViewDirection.y += -movementSpeed;
	}
	else if (keyCode == SDLK_UP)
	{
		m_ViewDirection.y += movementSpeed * 2;

	}
	else if (keyCode == SDLK_RIGHT)
	{
		vec3 vVector = m_ViewDirection - m_CameraPosition;
		m_ViewDirection.z = (float)(m_CameraPosition.z + sin(0.1f)*vVector.x + cos(0.1f)*vVector.z);
		m_ViewDirection.x = (float)(m_CameraPosition.x + cos(0.1f)*vVector.x - sin(0.1f)*vVector.z);

	}
	else if (keyCode == SDLK_LEFT)
	{
		vec3 vVector = m_ViewDirection - m_CameraPosition;
		m_ViewDirection.z = (float)(m_CameraPosition.z + sin(-0.1f)*vVector.x + cos(-0.1f)*vVector.z);
		m_ViewDirection.x = (float)(m_CameraPosition.x + cos(-0.1f)*vVector.x - sin(-0.1f)*vVector.z);
	}
}

void Camera::OnUpdate()
{
}
