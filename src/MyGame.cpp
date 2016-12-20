#include "MyGame.h"
const std::string ASSET_PATH = "assets";
const std::string SHADER_PATH = "/shaders";
const std::string TEXTURE_PATH = "/textures";
const std::string MODEL_PATH = "/models";

MyGame::MyGame()
{
	testX = m_WindowWidth / 2;
	testY = m_WindowHeight / 2;
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
	string lanternPath = ASSET_PATH + MODEL_PATH + "/lantern.fbx";
	


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

	string newNormalMappingVSPath = ASSET_PATH + SHADER_PATH + "/newNormalMappingVS.glsl";
	string newNormalMappingFSPath = ASSET_PATH + SHADER_PATH + "/newNormalMappingFS.glsl";
	
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
	string swd3DiffTexPath = ASSET_PATH + TEXTURE_PATH + "/sword4_c.png";
	string swd3SpecTexPath = ASSET_PATH + TEXTURE_PATH + "/sword4_S.png";
	string swd3BumpTexPath = ASSET_PATH + TEXTURE_PATH + "/sword4_N.png";
	string swd3HeightTexPath = ASSET_PATH + TEXTURE_PATH + "/sword4_D.png";

	//wood board paths
	string woodDiffTexPath = ASSET_PATH + TEXTURE_PATH + "/wood3_color.png";
	string woodSpecTexPath = ASSET_PATH + TEXTURE_PATH + "/wood3_spec.png";
	string woodBumpTexPath = ASSET_PATH + TEXTURE_PATH + "/wood3_normal.png";
	string woodHeightTexPath = ASSET_PATH + TEXTURE_PATH + "/wood3_height.png";
	

	//// FRASER CODE

	 // Anvil Model
	//creates new game object and loads a model
	shared_ptr<GameObject> m_TestGO = shared_ptr<GameObject>(loadModelFromFile(anvilPath));
	//loads shaders  (Anvil)
	//// FRASER CODE (SHADER FILES)
	m_TestGO->getMaterial()->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->getMaterial()->loadDiffuseTexture(metalDiffTexPath);
	m_TestGO->getMaterial()->loadSpecularTexture(metalSpecTexPath);
	m_TestGO->getMaterial()->loadNormalTexture(metalBumpTexPath);
	m_TestGO->getMaterial()->loadHeightMapTexture(metalHeightTexPath);
	//set scale and positions (Anivl)
	m_TestGO->getTransform()->setPosition(vec3(-80, -0, -130));
	m_TestGO->getTransform()->setRotation(vec3(92.7, 0, -5.0f));
	m_TestGO->getTransform()->setScale(vec3(1,1,1));
	m_GameObjects.push_back(m_TestGO);


	//axe 2
	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(axe2Path));
	m_TestGO->getMaterial()->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->getMaterial()->loadDiffuseTexture(axe2DiffTexPath);
	m_TestGO->getMaterial()->loadSpecularTexture(axe2SpecTexPath);
	m_TestGO->getMaterial()->loadNormalTexture(axe2BumpTexPath);
	m_TestGO->getMaterial()->loadHeightMapTexture(axe2HeightTexPath);
	m_TestGO->getTransform()->setPosition(vec3(-20, 100, -190));
	m_TestGO->getTransform()->setRotation(vec3(92.7, 1.8, -5.0f));
	m_TestGO->getTransform()->setScale(vec3(50, 50, 50));
	m_GameObjects.push_back(m_TestGO);


	//shield
	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(shieldPath));
	m_TestGO->getMaterial()->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->getMaterial()->loadDiffuseTexture(shieldDiffTexPath);
	m_TestGO->getMaterial()->loadSpecularTexture(shieldSpecTexPath);
	m_TestGO->getMaterial()->loadNormalTexture(shieldBumpTexPath);
	m_TestGO->getMaterial()->loadHeightMapTexture(shieldHeightTexPath);
	m_TestGO->getTransform()->setPosition(vec3(-20, 100, -180));
	m_TestGO->getTransform()->setRotation(vec3(92.7, 4.9, -5.0f));
	m_TestGO->getTransform()->setScale(vec3(1, 1, 1));
	m_GameObjects.push_back(m_TestGO);


	//knife
	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(knifePath));
	m_TestGO->getMaterial()->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->getMaterial()->loadDiffuseTexture(knifeDiffTexPath);
	m_TestGO->getMaterial()->loadSpecularTexture(knifeSpecTexPath);
	m_TestGO->getMaterial()->loadNormalTexture(knifeBumpTexPath);
	m_TestGO->getMaterial()->loadHeightMapTexture(knifeHeightTexPath);
	m_TestGO->getTransform()->setPosition(vec3(-110, 65.5, 10.0f));
	m_TestGO->getTransform()->setRotation(vec3(0, 2, 0));
	m_TestGO->getTransform()->setScale(vec3(0.5, 0.5, 0.5));
	m_GameObjects.push_back(m_TestGO);

	//swords
	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(sword1Path));
	m_TestGO->getMaterial()->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->getMaterial()->loadDiffuseTexture(swd1DiffTexPath);
	m_TestGO->getMaterial()->loadSpecularTexture(swd1SpecTexPath);
	m_TestGO->getMaterial()->loadNormalTexture(swd1BumpTexPath);
	m_TestGO->getMaterial()->loadHeightMapTexture(swd1HeightTexPath);
	m_TestGO->getTransform()->setPosition(vec3(-80, 40, -130));
	m_TestGO->getTransform()->setRotation(vec3(0, 0, 1.5f));
	m_TestGO->getTransform()->setScale(vec3(0.5, 0.5, 0.5));
	m_GameObjects.push_back(m_TestGO);

	//swords
	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(sword2Path));
	m_TestGO->getMaterial()->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->getMaterial()->loadDiffuseTexture(swd2DiffTexPath);
	m_TestGO->getMaterial()->loadSpecularTexture(swd2SpecTexPath);
	m_TestGO->getMaterial()->loadNormalTexture(swd2BumpTexPath);
	m_TestGO->getMaterial()->loadHeightMapTexture(swd2HeightTexPath);
	m_TestGO->getTransform()->setPosition(vec3(100, 10.0f, -80.0f));
	m_TestGO->getTransform()->setRotation(vec3(92.7, 0, -5.0f));
	m_TestGO->getTransform()->setScale(vec3(0.25, 0.25, 0.25));
	m_GameObjects.push_back(m_TestGO);

	//swords
	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(sword3Path));
	m_TestGO->getMaterial()->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->getMaterial()->loadDiffuseTexture(swd3DiffTexPath);
	m_TestGO->getMaterial()->loadSpecularTexture(swd3SpecTexPath);
	m_TestGO->getMaterial()->loadNormalTexture(swd3BumpTexPath);
	m_TestGO->getMaterial()->loadHeightMapTexture(swd3HeightTexPath);
	m_TestGO->getTransform()->setPosition(vec3(-140, 100, -100));
	m_TestGO->getTransform()->setRotation(vec3(92.7, 0, 1.5f));
	m_TestGO->getTransform()->setScale(vec3(1, 1, 1));
	m_GameObjects.push_back(m_TestGO);

	//walls
	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(wallPath));
	m_TestGO->getMaterial()->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->getMaterial()->loadDiffuseTexture(brickDiffTexPath);
	m_TestGO->getMaterial()->loadSpecularTexture(brickSpecTexPath);
	m_TestGO->getMaterial()->loadNormalTexture(brickBumpTexPath);
	m_TestGO->getMaterial()->loadHeightMapTexture(brickHeightTexPath);
	m_TestGO->getTransform()->setPosition(vec3(-20, 0, -200));
	m_TestGO->getTransform()->setRotation(vec3(0, 0, -0));
	m_TestGO->getTransform()->setScale(vec3(0.5, 1, 1));
	m_GameObjects.push_back(m_TestGO);

	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(wallPath));
	m_TestGO->getMaterial()->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->getMaterial()->loadDiffuseTexture(brickDiffTexPath);
	m_TestGO->getMaterial()->loadSpecularTexture(brickSpecTexPath);
	m_TestGO->getMaterial()->loadNormalTexture(brickBumpTexPath);
	m_TestGO->getMaterial()->loadHeightMapTexture(brickHeightTexPath);
	m_TestGO->getTransform()->setPosition(vec3(-150, 0, -50));
	m_TestGO->getTransform()->setRotation(vec3(0, 4.75, -0));
	m_TestGO->getTransform()->setScale(vec3(0.5, 1, 1));
	m_GameObjects.push_back(m_TestGO);

	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(wallPath));
	m_TestGO->getMaterial()->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->getMaterial()->loadDiffuseTexture(brickDiffTexPath);
	m_TestGO->getMaterial()->loadSpecularTexture(brickSpecTexPath);
	m_TestGO->getMaterial()->loadNormalTexture(brickBumpTexPath);
	m_TestGO->getMaterial()->loadHeightMapTexture(brickHeightTexPath);
	m_TestGO->getTransform()->setPosition(vec3(120, 0, -50));
	m_TestGO->getTransform()->setRotation(vec3(0, 4.75, -0));
	m_TestGO->getTransform()->setScale(vec3(0.5, 1, 1));
	m_GameObjects.push_back(m_TestGO);

	//floors
	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(wallPath));
	m_TestGO->getMaterial()->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->getMaterial()->loadDiffuseTexture(brickDiffTexPath);
	m_TestGO->getMaterial()->loadSpecularTexture(brickSpecTexPath);
	m_TestGO->getMaterial()->loadNormalTexture(brickBumpTexPath);
	m_TestGO->getMaterial()->loadHeightMapTexture(brickHeightTexPath);
	m_TestGO->getTransform()->setPosition(vec3(-150, 0, -50));
	m_TestGO->getTransform()->setRotation(vec3(4.7, 4.75, 0));
	m_TestGO->getTransform()->setScale(vec3(0.5, 1.5, 1));
	m_GameObjects.push_back(m_TestGO);

	//shelf
	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(woodBoardPath));
	m_TestGO->getMaterial()->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->getMaterial()->loadDiffuseTexture(woodDiffTexPath);
	m_TestGO->getMaterial()->loadSpecularTexture(woodSpecTexPath);
	m_TestGO->getMaterial()->loadNormalTexture(woodBumpTexPath);
	m_TestGO->getMaterial()->loadHeightMapTexture(woodHeightTexPath);
	m_TestGO->getTransform()->setPosition(vec3(-140, 50, -20));
	m_TestGO->getTransform()->setRotation(vec3(3.3, 4.75, 0));
	m_TestGO->getTransform()->setScale(vec3(1.5, 1.5, 1.5));
	m_GameObjects.push_back(m_TestGO);

	//lantern
	m_TestGO = shared_ptr<GameObject>(loadModelFromFile(lanternPath));
	m_TestGO->getMaterial()->loadShaders(newParallaxMappingVSPath, newParallaxMappingFSPath);
	m_TestGO->getMaterial()->loadDiffuseTexture(metalDiffTexPath);
	m_TestGO->getMaterial()->loadSpecularTexture(metalSpecTexPath);
	m_TestGO->getMaterial()->loadNormalTexture(metalBumpTexPath);
	m_TestGO->getMaterial()->loadHeightMapTexture(metalHeightTexPath);
	m_TestGO->getTransform()->setPosition(vec3(100, 100, -50));
	m_TestGO->getTransform()->setRotation(vec3(4.75, 4.75, 0));
	m_TestGO->getTransform()->setScale(vec3(1, 1, 1));
	m_GameObjects.push_back(m_TestGO);

	m_Camera = shared_ptr<Camera>(new Camera());
	m_Camera->setCameraPosition(vec3(0, 40, -10));
	m_Camera->setViewDirection(vec3(0, 0, -10));

	//// FRASER CODE

	//lighting
	shared_ptr<Light> m_Light = shared_ptr<Light>(new Light());
	m_Light->DiffuseColour = vec4(2.5f, 1.7f, 1.1f, 1.0f);
	m_Light->SpecularColour = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->position = vec3(100, 100, 50);
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
		m_Camera->MoveForward();

	}
	else if (keyCode == SDLK_s)
	{
		m_Camera->MoveBackwards();

	}
	else if (keyCode == SDLK_a)
	{
		m_Camera->MoveLeft();

	}
	else if (keyCode == SDLK_d)
	{
		m_Camera->MoveRight();


	}

	if (keyCode == SDLK_DOWN)
	{
		//m_Camera->LookDown();


	}
	else if (keyCode == SDLK_UP)
	{

		//m_Camera->LookUp();

	}
	else if (keyCode == SDLK_RIGHT)
	{
		//m_Camera->LookRight();

	}
	else if (keyCode == SDLK_LEFT)
	{
		//m_Camera->LookLeft();

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
	m_Lights.clear();
}


void MyGame::update()
{
	GameApplication::update();
	//m_Camera->MoveMouse();
	//cycles through all game objects and updates
	for (auto& object : m_GameObjects)
	{
		object->onUpdate();

	}
	m_Camera->MoveMouse();
	m_ProjMatrix = perspective(radians(45.0f), (float)getWindowWidth() / (float)getWindowHeight(), 0.1f, 1000.0f);
	m_ViewMatrix = (lookAt(m_Camera->getCameraPos(), m_Camera->getCameraPos() + m_Camera->getCameraViewDirection(), m_Camera->getUP()));
	

}

void MyGame::render()
{
	GameApplication::render();
	for (auto& object : m_GameObjects)
	{
		object->onBeginRender();
		GLuint currentShader = object->getMaterial()->getShaderProgram();

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
		glUniform3fv(cameraPositionLocation, 1, value_ptr(m_Camera->getCameraPos()));

		
		}
		object->onRender(m_ViewMatrix, m_ProjMatrix);

	}


	
}

