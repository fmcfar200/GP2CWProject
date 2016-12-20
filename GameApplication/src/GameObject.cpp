#include "GameObject.h"

GameObject::GameObject()
{
	shared_ptr<Transform> transformComponent = shared_ptr<Transform>(new Transform());
	addComponent(transformComponent);
	m_Transform = transformComponent.get();

	shared_ptr<Material> materialComponent = shared_ptr<Material>(new Material());
	addComponent(materialComponent);
	m_Material = materialComponent.get();

	m_VBO=0;
	m_EBO=0;
	m_VAO=0;
	m_NumberOfVerts=0;
	m_NumberOfIndices=0;

<<<<<<< HEAD
	//Shader Program
	m_ShaderProgram=0;
<<<<<<< HEAD
	m_Texture=0;
	m_Sampler=0;
	m_pParent = nullptr;

	m_AmbientMaterialColour=vec4(0.2f,0.2f,0.2f,1.0f);
=======
	m_DiffuseTexture=0;
	m_SpecularTexture = 0;
	m_NormalTexture = 0;
	m_Sampler=0;
	m_pParent = nullptr;

	m_AmbientMaterialColour=vec4(0.0f,0.0f,0.0f,1.0f);
>>>>>>> refs/remotes/origin/master
	m_DiffuseMaterialColour=vec4(0.5f,0.5f,0.5f,1.0f);
	m_SpecularMaterialColour=vec4(1.0f,1.0f,1.0f,1.0f);
	m_SpecularMaterialPower=25.0f;
=======
	
	m_pParent = nullptr;

	
>>>>>>> refs/remotes/origin/master
}

GameObject::~GameObject()
{

}

void GameObject::onBeginRender()
{
	glUseProgram(getMaterial()->getShaderProgram());
	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
}

void GameObject::onUpdate()
{
	for (auto &gameObject : m_ChildrenGameObjects)
	{
		gameObject->onUpdate();
	}

	for (auto &component : m_Components)
	{
		component->onUpdate();
	}

	
}

void GameObject::onRender(mat4& view, mat4& projection)
{
	
	

	GLint MVPLocation = glGetUniformLocation(getMaterial()->getShaderProgram(), "MVP");
	mat4 MVP = projection*view*getTransform()->getModelMatrix();
	glUniformMatrix4fv(MVPLocation, 1, GL_FALSE, glm::value_ptr(MVP));

	GLint ModelLocation = glGetUniformLocation(getMaterial()->getShaderProgram(), "Model");
	glUniformMatrix4fv(ModelLocation, 1, GL_FALSE, glm::value_ptr(getTransform()->getModelMatrix()));

	glBindSampler(0, getMaterial()->getSampler());
	glActiveTexture(GL_TEXTURE0);
<<<<<<< HEAD
<<<<<<< HEAD
	glBindTexture(GL_TEXTURE_2D, m_Texture);
	GLint textureLocation = glGetUniformLocation(m_ShaderProgram, "diffuseSampler");
	glUniform1i(textureLocation, 0);
=======
	glBindTexture(GL_TEXTURE_2D, m_DiffuseTexture);
	GLint diffuseTextureLocation = glGetUniformLocation(m_ShaderProgram, "diffuseSampler");
=======
	glBindTexture(GL_TEXTURE_2D, getMaterial()->getDiffuseTexture());
	GLint diffuseTextureLocation = glGetUniformLocation(getMaterial()->getShaderProgram(), "diffuseSampler");
>>>>>>> refs/remotes/origin/master
	glUniform1i(diffuseTextureLocation, 0);

	glBindSampler(1, getMaterial()->getSampler());
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, getMaterial()->getSpecularTexture());
	GLint specTextureLocation = glGetUniformLocation(getMaterial()->getShaderProgram(), "specularSampler");
	glUniform1i(specTextureLocation, 1);

	glBindSampler(2, getMaterial()->getSampler());
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, getMaterial()->getNormalTexture());
	GLint normalTextureLocation = glGetUniformLocation(getMaterial()->getShaderProgram(), "normalSampler");
	glUniform1i(normalTextureLocation, 2);

	
	glBindSampler(3, getMaterial()->getSampler());
	glActiveTexture(GL_TEXTURE3);
	glBindTexture(GL_TEXTURE_2D, getMaterial()->getHeightTexture());
	GLint heightTextureLocation = glGetUniformLocation(getMaterial()->getShaderProgram(), "heightSampler");
	glUniform1i(heightTextureLocation, 3);
	


	

	


