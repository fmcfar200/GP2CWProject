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
	string anvilPath = ASSET_PATH + MODEL_PATH + "/anvil.fbx";
	string understandPath = ASSET_PATH + MODEL_PATH + "/constuct_understand_wood.fbx";

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

	//metal paths
	string metalDiffTexPath = ASSET_PATH + TEXTURE_PATH + "/m_3.png";
	string metalSpecTexPath = ASSET_PATH + TEXTURE_PATH + "/m_3S.png";
	string metalBumpTexPath = ASSET_PATH + TEXTURE_PATH + "/m_3N.png";
	string metalHeightTexPath = ASSET_PATH + TEXTURE_PATH + "/m_3D.png";
	
	//wood board paths
	string woodDiffTexPath = ASSET_PATH + TEXTURE_PATH + "/wood3_color.png";
	string woodSpecTexPath = ASSET_PATH + TEXTURE_PATH + "/wood3_spec.png";
	string woodBumpTexPath = ASSET_PATH + TEXTURE_PATH + "/wood3_normal.png";
	string woodHeightTexPath = ASSET_PATH + TEXTURE_PATH + "/wood3_height.png";

	
	 
	//creates new game object and loads a model
	shared_ptr<GameObject> m_TestGO = shared_ptr<GameObject>(loadModelFromFile(anvilPath));
	//loads shaders
	m_TestGO->loadShaders(parallaxMappingVSPath, parallaxMappingFSPath);
	m_TestGO->loadDiffuseTexture(metalDiffTexPath);
	m_TestGO->loadSpecularTexture(metalSpecTexPath);
	m_TestGO->loadNormalTexture(metalBumpTexPath);
	m_TestGO->loadHeightMapTexture(metalHeightTexPath);
	//set scale and positions
	m_TestGO->setPosition(vec3(-20.0f, -10.0f, -80.f));
	m_TestGO->setRotation(vec3(92.7, 0.0, -5.0f));
	m_TestGO->setScale(vec3(0.5,0.5,0.5));
	m_GameObjects.push_back(m_TestGO);
	
	//table
	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(understandPath));
	m_TestGO->loadShaders(parallaxMappingVSPath, parallaxMappingFSPath);
	m_TestGO->loadDiffuseTexture(woodDiffTexPath);
	m_TestGO->loadSpecularTexture(woodSpecTexPath);
	m_TestGO->loadNormalTexture(woodBumpTexPath);
	m_TestGO->loadHeightMapTexture(woodHeightTexPath);
	m_TestGO->setPosition(vec3(50.0f, -30.0f, -100.0f));
	m_TestGO->setRotation(vec3(5, 0, -1));
	m_TestGO->setScale(vec3(1.5, 1.5, 1.5));
	m_GameObjects.push_back(m_TestGO);
	
	
	m_CameraPosition = vec3(0.0f, 0.0f, 10.0f);
	m_ViewDirection = vec3(0.0f, 0.0f, -10.0f);

	//lighting
	m_Light = shared_ptr<Light>(new Light());
	m_Light->DiffuseColour = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SpecularColour = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->Direction = vec3(0.0f, 0.0f, -1.0f);
	m_AmbientLightColour = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	
}

void MyGame::onKeyDown(SDL_Keycode keyCode)
{
	
	//controls rotation of camera

	if (keyCode == SDLK_w)
	{
		m_CameraPosition += movementSpeed * m_ViewDirection;

	}
	else if(keyCode == SDLK_s)
	{
		m_CameraPosition += -movementSpeed * m_ViewDirection;

	}
	else if (keyCode == SDLK_a)
	{
		m_CameraPosition.x += -movementSpeed;

	}
	else if (keyCode == SDLK_d)
	{
		m_CameraPosition.x += movementSpeed;


	}

	



	//input for movement
	if (keyCode == SDLK_DOWN)
	{
		m_ViewDirection.y += -movementSpeed;
	}
	else if (keyCode == SDLK_UP)
	{
		m_ViewDirection.y += movementSpeed;

	}
	else if (keyCode == SDLK_RIGHT)
	{
		m_ViewDirection.x += movementSpeed;

	}
	else if (keyCode == SDLK_LEFT)
	{
		m_ViewDirection.x += -movementSpeed;

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
	m_ViewMatrix = lookAt(m_CameraPosition, m_CameraPosition + m_ViewDirection, vec3(0.0,1.0,0.0));
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
		object->onBeginRender();
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
