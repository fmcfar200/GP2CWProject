#include "Transform.h"



Transform::Transform()
{
	m_Position = vec3(0.0f, 0.0f, 0.0f);
	m_Rotation = vec3(0.0f, 0.0f, 0.0f);
	m_Scale = vec3(1.0f, 1.0f, 1.0f);

	m_ModelMatrix = mat4(1.0f);
	m_TranslationMatrix = mat4(1.0f);
	m_ScaleMatrix = mat4(1.0f);

	m_RotationMatrix = mat4(1.0f);
	m_Name = "Transform";
}


Transform::~Transform()
{

}
void Transform::onUpdate()
{
	m_ScaleMatrix = scale(m_Scale);
	m_TranslationMatrix = translate(m_Position);

	m_RotationMatrix = eulerAngleYXZ(m_Rotation.y, m_Rotation.x, m_Rotation.z);

	m_ScaleMatrix = scale(m_Scale);

	m_TranslationMatrix = translate(m_Position);

	m_ModelMatrix = m_TranslationMatrix*m_RotationMatrix*m_ScaleMatrix;
	
	
}

mat4 & Transform::getModelMatrix()
{
	return m_ModelMatrix;
}

