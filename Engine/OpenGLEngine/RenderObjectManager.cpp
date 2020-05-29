#include "RenderObjectManager.h"
#include "ShaderManager.h"
#include "Camera.h"

std::vector<RenderObject*> RenderObjectManager::renderObjects;

void RenderObjectManager::GenerateRenderObjects()
{
	if (renderObjects.size() < 1)
	{
		RenderObject *robj = new RenderObject();

		robj->vertices = {
			vec3(-4, 4, 0),vec3(-4, -4, 0),vec3(4,-4,0),vec3(4,4,0)
		};
		robj->uvs = {
			vec2(0,0),vec2(0,1),vec2(1,1),vec2(1,0)
		};

		robj->indices = {
				0,1,2,
				3,2,0
		};

		Texture* tex = new Texture();
		tex->path = "Resources/Textures/test.png";
		tex->textureType = BASE_TEXTURE;
		tex->LoadTexture();

		robj->textures.push_back(tex);
		robj->shader = ShaderManager::GetShader("UnlitTexture");
		robj->func_shader = [](Shader* ss) {
			ss->setVec3("_color", glm::vec3(1.0f, 1.0f, 1.0f));
			ss->setMat4("_projection", Camera::mainCamera->projectionMatrix);
			ss->setMat4("_view", Camera::mainCamera->worldToViewMatrix);
			ss->setMat4("_model", glm::mat4(1.0f));
		};

		renderObjects.push_back(robj);
	}
}

void RenderObjectManager::ClearRenderObjects()
{
	for (std::vector<RenderObject*>::iterator it = renderObjects.begin();
		it != renderObjects.end(); it++)
	{
		RenderObject* ptr = *it;
		if (ptr->isDeleted)
		{
			ptr->ClearGeometry();
			renderObjects.erase(it);
			delete ptr;
		}
	}
}
