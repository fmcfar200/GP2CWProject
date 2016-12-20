#version 410

out vec4 FragColor;

in vec2 vertexTextureCoordsOut;
in vec3 vertexNormalOut;
in vec3 cameraDirectionOut;
in vec4 vertexColoursOut;
in mat3 tangentMatrix;
in vec3 worldPos;

uniform vec4 ambientMaterialColour;
uniform vec4 diffuseMaterialColour;
uniform vec4 specularMaterialColour;
uniform float specularPower=25.0f;

uniform sampler2D diffuseSampler;
uniform sampler2D specularSampler;
uniform sampler2D normalSampler;


	//// FRASER CODE

struct PointLight
{
	vec3 position;
	
	vec4 ambientColour;
	vec4 diffuseColour;
	vec4 specularColour;
	
	float constant;
	float linear;
	float quadratic;
};
 
uniform PointLight pointLight;


void main()
{

	vec3 bumpNormals = 2.0f * texture(normalSampler,vertexTextureCoordsOut).r - 1.0f;
	bumpNormals = normalize(bumpNormals);
	
		//// FRASER CODE

	//tangent multiple gone
	vec3 lightDir=normalize(pointLight.position - worldPos);
	float diffuseTerm = dot(bumpNormals, lightDir);
	vec3 halfWayVec = normalize(cameraDirectionOut + lightDir);
	float specularTerm = pow(dot(bumpNormals, halfWayVec), specularPower);
	
	
	vec4 diffuseTextureColour = texture(diffuseSampler, vertexTextureCoordsOut);
	vec4 specularTextureColour = texture(specularSampler, vertexTextureCoordsOut);
	
	vec4 ambientColour = ambientMaterialColour*pointLight.ambientColour;
	vec4 diffuseColour = diffuseTextureColour*pointLight.diffuseColour*diffuseTerm;
	vec4 specularColour = specularTextureColour*pointLight.specularColour*specularTerm;
	
		//// FRASER CODE

	//attenuation
	float distance = length(pointLight.position - worldPos);
	float attenuation = 1.0f / (1.0f + 0.01f * distance + 0	*(distance * distance));
	ambientColour *= attenuation;
	diffuseColour *= attenuation;
	specularColour *= attenuation;
	
	FragColor = ambientColour + diffuseColour + specularColour;
}
