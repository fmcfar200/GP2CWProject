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
	string anvilPath = ASSET_PATH + MODEL_PATH + "/anvil.fbx";
	string axe1HeadPath = ASSET_PATH + MODEL_PATH + "/2h_axe.fbx";
	string axe1Path = ASSET_PATH + MODEL_PATH + "/1h_axe.fbx";
	string axe2Path = ASSET_PATH + MODEL_PATH + "/axe2.fbx";
	string shieldPath = ASSET_PATH + MODEL_PATH + "/shield_deco3.fbx";
	string knifePath = ASSET_PATH + MODEL_PATH + "/knife2.fbx";
	string sword1Path = ASSET_PATH + MODEL_PATH + "/sword.fbx";
	string sword2Path = ASSET_PATH + MODEL_PATH + "/sword2.fbx";
	string sword3Path = ASSET_PATH + MODEL_PATH + "/sword4.fbx";
	string wallPath = ASSET_PATH + MODEL_PATH + "/wall.fbx";
	string woodBoardPath = ASSET_PATH + MODEL_PATH + "/woodboard.fbx";

	


	//light texture vs and fs path
	string lightTextureVSPath = ASSET_PATH + SHADER_PATH + "/lightTextureVS.glsl";
	string lightTextureFSPath = ASSET_PATH + SHADER_PATH + "/lightTextureFS.glsl";

	//normal mapping paths
	string normalMappingVSPath = ASSET_PATH + SHADER_PATH + "/normalMappingVS.glsl";
	string normalMappingFSPath = ASSET_PATH + SHADER_PATH + "/normalMappingFS.glsl";

	//parallax paths
	string parallaxMappingVSPath = ASSET_PATH + SHADER_PATH + "/parallaxMappingVS.glsl";
	string parallaxMappingFSPath = ASSET_PATH + SHADER_PATH + "/parallaxMappingFS.glsl";
	
	string newParallaxMappingVSPath = ASSET_PATH + SHADER_PATH + "/newParallaxMappingVS.glsl";
	string newParallaxMappingFSPath = ASSET_PATH + SHADER_PATH + "/newParallaxMappingFS.glsl";
	
	//brick textures
	string brickDiffTexPath = ASSET_PATH + TEXTURE_PATH + "/s_3_1.png";
	string brickSpecTexPath = ASSET_PATH + TEXTURE_PATH + "/s_3S.png";
	string brickBumpTexPath = ASSET_PATH + TEXTURE_PATH + "/s_3N.png";
	string brickHeightTexPath = ASSET_PATH + TEXTURE_PATH + "/s_3D.png";

	//metal paths
	string metalDiffTexPath = ASSET_PATH + TEXTURE_PATH + "/m_3.png";
	string metalSpecTexPath = ASSET_PATH + TEXTURE_PATH + "/m_3S.png";
	string metalBumpTexPath = ASSET_PATH + TEXTURE_PATH + "/m_3N.png";
	string metalHeightTexPath = ASSET_PATH + TEXTURE_PATH + "/m_3D.png";
	
	// Axe head 
	string axeDiffTexPath = ASSET_PATH + TEXTURE_PATH + "/2h_axe.png";
	string axeSpecTexPath = ASSET_PATH + TEXTURE_PATH + "/2h_axeS.png";
	string axeBumpTexPath = ASSET_PATH + TEXTURE_PATH + "/2h_axeN.png";
	string axeHeightTexPath = ASSET_PATH + TEXTURE_PATH + "/2h_axeD.png";

	//axe 2
	string axe2DiffTexPath = ASSET_PATH + TEXTURE_PATH + "/axe_col.png";
	string axe2SpecTexPath = ASSET_PATH + TEXTURE_PATH + "/axe_spec.png";
	string axe2BumpTexPath = ASSET_PATH + TEXTURE_PATH + "/axe_norm.png";
	string axe2HeightTexPath = ASSET_PATH + TEXTURE_PATH + "/axe_bump.png";
	//axe metal
	string axeMetal = ASSET_PATH + TEXTURE_PATH + "/2_axe_metal.png";

	//shield
	string shieldDiffTexPath = ASSET_PATH + TEXTURE_PATH + "/shield_C.png";
	string shieldSpecTexPath = ASSET_PATH + TEXTURE_PATH + "/shield_S.png";
	string shieldBumpTexPath = ASSET_PATH + TEXTURE_PATH + "/shield_N.png";
	string shieldHeightTexPath = ASSET_PATH + TEXTURE_PATH + "/shield_D.png";

	//knife
	string knifeDiffTexPath = ASSET_PATH + TEXTURE_PATH + "/kn5_COL.png";
	string knifeSpecTexPath = ASSET_PATH + TEXTURE_PATH + "/kn5_SPEC.png";
	string knifeBumpTexPath = ASSET_PATH + TEXTURE_PATH + "/kn5_NRM.png";
	string knifeHeightTexPath = ASSET_PATH + TEXTURE_PATH + "/kn5_DISP.png";

	//sword1
	string swd1DiffTexPath = ASSET_PATH + TEXTURE_PATH + "/sword_C.png";
	string swd1SpecTexPath = ASSET_PATH + TEXTURE_PATH + "/sword_S.png";
	string swd1BumpTexPath = ASSET_PATH + TEXTURE_PATH + "/sword_N.png";
	string swd1HeightTexPath = ASSET_PATH + TEXTURE_PATH + "/sword_D.png";

	//sword2
	string swd2DiffTexPath = ASSET_PATH + TEXTURE_PATH + "/sword2_C.png";
	string swd2SpecTexPath = ASSET_PATH + TEXTURE_PATH + "/sword2_S.png";
	string swd2BumpTexPath = ASSET_PATH + TEXTURE_PATH + "/sword2_N.png";
	string swd2HeightTexPath = ASSET_PATH + TEXTURE_PATH + "/sword2_D.png";

	//sword3
	string swd3DiffTexPath = ASSET_PATH + TEXTURE_PATH + "/sword4_C.png";
	string swd3SpecTexPath = ASSET_PATH + TEXTURE_PATH + "/sword4_S.png";
	string swd3HeightTexPath = ASSET_PATH + TEXTURE_PATH + "/sword4_D.png";

	//wood board paths
	string woodDiffTexPath = ASSET_PATH + TEXTURE_PATH + "/wood3_color.png";
	string woodSpecTexPath = ASSET_PATH + TEXTURE_PATH + "/wood3_spec.png";
	string woodBumpTexPath = ASSET_PATH + TEXTURE_PATH + "/wood3_normal.png";
	string woodHeightTexPath = ASSET_PATH + TEXTURE_PATH + "/wood3_height.png";
		   
	 // Anvil Model
	//creates new game object and loads a model
	shared_ptr<GameObject> m_TestGO = shared_ptr<GameObject>(loadModelFromFile(anvilPath));
	//loads shaders  (Anvil)
	m_TestGO->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->loadDiffuseTexture(metalDiffTexPath);
	m_TestGO->loadSpecularTexture(metalSpecTexPath);
	m_TestGO->loadNormalTexture(metalBumpTexPath);
	//m_TestGO->loadHeightMapTexture(metalHeightTexPath);
	//set scale and positions (Anivl)
	m_TestGO->setPosition(vec3(-80, -0, -130));
	m_TestGO->setRotation(vec3(92.7, 0, -5.0f));
	m_TestGO->setScale(vec3(1,1,1));
	m_GameObjects.push_back(m_TestGO);

	/*
	//AXE 1
	//Axe Head
	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(axe1HeadPath));
	m_TestGO->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->loadDiffuseTexture(axeDiffTexPath);
	m_TestGO->loadSpecularTexture(axeSpecTexPath);
	m_TestGO->loadNormalTexture(axeBumpTexPath);
	m_TestGO->loadHeightMapTexture(axeHeightTexPath);
	m_TestGO->setPosition(vec3(23, 10.0f, -80.0f));
	m_TestGO->setRotation(vec3(92.7, 0, -5.0f));
	m_TestGO->setScale(vec3(0.5f, 0.5f, 0.5f));
	m_GameObjects.push_back(m_TestGO);
	//Axe Handle 
	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(axe1Path));
	m_TestGO->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->loadDiffuseTexture(axeMetal);
	m_TestGO->setPosition(vec3(23.5f, 20.0f, -85.0f));
	m_TestGO->setRotation(vec3(92.7, 0, -5.0f));
	m_TestGO->setScale(vec3(0.5f, 0.5f, 0.5f));
	m_GameObjects.push_back(m_TestGO);
	*/
	//axe 2
	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(axe2Path));
	m_TestGO->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->loadDiffuseTexture(axe2DiffTexPath);
	m_TestGO->loadSpecularTexture(axe2SpecTexPath);
	m_TestGO->loadNormalTexture(axe2BumpTexPath);
	m_TestGO->loadHeightMapTexture(axe2HeightTexPath);
	m_TestGO->setPosition(vec3(-20, 100, -190));
	m_TestGO->setRotation(vec3(92.7, 1.8, -5.0f));
	m_TestGO->setScale(vec3(50, 50, 50));
	m_GameObjects.push_back(m_TestGO);

	//shield
	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(shieldPath));
	m_TestGO->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->loadDiffuseTexture(shieldDiffTexPath);
	m_TestGO->loadSpecularTexture(shieldSpecTexPath);
	m_TestGO->loadNormalTexture(shieldBumpTexPath);
	m_TestGO->loadHeightMapTexture(shieldHeightTexPath);
	m_TestGO->setPosition(vec3(-20, 100, -180));
	m_TestGO->setRotation(vec3(92.7, 4.9, -5.0f));
	m_TestGO->setScale(vec3(1, 1, 1));
	m_GameObjects.push_back(m_TestGO);

	//knife
	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(knifePath));
	m_TestGO->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->loadDiffuseTexture(knifeDiffTexPath);
	m_TestGO->loadSpecularTexture(knifeSpecTexPath);
	m_TestGO->loadNormalTexture(knifeBumpTexPath);
	m_TestGO->loadHeightMapTexture(knifeHeightTexPath);
	m_TestGO->setPosition(vec3(120, 10.0f, -80.0f));
	m_TestGO->setRotation(vec3(92.7, 0, -5.0f));
	m_TestGO->setScale(vec3(0.5, 0.5, 0.5));
	m_GameObjects.push_back(m_TestGO);

	//swords
	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(sword1Path));
	m_TestGO->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->loadDiffuseTexture(swd1DiffTexPath);
	m_TestGO->loadSpecularTexture(swd1SpecTexPath);
	m_TestGO->loadNormalTexture(swd1BumpTexPath);
	m_TestGO->loadHeightMapTexture(swd1HeightTexPath);
	m_TestGO->setPosition(vec3(150, 10.0f, -80.0f));
	m_TestGO->setRotation(vec3(92.7, 0, -5.0f));
	m_TestGO->setScale(vec3(1, 1, 1));
	m_GameObjects.push_back(m_TestGO);

	//swords
	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(sword2Path));
	m_TestGO->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->loadDiffuseTexture(swd2DiffTexPath);
	m_TestGO->loadSpecularTexture(swd2SpecTexPath);
	m_TestGO->loadNormalTexture(swd2BumpTexPath);
	m_TestGO->loadHeightMapTexture(swd2HeightTexPath);
	m_TestGO->setPosition(vec3(180, 10.0f, -80.0f));
	m_TestGO->setRotation(vec3(92.7, 0, -5.0f));
	m_TestGO->setScale(vec3(0.25, 0.25, 0.25));
	m_GameObjects.push_back(m_TestGO);

	//swords
	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(sword3Path));
	m_TestGO->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->loadDiffuseTexture(swd3DiffTexPath);
	m_TestGO->loadSpecularTexture(swd3SpecTexPath);
	m_TestGO->loadHeightMapTexture(swd3HeightTexPath);
	m_TestGO->setPosition(vec3(210, 10.0f, -80.0f));
	m_TestGO->setRotation(vec3(92.7, 0, -5.0f));
	m_TestGO->setScale(vec3(2, 2, 2));
	m_GameObjects.push_back(m_TestGO);

	//walls
	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(wallPath));
	m_TestGO->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->loadDiffuseTexture(brickDiffTexPath);
	m_TestGO->loadSpecularTexture(brickSpecTexPath);
	m_TestGO->loadNormalTexture(brickBumpTexPath);
	m_TestGO->loadHeightMapTexture(brickHeightTexPath);
	m_TestGO->setPosition(vec3(-20, 0, -200));
	m_TestGO->setRotation(vec3(0, 0, -0));
	m_TestGO->setScale(vec3(0.5, 1, 1));
	m_GameObjects.push_back(m_TestGO);

	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(wallPath));
	m_TestGO->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->loadDiffuseTexture(brickDiffTexPath);
	m_TestGO->loadSpecularTexture(brickSpecTexPath);
	m_TestGO->loadNormalTexture(brickBumpTexPath);
	m_TestGO->loadHeightMapTexture(brickHeightTexPath);
	m_TestGO->setPosition(vec3(-150, 0, -50));
	m_TestGO->setRotation(vec3(0, 4.75, -0));
	m_TestGO->setScale(vec3(0.5, 1, 1));
	m_GameObjects.push_back(m_TestGO);

	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(wallPath));
	m_TestGO->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->loadDiffuseTexture(brickDiffTexPath);
	m_TestGO->loadSpecularTexture(brickSpecTexPath);
	m_TestGO->loadNormalTexture(brickBumpTexPath);
	m_TestGO->loadHeightMapTexture(brickHeightTexPath);
	m_TestGO->setPosition(vec3(120, 0, -50));
	m_TestGO->setRotation(vec3(0, 4.75, -0));
	m_TestGO->setScale(vec3(0.5, 1, 1));
	m_GameObjects.push_back(m_TestGO);

	//floors
	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(wallPath));
	m_TestGO->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->loadDiffuseTexture(brickDiffTexPath);
	m_TestGO->loadSpecularTexture(brickSpecTexPath);
	m_TestGO->loadNormalTexture(brickBumpTexPath);
	m_TestGO->loadHeightMapTexture(brickHeightTexPath);
	m_TestGO->setPosition(vec3(-150, 0, -50));
	m_TestGO->setRotation(vec3(4.7, 4.75, 0));
	m_TestGO->setScale(vec3(0.5, 1.5, 1));
	m_GameObjects.push_back(m_TestGO);

	//shelf
	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(woodBoardPath));
	m_TestGO->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->loadDiffuseTexture(woodDiffTexPath);
	m_TestGO->loadSpecularTexture(woodSpecTexPath);
	m_TestGO->loadNormalTexture(woodBumpTexPath);
	m_TestGO->loadHeightMapTexture(woodHeightTexPath);
	m_TestGO->setPosition(vec3(-140, 50, -50));
	m_TestGO->setRotation(vec3(3.3, 4.75, 0));
	m_TestGO->setScale(vec3(1, 1, 1));
	m_GameObjects.push_back(m_TestGO);



	// Camera Set up
	m_CameraPosition = vec3(0.0f, 40, 10.0f);
	m_ViewDirection = vec3(0.0f, 0.0f, -10.0f);

	//lighting
	shared_ptr<Light> m_Light = shared_ptr<Light>(new Light());
	m_Light->DiffuseColour = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SpecularColour = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->position = vec3(0, 0, 0);
	m_Light->constant = 1.0f;
	m_Light->linear = 0.9f;
	m_Light->quadratic = 0.032f;
	m_Lights.push_back(m_Light);

	m_Light = shared_ptr<Light>(new Light());
	m_Light->DiffuseColour = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SpecularColour = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->position = vec3(100, 250.0f, 50);
	m_Light->constant = 1.0f;
	m_Light->linear = 0.9f;
	m_Light->quadratic = 0.032f;
	m_Lights.push_back(m_Light);

	m_AmbientLightColour = vec4(0.2F,0.2F,0.2F, 1.0f);

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
		vec3 m_StrafeDirection = cross(m_ViewDirection, m_UP);
		m_CameraPosition += -movementSpeed*m_StrafeDirection;
	}
	else if (keyCode == SDLK_d)
	{
		vec3 m_StrafeDirection = cross(m_ViewDirection, m_UP);
		m_CameraPosition += movementSpeed*m_StrafeDirection;

	}

	if (keyCode == SDLK_DOWN)
	{
		m_ViewDirection.y += -movementSpeed*2;
	}
	else if (keyCode == SDLK_UP)
	{
		m_ViewDirection.y += movementSpeed*2;

	}
	else if (keyCode == SDLK_RIGHT)
	{
		m_ViewDirection.x += movementSpeed*2;

	}
	else if (keyCode == SDLK_LEFT)
	{
		m_ViewDirection.x += -movementSpeed*2;

	}
}

