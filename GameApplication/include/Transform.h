#ifndef _TRANSFORM_H
#define _TRANSFORM_H

#include "Common.h"


class Transform
{
public:
	Transform();
	~Transform();
	void onUpdate();


	mat4& getModelMatrix()
	{
		return m_ModelMatrix;
	}

	void setPosition(const vec3& pos)
	{
		m_Position = pos;
	};

	void setRotation(const vec3& rot)
	{
		m_Rotation = rot;
	};

	void setScale(const vec3& scale)
	{
		m_Scale = scale;
	};

	vec3& getPosition()
	{
		return m_Position;
	};

	vec3& getRotation()
	{
		return m_Rotation;
	};

	vec3& getScale()
	{
		return m_Scale;
	};

	//void rotate(const vec3& delta);

private:

	vec3 m_Position;
	vec3 m_Rotation;
	vec3 m_Scale;

	mat4 m_ModelMatrix;
	mat4 m_TranslationMatrix;
	mat4 m_ScaleMatrix;
	mat4 m_RotationMatrix;

	string m_Name;
};

#endif