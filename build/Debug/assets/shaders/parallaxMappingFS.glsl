#version 410

out vec4 FragColor;

in vec2 vertexTextureCoordsOut;
in vec3 vertexNormalOut;
in vec3 cameraDirectionOut;
in vec3 lightDirectionOut;
in vec4 vertexColoursOut;
in mat3 tangentMatrix;

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
	
	vec2 correctedTexCoord = scale*vertexTextureCoordsOut.xy*height-bias;
	correctedTexCoord = vertexTextureCoordsOut-correctedTexCoord;

	vec3 bumpNormals = 2.0f*texture(normalSampler,correctedTexCoord).rgb-1.0f;
	bumpNormals = normalize(bumpNormals);
	
	vec3 lightDir=normalize(tangentMatrix*(-directionLight.direction));
	float diffuseTerm = dot(bumpNormals, lightDir);
	vec3 halfWayVec = normalize(cameraDirectionOut + lightDir);
	float specularTerm = pow(dot(bumpNormals, halfWayVec), specularPower);
	
	
	vec4 diffuseTextureColour = texture(diffuseSampler, correctedTexCoord);
	vec4 specularTextureColour = texture(specularSampler, correctedTexCoord);
	
	vec4 ambientColour = ambientMaterialColour*directionLight.ambientColour;
	vec4 diffuseColour = diffuseTextureColour*directionLight.diffuseColour*diffuseTerm;
	vec4 specularColour = specularTextureColour*directionLight.specularColour*specularTerm;
	
	FragColor = ambientColour + diffuseColour + specularColour;
}
