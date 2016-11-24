<<<<<<< HEAD
#version 150

out vec4 FragColor;

in vec3 vertexNormalOut;
in vec3 cameraDirectionOut;
in vec3 lightDirectionOut;
in vec2 texCoordsOut;

uniform vec4 ambientMaterialColour;
uniform vec4 diffuseMaterialColour;
uniform vec4 specularMaterialColour;
uniform float specularPower;

uniform vec4 ambientLightColour;
uniform vec4 diffuseLightColour;
uniform vec4 specularLightColour;

uniform sampler2D diffuseMap;
uniform sampler2D specMap;
uniform sampler2D bumpMap;
uniform sampler2D heightMap;

uniform float bias = 0.03;
uniform float scale = 0.015;

void main()
{
	//retrieve height from texture
	float height = texture(heightMap, texCoordsOut).r;

	//use offset limits(scale and bias) to move texture coords
	vec2 correctedTexCoords = scale*texCoordsOut.xy*height;

	//Calculate new texture coords, we use these instead of normal texture coords
	correctedTexCoords=texCoordsOut-correctedTexCoords;

	//get normals from normal map, rescale from 0 to 1 to -1 to 1
	vec3 bumpNormals = 2.0 * texture(bumpMap, correctedTexCoords).rgb - 1.0;

	//normalize!!
	bumpNormals = normalize(bumpNormals);

	//now use bumpnormals in reflectance calculate
	float diffuseTerm = dot(bumpNormals, lightDirectionOut);
	vec3 halfWayVec = normalize(cameraDirectionOut + lightDirectionOut);
	float specularTerm = pow(dot(bumpNormals, halfWayVec), specularPower);

	vec4 diffuseTextureColour = texture(diffuseMap, correctedTexCoords);
	vec4 specTextureColour = texture(specMap, correctedTexCoords);

	FragColor = (ambientMaterialColour*ambientLightColour) + ((diffuseMaterialColour + diffuseTextureColour)*diffuseLightColour*diffuseTerm) + ((specularMaterialColour + specTextureColour)*specularLightColour*specularTerm);
}
=======
#version 410

out vec4 FragColor;

in vec2 vertexTextureCoordsOut;
in vec3 vertexNormalOut;
in vec3 cameraDirectionOut;
in vec3 lightDirectionOut;
in vec4 vertexColoursOut;


uniform vec4 ambientMaterialColour=vec4(0.5f,0.0f,0.0f,1.0f);
uniform vec4 diffuseMaterialColour=vec4(0.8f,0.0f,0.0f,1.0f);
uniform vec4 specularMaterialColour=vec4(1.0f,1.0f,1.0f,1.0f);
uniform float specularPower=25.0f;

uniform float bias = 0.03f;
uniform float scale = 0.015f;

uniform sampler2D diffuseSampler;
uniform sampler2D specularSampler;
uniform sampler2D normalSampler;
uniform sampler2D heightSampler;




struct DirectionalLight
{
	 vec4 ambientColour;
	 vec4 diffuseColour;
	 vec4 specularColour;
	 
	 vec3 direction;
};

uniform DirectionalLight directionLight;



void main()
{
	float height = texture(heightSampler,vertexTextureCoordsOut).r;
	
	vec2 correctedTexCoord = scale*vertexTextureCoordsOut*height-bias;
	correctedTexCoord = vertexTextureCoordsOut-correctedTexCoord;

	vec3 bumpNormals = 2.0f*(texture(normalSampler,correctedTexCoord).xyz)-1.0f;
	bumpNormals = normalize(bumpNormals);
	
	vec3 lightDir=normalize(-directionLight.direction);
	float diffuseTerm = dot(bumpNormals, lightDir);
	vec3 halfWayVec = normalize(cameraDirectionOut + lightDir);
	float specularTerm = pow(dot(bumpNormals, halfWayVec), specularPower);
	
	
	vec4 diffuseTextureColour = texture(diffuseSampler, correctedTexCoord);
	vec4 specularTextureColour = texture(specularSampler, correctedTexCoord);
	
	vec4 ambientColour = ambientMaterialColour*directionLight.ambientColour;
	vec4 diffuseColour = diffuseTextureColour*directionLight.diffuseColour*diffuseTerm;
	vec4 specularColour = specularTextureColour*directionLight.specularColour*specularTerm;
	
	//FragColor = vec4(1.0f,1.0f,1.0f,1.0f);
	FragColor = ambientColour + diffuseColour + specularColour;
}
>>>>>>> refs/remotes/origin/master
