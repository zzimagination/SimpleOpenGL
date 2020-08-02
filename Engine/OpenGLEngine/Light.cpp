#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "ShaderProgram.h"
#include "Light.h"

int Light::lightID = 0;

void Light::InitValue()
{
	diffuse = vec3(1);
	specular = vec3(1);
	ambient = vec3(0.1f);

	intensity = 1;
	near_plane = 0.1f;
	far_plane = 25;
	constant = 1;
	linear = 0.09f;
	quadratic = 0.032f;
	cutOff =cos(radians(12.0f));
	outerCutOff =cos(radians(15.0f));
}

Light::Light(LightType type)
{
	lightType = type;

	InitValue();

	glGenBuffers(1, &uboLightBlock);
	glBindBuffer(GL_UNIFORM_BUFFER, uboLightBlock);
	GLsizeiptr size = 0;
	switch (type)
	{
	case direction:
		size = 16 *4 + 16*4;
		glBufferData(GL_UNIFORM_BUFFER, size, NULL, GL_STATIC_DRAW);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
		glBindBufferBase(GL_UNIFORM_BUFFER, 1, uboLightBlock);
		break;
	case point:
		size = 16 * 3 + 4 * 4;
		glBufferData(GL_UNIFORM_BUFFER, size, NULL, GL_STATIC_DRAW);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
		glBindBufferBase(GL_UNIFORM_BUFFER, 2, uboLightBlock);
		break;
	case spot:
		size = 16 * 4 + 4 * 5;
		glBufferData(GL_UNIFORM_BUFFER, size, NULL, GL_STATIC_DRAW);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
		glBindBufferBase(GL_UNIFORM_BUFFER, 3, uboLightBlock);
		break;
	default:
		break;
	}


	lightID++;
}

Light::~Light()
{

}
void Light::SetShaderUBO()
{
	glBindBuffer(GL_UNIFORM_BUFFER, uboLightBlock);

	switch (lightType)
	{

	case direction:
		glBufferSubData(GL_UNIFORM_BUFFER, 0, 16, glm::value_ptr(direct));
		glBufferSubData(GL_UNIFORM_BUFFER, 16, 16, glm::value_ptr(ambient*intensity));
		glBufferSubData(GL_UNIFORM_BUFFER, 32, 16, glm::value_ptr(diffuse*intensity));
		glBufferSubData(GL_UNIFORM_BUFFER, 48, 16, glm::value_ptr(specular*intensity));
		glBufferSubData(GL_UNIFORM_BUFFER, 64, sizeof(mat4), glm::value_ptr(dirLightSpaceMatrix));
		break;
	case point:
		glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(vec3), glm::value_ptr(position));
		glBufferSubData(GL_UNIFORM_BUFFER, 16, sizeof(vec3), glm::value_ptr(diffuse*intensity));
		glBufferSubData(GL_UNIFORM_BUFFER, 32, sizeof(vec3), glm::value_ptr(specular*intensity));
		
		glBufferSubData(GL_UNIFORM_BUFFER, 44, sizeof(float), &constant);
		glBufferSubData(GL_UNIFORM_BUFFER, 48, sizeof(float), &linear);
		glBufferSubData(GL_UNIFORM_BUFFER, 52, sizeof(float), &quadratic);
		glBufferSubData(GL_UNIFORM_BUFFER, 56, sizeof(float), &far_plane);
		break;
	case spot:
		glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(vec3), glm::value_ptr(position));
		glBufferSubData(GL_UNIFORM_BUFFER, 16, sizeof(vec3), glm::value_ptr(direct));
		glBufferSubData(GL_UNIFORM_BUFFER, 32, sizeof(vec3), glm::value_ptr(diffuse*intensity));
		glBufferSubData(GL_UNIFORM_BUFFER, 48, sizeof(vec3), glm::value_ptr(specular*intensity));

		glBufferSubData(GL_UNIFORM_BUFFER, 60, sizeof(float), &cutOff);
		glBufferSubData(GL_UNIFORM_BUFFER, 64, sizeof(float), &outerCutOff);
		glBufferSubData(GL_UNIFORM_BUFFER, 68, sizeof(float), &constant);
		glBufferSubData(GL_UNIFORM_BUFFER, 72, sizeof(float), &linear);
		glBufferSubData(GL_UNIFORM_BUFFER, 76, sizeof(float), &quadratic);



		break;
	default:
		break;
	}


	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}
