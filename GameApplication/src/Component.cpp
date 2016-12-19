#include "Component.h"

BaseComponent::BaseComponent()
{
	m_ParentGameObject = nullptr;
	m_Name = "Component";
}

BaseComponent::~BaseComponent()
{
}

const string & BaseComponent::getName()
{
	return m_Name;
}

void BaseComponent::setName(const string & name)
{
	m_Name = name;
}

void BaseComponent::setParent(GameObject * gameObject)
{
	m_ParentGameObject = gameObject;
}

GameObject * BaseComponent::getParent()
{
	return m_ParentGameObject;
}

void BaseComponent::onUpdate()
{
}

void BaseComponent::onRender()
{
}

void BaseComponent::onInit()
{
}

void BaseComponent::onDestroy()
{
}