/*
void MyGame::mouseUpdate(const glm::vec2 & m_NewMousePosition)
{
	vec2 mouseDelta = m_NewMousePosition - m_OldMousePosition;
	m_ViewDirection = mat3(rotate(mouseDelta.x, m_UP)) * m_ViewDirection;
	m_OldMousePosition = m_NewMousePosition;
	
}
*/

void MyGame::destroyScene()
{
	//cycles through all game objects and destroys
	for (auto& object : m_GameObjects)
	{
		object->onDestroy();

	}

	//clears the list
	m_GameObjects.clear();
	m_Lights.clear();
}

void MyGame::update()
{
	GameApplication::update();

	m_ProjMatrix = perspective(radians(45.0f), (float)m_WindowWidth / (float)m_WindowHeight, 0.1f, 1000.0f);
	m_ViewMatrix = lookAt(m_CameraPosition, m_CameraPosition + m_ViewDirection, m_UP);
	//cycles through all game objects and updates
	for (auto& object : m_GameObjects)
	{
		object->onUpdate();

	}

	//m_Light->Direction = m_ViewDirection;
}

void MyGame::render()
{
	GameApplication::render();
	for (auto& object : m_GameObjects)
	{
		object->onBeginRender();
		GLuint currentShader = object->getShaderProgram();

		for (auto& lights : m_Lights)
		{
			GLint lightPositionLocation = glGetUniformLocation(currentShader, "pointLight.position");
		glUniform3fv(lightPositionLocation, 1, value_ptr(lights->position));

		GLint ambientLightColourLocation = glGetUniformLocation(currentShader, "pointLight.ambientColour");
		glUniform4fv(ambientLightColourLocation, 1, value_ptr(m_AmbientLightColour));

		GLint diffuseLightColourLocation = glGetUniformLocation(currentShader, "pointLight.diffuseColour");
		glUniform4fv(diffuseLightColourLocation, 1, value_ptr(lights->DiffuseColour));

		GLint specularLightColourLocation = glGetUniformLocation(currentShader, "pointLight.specularColour");
		glUniform4fv(specularLightColourLocation, 1, value_ptr(lights->SpecularColour));

		GLint cameraPositionLocation = glGetUniformLocation(currentShader, "cameraPos");
		glUniform3fv(cameraPositionLocation, 1, value_ptr(m_CameraPosition));

		
		}
		object->onRender(m_ViewMatrix, m_ProjMatrix);

	}


	
}
