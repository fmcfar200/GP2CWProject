#include "MyGame.h"
#include "Common.h"
#include "..\include\MyGame.h"

const std::string ASSET_PATH = "assets";
const std::string SHADER_PATH = "/shaders";
const std::string TEXTURE_PATH = "/textures";
const std::string MODEL_PATH = "/models";

MyGame::MyGame()
{
}

MyGame::~MyGame()
{
}

void MyGame::render()
{
	GameApplication::render();
	m_TestObject->onRender(m_ViewMatrix, m_ProjMatrix);
}

void MyGame::update()
{
	GameApplication::update();

	m_ProjMatrix = perspective(radians(45.0f), (float)m_WindowWidth / (float)m_WindowHeight, 0.1f, 100.0f);
	m_ViewMatrix = lookAt(m_CameraPosition, vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));

	m_TestObject->onUpdate();
}

void MyGame::initScene()
{
	
	Vertex verts[] = {
	{vec3(-0.5f, -0.5f, 0.0f),vec4(1.0f,1.0f,1.0f,1.0f),vec2(0.0f,3.0f)},
	{vec3(0.5f, -0.5f, 0.0f),vec4(1.0f,1.0f,1.0f,1.0f),vec2(3.0f,3.0f)},
	{vec3(-0.5f,  0.5f, 0.0f),vec4(1.0f,1.0f,1.0f,1.0f),vec2(0.0f,0.0f)},
	{vec3(0.5f, 0.5f, 0.0f),vec4(1.0f,1.0f,1.0f,1.0f),vec2(3.0f,0.0f)},
	};

	int indices[] =
	{
	0,2,1,
	2,3,1
	};

	m_TestObject = new GameObject();
	
	string vsPath = ASSET_PATH + SHADER_PATH + "/simpleVS.glsl";
	string fsPath = ASSET_PATH + SHADER_PATH + "/textureFS.glsl";
	string texturePath = ASSET_PATH + TEXTURE_PATH + "/texture.png";
	m_TestObject->loadShaders(vsPath, fsPath);

	//lets load texture
	m_TestObject->loadTexture(texturePath);

	m_TestObject->copyVertexData(verts, 4, indices ,6 );

	m_CameraPosition = vec3(0.0f, 0.0f, 100.0f);


}

void MyGame::destroyScene()
{
	m_TestObject->onDestroy();
}
