#include "MyGame.h"

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

void MyGame::initScene()
{
	//asset paths
	string earthPath = ASSET_PATH + MODEL_PATH + "/Earth.fbx";
	string houseModel = ASSET_PATH + MODEL_PATH + "/fachwerkhaus1.fbx";

	//light texture vs and fs path
	string lightTextureVSPath = ASSET_PATH + SHADER_PATH + "/lightTextureVS.glsl";
	string lightTextureFSPath = ASSET_PATH + SHADER_PATH + "/lightTextureFS.glsl";

	//normal mapping paths
	string normalMappingVSPath = ASSET_PATH + SHADER_PATH + "/normalMappingVS.glsl";
	string normalMappingFSPath = ASSET_PATH + SHADER_PATH + "/normalMappingFS.glsl";

	//parallax paths
	string parallaxMappingVSPath = ASSET_PATH + SHADER_PATH + "/parallaxMappingVS.glsl";
	string parallaxMappingFSPath = ASSET_PATH + SHADER_PATH + "/parallaxMappingFS.glsl";
	
	//earth textures
	string earthDiffTexPath = ASSET_PATH + TEXTURE_PATH + "/earth_diff.png";
	string earthSpecTexPath = ASSET_PATH + TEXTURE_PATH + "/earth_spec.png";
	string earthBumpTexPath = ASSET_PATH + TEXTURE_PATH + "/earth_norm.png";
	string earthHeightTexPath = ASSET_PATH + TEXTURE_PATH + "/earth_height.png";

	//brick textures
	string brickDiffTexPath = ASSET_PATH + TEXTURE_PATH + "/bricks_diff.jpg";
	string brickSpecTexPath = ASSET_PATH + TEXTURE_PATH + "/bricks_spec.png";
	string brickBumpTexPath = ASSET_PATH + TEXTURE_PATH + "/bricks_norm.png";
	string brickHeightTexPath = ASSET_PATH + TEXTURE_PATH + "/bricks_height.png";


	
	//creates new game object and loads a model
	shared_ptr<GameObject> m_TestGO = shared_ptr<GameObject>(loadModelFromFile(earthPath));
	//loads shaders
	m_TestGO->loadShaders(parallaxMappingVSPath, parallaxMappingFSPath);
	m_TestGO->loadDiffuseTexture(brickDiffTexPath);
	m_TestGO->loadSpecularTexture(brickSpecTexPath);
	m_TestGO->loadNormalTexture(brickBumpTexPath);
	m_TestGO->loadHeightMapTexture(brickHeightTexPath);
	//set scale and positions
	m_TestGO->setPosition(vec3(-5.0f, 0.0f, 0.0f));
	m_TestGO->setScale(vec3(1.0f, 1.0f, 1.0f));
	m_GameObjects.push_back(m_TestGO);

	shared_ptr<GameObject> m_TestGO2 = shared_ptr<GameObject>(loadModelFromFile(earthPath));
	m_TestGO2->loadShaders(parallaxMappingVSPath, parallaxMappingFSPath);
	m_TestGO2->loadDiffuseTexture(brickDiffTexPath);
	m_TestGO2->loadSpecularTexture(brickSpecTexPath);
	m_TestGO2->loadNormalTexture(brickBumpTexPath);
	m_TestGO2->loadHeightMapTexture(brickHeightTexPath);
	m_TestGO2->setPosition(vec3(5.0f, 0.0f, 0.0f));
	m_TestGO2->setScale(vec3(1.0f, 1.0f, 1.0f));
	m_GameObjects.push_back(m_TestGO2);


	
	m_CameraPosition = vec3(0.0f, 0.0f, 20.0f);

	//lighting
	m_Light = shared_ptr<Light>(new Light());
	m_Light->DiffuseColour = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SpecularColour = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->Direction = vec3(0.0f, 0.0f, -1.0f);
	m_AmbientLightColour = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	
}

void MyGame::onKeyDown(SDL_Keycode keyCode)
{
	/*
	//input for rotation
	if (keyCode == SDLK_a)
	{
		m_TestGO->rotate(vec3(0.0f, -0.1f, 0.0f));
	}else if (keyCode == SDLK_d)
	{
		m_TestGO->rotate(vec3(0.0f, 0.1f, 0.0f));
	}
	if (keyCode==SDLK_w)
	{
		m_TestGO->rotate(vec3(-0.1f,0.0f,0.0f));
	}
	else if (keyCode==SDLK_s)
	{
		m_TestGO->rotate(vec3(0.1f,0.0f,0.0f));
	}

	*/
	//input for zooming
	if (keyCode == SDLK_DOWN)
	{
		m_CameraPosition = vec3(m_CameraPosition.x, m_CameraPosition.y, m_CameraPosition.z + 0.25f);
	}
	else if (keyCode == SDLK_UP)
	{
		m_CameraPosition = vec3(m_CameraPosition.x, m_CameraPosition.y, m_CameraPosition.z - 0.25f);

	}
}

void MyGame::destroyScene()
{
	//cycles through all game objects and destroys
	for (auto& object : m_GameObjects)
	{
		object->onDestroy();

	}

	//clears the list
	m_GameObjects.clear();
}

void MyGame::update()
{
	GameApplication::update();

	m_ProjMatrix = perspective(radians(45.0f), (float)m_WindowWidth / (float)m_WindowHeight, 0.1f, 1000.0f);
	m_ViewMatrix = lookAt(m_CameraPosition, vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
	//cycles through all game objects and updates
	for (auto& object : m_GameObjects)
	{
		object->onUpdate();

	}
}

void MyGame::render()
{
	GameApplication::render();
	for (auto& object : m_GameObjects)
	{
		GLuint currentShader = object->getShaderProgram();

		GLint ambientLightColourLocation = glGetUniformLocation(currentShader, "directionLight.ambientColour");
		glUniform4fv(ambientLightColourLocation, 1, value_ptr(m_AmbientLightColour));

		GLint diffuseLightColourLocation = glGetUniformLocation(currentShader, "directionLight.diffuseColour");
		glUniform4fv(diffuseLightColourLocation, 1, value_ptr(m_Light->DiffuseColour));

		GLint specularLightColourLocation = glGetUniformLocation(currentShader, "directionLight.specularColour");
		glUniform4fv(specularLightColourLocation, 1, value_ptr(m_Light->SpecularColour));

		GLint lightDirectionLocation = glGetUniformLocation(currentShader, "directionLight.direction");
		glUniform3fv(lightDirectionLocation, 1, value_ptr(m_Light->Direction));

		GLint cameraPositionLocation = glGetUniformLocation(currentShader, "cameraPos");
		glUniform3fv(cameraPositionLocation, 1, value_ptr(m_CameraPosition));

		object->onRender(m_ViewMatrix, m_ProjMatrix);
	}


	
}
