#version 410

out vec4 FragColor;

in vec2 vertexTextureCoordsOut;
in vec3 vertexNormalOut;
in vec3 cameraDirectionOut;
in vec3 lightDirectionOut;
in vec4 vertexColoursOut;
in mat3 tangentMatrix;
in vec3 worldPos;

uniform vec4 ambientMaterialColour;
uniform vec4 diffuseMaterialColour;
uniform vec4 specularMaterialColour;
uniform float specularPower;

uniform float bias = 0.03f;
uniform float scale = 0.015f;

uniform sampler2D diffuseSampler;
uniform sampler2D specularSampler;
uniform sampler2D normalSampler;
uniform sampler2D heightSampler;



/*
struct DirectionalLight
{
	 vec4 ambientColour;
	 vec4 diffuseColour;
	 vec4 specularColour;
	 
	 vec3 direction;
};

uniform DirectionalLight directionLight;
*/

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
	float height = texture(heightSampler,vertexTextureCoordsOut).r;
	
	vec2 correctedTexCoord = scale*vertexTextureCoordsOut.xy*height-bias;
	correctedTexCoord = vertexTextureCoordsOut-correctedTexCoord;

	vec3 bumpNormals = 2.0f*texture(normalSampler,correctedTexCoord).rgb-1.0f;
	bumpNormals = normalize(bumpNormals);
	
	vec3 lightDir=normalize(pointLight.position - worldPos);
	float diffuseTerm = dot(bumpNormals, lightDir);
	vec3 halfWayVec = normalize(lightDir);
	float specularTerm = pow(dot(bumpNormals, halfWayVec), specularPower);
	
	
	vec4 diffuseTextureColour = texture(diffuseSampler, correctedTexCoord);
	vec4 specularTextureColour = texture(specularSampler, correctedTexCoord);
	
	vec4 ambientColour = ambientMaterialColour*pointLight.ambientColour;
	vec4 diffuseColour = diffuseTextureColour*pointLight.diffuseColour*diffuseTerm;
	vec4 specularColour = specularTextureColour*pointLight.specularColour*specularTerm;
	
	
	//attenuation
	float distance = length(pointLight.position - worldPos);
	float attenuation = 1.0f / (1.0f + 0.01f * distance + 0	*(distance * distance));
	ambientColour *= attenuation;
	diffuseColour *= attenuation;
	specularColour *= attenuation;
	
	FragColor = ambientColour + diffuseColour + specularColour;
}