>>>>>>> refs/remotes/origin/master

	GLint ambientLocation = glGetUniformLocation(getMaterial()->getShaderProgram(), "ambientMaterialColour");
	glUniform4fv(ambientLocation, 1, value_ptr(getMaterial()->getAmbientMaterialColour()));

	GLint diffuseLocation = glGetUniformLocation(getMaterial()->getShaderProgram(), "diffuseMaterialColour");
	glUniform4fv(diffuseLocation, 1, value_ptr(getMaterial()->getDiffuseMaterialColour()));

	GLint specularLocation = glGetUniformLocation(getMaterial()->getShaderProgram(), "specularMaterialColour");
	glUniform4fv(specularLocation, 1, value_ptr(getMaterial()->getSpecularMaterialColour()));

	GLint specularPowerLocation = glGetUniformLocation(getMaterial()->getShaderProgram(), "specularPower");
	glUniform1f(specularPowerLocation, getMaterial()->getSpecularMaterialPower());

	glDrawElements(GL_TRIANGLES, m_NumberOfIndices, GL_UNSIGNED_INT, NULL);

}

void GameObject::onInit()
{
	for (auto &gameObject : m_ChildrenGameObjects)
	{
		gameObject->onInit();
	}

	for (auto &component : m_Components)
	{
		component->onInit();
	}
}

void GameObject::onDestroy()
{
<<<<<<< HEAD
	glDeleteVertexArrays(1, &m_VAO);
	glDeleteBuffers(1, &m_EBO);
	glDeleteBuffers(1, &m_VBO);
	glDeleteSamplers(1, &m_Sampler);
<<<<<<< HEAD
	glDeleteTextures(1, &m_Texture);
=======
	glDeleteTextures(1, &m_DiffuseTexture);
	glDeleteTextures(1, &m_SpecularTexture);
>>>>>>> refs/remotes/origin/master
	glDeleteProgram(m_ShaderProgram);
}

void GameObject::addChild(shared_ptr<GameObject> gameobject)
{
	gameobject->m_pParent = this;
	m_ChildrenGameObjects.push_back(gameobject);
}

void GameObject::rotate(const vec3 & delta)
{
	m_Rotation += delta;
}

<<<<<<< HEAD
void GameObject::loadTexture(const string & filename)
{
	m_Texture = loadTextureFromFile(filename);
	glBindTexture(GL_TEXTURE_2D, m_Texture);
=======
void GameObject::loadDiffuseTexture(const string & filename)
{
	m_DiffuseTexture = loadTextureFromFile(filename);
	glBindTexture(GL_TEXTURE_2D, m_DiffuseTexture);
>>>>>>> refs/remotes/origin/master
	glGenerateMipmap(GL_TEXTURE_2D);
=======
>>>>>>> refs/remotes/origin/master

	for (auto &gameObject : m_ChildrenGameObjects)
	{
		gameObject->onDestroy();
	}

	for (auto &component : m_Components)
	{
		component->onDestroy();
	}
	m_ChildrenGameObjects.clear();
	m_Components.clear();

<<<<<<< HEAD
<<<<<<< HEAD
=======
void GameObject::loadSpecularTexture(const string & filename)
{
	m_SpecularTexture = loadTextureFromFile(filename);
	glBindTexture(GL_TEXTURE_2D, m_SpecularTexture);
	glGenerateMipmap(GL_TEXTURE_2D);
=======
>>>>>>> refs/remotes/origin/master

	glDeleteVertexArrays(1, &m_VAO);
	glDeleteBuffers(1, &m_EBO);
	glDeleteBuffers(1, &m_VBO);
	
}

void GameObject::addComponent(shared_ptr<Component> component)
{
	component->setParent(this);
	m_Components.push_back(component);
}

void GameObject::addChild(shared_ptr<GameObject> gameobject)
{
	m_ChildrenGameObjects.push_back(gameobject);
}


<<<<<<< HEAD
>>>>>>> refs/remotes/origin/master
void GameObject::loadShaders(const string & vsFilename, const string & fsFilename)
{
	GLuint vertexShaderProgram = loadShaderFromFile(vsFilename, VERTEX_SHADER);

	GLuint fragmentShaderProgram = loadShaderFromFile(fsFilename, FRAGMENT_SHADER);
=======
>>>>>>> refs/remotes/origin/master



void GameObject::copyVertexData(Vertex * pVertex, int numberOfVertices, int * pIndices, int numberOfIndices)
{
	m_NumberOfVerts = numberOfVertices;
	m_NumberOfIndices = numberOfIndices;
	glGenBuffers(1, &m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, numberOfVertices * sizeof(Vertex), pVertex, GL_STATIC_DRAW);

	glGenBuffers(1, &m_EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, numberOfIndices * sizeof(int), pIndices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);


	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		NULL);
<<<<<<< HEAD
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(void**)(offsetof(Vertex, colours)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(void**)(offsetof(Vertex, texCoords0)));
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(void**)(offsetof(Vertex, normal)));
=======

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(void**)(offsetof(Vertex, colours)));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(void**)(offsetof(Vertex, texCoords0)));

	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(void**)(offsetof(Vertex, normal)));

	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(void**)(offsetof(Vertex, tangent)));

	glEnableVertexAttribArray(5);
	glVertexAttribPointer(5, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(void**)(offsetof(Vertex, binormal)));
>>>>>>> refs/remotes/origin/master
}
