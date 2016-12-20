#ifndef LIGHT_H
#define LIGHT_H

#include "Common.h"

struct Light
{
	vec3 position;
	vec4 DiffuseColour;
	vec4 SpecularColour;

	float constant;
	float linear;
	float quadratic;

};

#endif
