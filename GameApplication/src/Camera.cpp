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

void Camera::setCameraPosition(const vec3 & pos)
{
	m_CameraPosition = pos;

}
void Camera::setViewDirection(const vec3& viewDir)
{
	m_ViewDirection = viewDir;
}

vec3& Camera::getCameraPos()
{
	return m_CameraPosition;
}
vec3& Camera::getCameraViewDirection()
{
	return m_ViewDirection;
}
vec3& Camera::getUP()
{
	return m_UP;
}








void Camera::MoveForward()
{
	m_CameraPosition += movementSpeed * m_ViewDirection;
}

void Camera::MoveBackwards()
{
	m_CameraPosition += -movementSpeed * m_ViewDirection;
}

void Camera::MoveLeft()
{
	vec3 m_StrafeDirection = cross(m_ViewDirection, m_UP);
	m_CameraPosition += -movementSpeed*m_StrafeDirection;
}

void Camera::MoveRight()
{
	vec3 m_StrafeDirection = cross(m_ViewDirection, m_UP);
	m_CameraPosition += movementSpeed*m_StrafeDirection;
}

void Camera::LookUp()
{
	m_ViewDirection.y += movementSpeed * 2;
}

void Camera::LookDown()
{
	m_ViewDirection.y += -movementSpeed * 2;
}

void Camera::LookLeft()
{
	vec3 vVector = m_ViewDirection - m_CameraPosition;
	m_ViewDirection.z = (float)(m_CameraPosition.z + sin(-0.1f)*vVector.x + cos(-0.1f)*vVector.z);
	m_ViewDirection.x = (float)(m_CameraPosition.x + cos(-0.1f)*vVector.x - sin(-0.1f)*vVector.z);
}

void Camera::LookRight()
{
	vec3 vVector = m_ViewDirection - m_CameraPosition;
	m_ViewDirection.z = (float)(m_CameraPosition.z + sin(0.1f)*vVector.x + cos(0.1f)*vVector.z);
	m_ViewDirection.x = (float)(m_CameraPosition.x + cos(0.1f)*vVector.x - sin(0.1f)*vVector.z);

}

void Camera::OnUpdate()
{
}


