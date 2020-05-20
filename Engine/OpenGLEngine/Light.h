#ifndef LIGHT_H
#define LIGHT_H

using namespace glm;

enum LightType {
	direction,
	point,
	spot
};

class Light
{
public:
	LightType lightType;
	static int lightID;
	vec3 diffuse;
	vec3 specular;
	vec3 ambient;
	vec3 position;
	vec3 direct;

	float intensity;
	float linear;
	float quadratic;
	float cutOff;
	float outerCutOff;
	float near_plane;
	float far_plane;
	float constant;
	int shadow_width;
	int shadow_height;

	mat4 dirLightSpaceMatrix;
	std::vector<mat4> cubeShadowTransforms;

	Light();
	Light(LightType type);
	~Light();

	void SetShaderInfo(Shader shader);
	void SetShaderUBO();
	std::vector<mat4> GetCubeShadowTransforms();
	mat4 GetDirLightSpaceMatrix();


private:

	int pointIndex;
	unsigned int uboLightBlock;



	void InitValue();
};
#endif