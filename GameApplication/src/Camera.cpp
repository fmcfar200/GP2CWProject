#include "Camera.h"



Camera::Camera()
{
	 m_CameraPosition = vec3(0.0f, 0, 0);
	 m_CameraFront = vec3(0.0f, 0.0f, 0);
	 m_CameraUp = vec3(0.0, 1.0, 0.0);
	 m_Direction = vec3(0,0,0);

	 cameraSpeed = 5.0f;

	 lastX = 512;
	 lastY = 384;

	 yaw = -90.0f;
	 pitch = 0.0f;
	 fov = radians(45.0f);
	 deltaTime = 0.0f;
	 lastFrame = 0.0f;
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
	m_CameraFront = viewDir;
}

vec3& Camera::getCameraPos()
{
	return m_CameraPosition;
}
vec3& Camera::getCameraViewDirection()
{
	return m_CameraFront;
}
vec3& Camera::getUP()
{
	return m_CameraUp;
}

/// JACK CODE
// Handles the mouse movement 
void Camera::MoveMouse()
{
	//SDL_SetRelativeMouseMode(SDL_TRUE);
	GLfloat currentFrame = SDL_GetTicks();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

	cameraSpeed = 5.0f * deltaTime;

	//gets current mouse position on screen
	int xpos, ypos;
	SDL_GetGlobalMouseState(&xpos, &ypos);
	 
	GLfloat xOffset = xpos - lastX;
	GLfloat yOffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	GLfloat sens = 0.20f;
	xOffset *= sens;
	yOffset *= sens;

	yaw += xOffset;
	pitch += yOffset;

	if (pitch > 89.0f)
	{
		pitch = 89.0f;
	}
	if (pitch < -89.0f)
	{
		pitch = -89.0f;
	}

	vec3 front;
	front.x = cos(radians(yaw)) * cos(radians(pitch));
	front.y = sin(radians(pitch));
	front.z = sin(radians(yaw)) * cos(radians(pitch));
	m_CameraFront = normalize(front);
}

/// JACK CODE
void Camera::MoveForward()
{
	m_CameraPosition += normalize(m_CameraFront * cameraSpeed);
}

/// JACK CODE
void Camera::MoveBackwards()
{
	m_CameraPosition -= normalize(m_CameraFront * cameraSpeed);
}

/// JACK CODE
void Camera::MoveLeft()
{
	m_CameraPosition -= normalize(cross(m_CameraFront, m_CameraUp) * cameraSpeed);
}

/// JACK CODE
void Camera::MoveRight()
{
	m_CameraPosition += normalize(cross(m_CameraFront, m_CameraUp) * cameraSpeed);
}

void Camera::LookUp()
{
	m_CameraFront.y += movementSpeed * 2;
}

void Camera::LookDown()
{
	m_CameraFront.y += -movementSpeed * 2;
}

void Camera::LookLeft()
{
	vec3 vVector = m_CameraFront - m_CameraPosition;
	m_CameraFront.z = (float)(m_CameraPosition.z + sin(-0.1f)*vVector.x + cos(-0.1f)*vVector.z);
	m_CameraFront.x = (float)(m_CameraPosition.x + cos(-0.1f)*vVector.x - sin(-0.1f)*vVector.z);
}

void Camera::LookRight()
{
	vec3 vVector = m_CameraFront - m_CameraPosition;
	m_CameraFront.z = (float)(m_CameraPosition.z + sin(0.1f)*vVector.x + cos(0.1f)*vVector.z);
	m_CameraFront.x = (float)(m_CameraPosition.x + cos(0.1f)*vVector.x - sin(0.1f)*vVector.z);

}

void Camera::update()
{

}


