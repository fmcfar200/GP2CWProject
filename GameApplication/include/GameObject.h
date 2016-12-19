#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Common.h"
#include "Vertex.h"
#include "Texture.h"
#include "Shader.h"
#include "Transform.h"
#include "Component.h"
#include "Material.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	void onBeginRender();

	void onUpdate();
	void onRender(mat4& view, mat4& projection);
	void onInit();
	void onDestroy();

	void addComponent(shared_ptr<Component> component);
	void addChild(shared_ptr<GameObject> gameobject);

	template<class type>
	type * getComponent()
	{
		type * c = nullptr;
		for (auto component : m_Components)
		{
			c = dynamic_cast<type*>(component.get());
			if (c != nullptr)
				return c;
		}
		return c;
	};
	

	
	void copyVertexData(Vertex *pVertex, int numberOfVertices, int *pIndices, int numberOfIndices);

	



	Transform * getTransform() { return m_Transform; };
	Material * getMaterial() { return m_Material; };

private:
	GameObject * m_pParent;
	vector<shared_ptr<GameObject> > m_ChildrenGameObjects;
	vector<shared_ptr<Component> > m_Components;
	Transform * m_Transform;
	Material * m_Material;

	//attribs
	vec3 m_Tangents;
	vec3 m_Binormals;

	mat4 m_TranslationMatrix;
	mat4 m_ScaleMatrix;
	mat4 m_RotationMatrix;
	mat4 m_ModelMatrix;

	GLuint m_VBO;
	GLuint m_EBO;
	GLuint m_VAO;
	int m_NumberOfVerts;
	int m_NumberOfIndices;

	//Shader Program
	

	
};

#endif