void Light::SetShaderInfo(ShaderProgram shader)
{
	switch (lightType)
	{
	case direction:
		//直线光
		//shader.setVec3("_dirLight.direction", direct);
		//shader.setVec3("_dirLight.ambient", ambient*intensity);
		//shader.setVec3("_dirLight.diffuse", diffuse*intensity);
		//shader.setVec3("_dirLight.specular", specular*intensity);
		//shader.setMat4("_dirLightSpaceMatrix", dirLightSpaceMatrix);
		break;
	case point:
		//点光源
		//shader.setVec3("_pointLight.position", position);
		//shader.setVec3("_pointLight.diffuse", diffuse*intensity);
		//shader.setVec3("_pointLight.specular", specular*intensity);
		/*shader.setFloat("_pointLight.constant", constant);
		shader.setFloat("_pointLight.linear", linear);
		shader.setFloat("_pointLight.quadratic", quadratic);
		shader.setFloat("_pointLight.far_plane", far_plane);*/
		break;
	case spot:
		//聚光灯
		//shader.setVec3("_spotLight.position", position);
		//shader.setVec3("_spotLight.direction", direct);
		//shader.setVec3("_spotLight.diffuse", diffuse*intensity);
		//shader.setVec3("_spotLight.specular", specular*intensity);
		//shader.setFloat("_spotLight.constant", constant);
		//shader.setFloat("_spotLight.linear", linear);
		//shader.setFloat("_spotLight.quadratic", quadratic);
		//shader.setFloat("_spotLight.cutOff", cutOff);
		//shader.setFloat("_spotLight.outerCutOff", cutOff + outerCutOff + 0.001f);
		break;
	default:
		break;
	}
}

mat4 Light::GetDirLightSpaceMatrix()
{
	if (lightType != direction)
		return mat4();
	glm::mat4 lightProjection, lightView;
	lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, near_plane, far_plane);
	lightView = lookAt(position, glm::vec3(0.0f), glm::vec3(0.0, 1.0, 0.0));
	dirLightSpaceMatrix = lightProjection * lightView;
	return dirLightSpaceMatrix;
}

std::vector<mat4> Light::GetCubeShadowTransforms()
{
	if (lightType != point)
		return std::vector<mat4>();

	glm::mat4 shadowProj = glm::perspective(glm::radians(90.0f), (float)shadow_width / (float)shadow_height, near_plane, far_plane);
	cubeShadowTransforms.clear();
	cubeShadowTransforms.push_back(shadowProj *
		glm::lookAt(position, position + glm::vec3(1.0, 0.0, 0.0), glm::vec3(0.0, -1.0, 0.0)));
	cubeShadowTransforms.push_back(shadowProj *
		glm::lookAt(position, position + glm::vec3(-1.0, 0.0, 0.0), glm::vec3(0.0, -1.0, 0.0)));
	cubeShadowTransforms.push_back(shadowProj *
		glm::lookAt(position, position + glm::vec3(0.0, 1.0, 0.0), glm::vec3(0.0, 0.0, 1.0)));
	cubeShadowTransforms.push_back(shadowProj *
		glm::lookAt(position, position + glm::vec3(0.0, -1.0, 0.0), glm::vec3(0.0, 0.0, -1.0)));
	cubeShadowTransforms.push_back(shadowProj *
		glm::lookAt(position, position + glm::vec3(0.0, 0.0, 1.0), glm::vec3(0.0, -1.0, 0.0)));
	cubeShadowTransforms.push_back(shadowProj *
		glm::lookAt(position, position + glm::vec3(0.0, 0.0, -1.0), glm::vec3(0.0, -1.0, 0.0)));

	return cubeShadowTransforms;
}
