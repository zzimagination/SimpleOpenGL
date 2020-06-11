#include "RenderObjectManager.h"
#include "ShaderManager.h"
#include "../Camera/Camera.h"
#include "../Object/BuildInMesh.h"
#include "../World/WorldManager.h"


using namespace std;

vector<RenderObject*> RenderObjectManager::renderObjects;

vector<RenderObjectManager::RendererPair> RenderObjectManager::rendererPairs;

void RenderObjectManager::AddRenderer(Renderer* renderer)
{
	if (renderer == nullptr)
	{
		throw "renderer is not renderer";
	}

	if (ContainRenderer(renderer) >= 0)
	{
		throw "renderer is exist";
	}

	RenderObject* object = new RenderObject();
	auto t = sizeof(renderer->cube.vertices);
	object->vertices.assign(renderer->cube.vertices, renderer->cube.vertices + sizeof(renderer->cube.vertices) / sizeof(renderer->cube.vertices[0]));
	object->indices.assign(renderer->cube.indices, renderer->cube.indices + sizeof(renderer->cube.indices) / sizeof(renderer->cube.indices[0]));
	object->uvs.assign(renderer->cube.uvs, renderer->cube.uvs + sizeof(renderer->cube.uvs) / sizeof(renderer->cube.uvs[0]));

	object->shader = renderer->shader;
	object->modelMatrix = renderer->modelMatrix;
	object->viewMatrix = WorldManager::active->camera->worldToViewMatrix;
	object->projectionMatrix = WorldManager::active->camera->projectionMatrix;

	object->AddVec3Value("_color", vec3(1.0f));
	object->textures.assign(renderer->textures.begin(), renderer->textures.end());

	renderObjects.push_back(object);

	RendererPair pair;
	pair.object = object;
	pair.renderers.push_back(renderer);
	rendererPairs.push_back(pair);
}

void RenderObjectManager::UpdateRenderer(Renderer * renderer)
{
	if (renderer == nullptr)
	{
		throw "renderer is not renderer";
	}

	int idx = ContainRenderer(renderer);
	if (idx < 0)
	{
		throw "renderer is not exist";
	}

	RenderObject* object = rendererPairs[idx].object;

	object->vertices.clear();
	vec3* start = renderer->cube.vertices;
	vec3* end = start + sizeof(renderer->cube.vertices) / sizeof(vec3);
	object->vertices.assign(start, end);

	object->indices.clear();
	int* startIndex = renderer->cube.indices;
	int* endIndex = startIndex + sizeof(renderer->cube.indices) / sizeof(int);
	object->indices.assign(startIndex, endIndex);

	object->uvs.clear();
	vec2* startUV = renderer->cube.uvs;
	vec2* endUV = startUV + sizeof(renderer->cube.uvs) / sizeof(vec2);
	object->uvs.assign(startUV, endUV);

	object->shader = renderer->shader;

	object->modelMatrix = renderer->modelMatrix;
	object->viewMatrix = WorldManager::active->camera->worldToViewMatrix;
	object->projectionMatrix = WorldManager::active->camera->projectionMatrix;

	
	object->vec3Map.clear();
	for (auto i = renderer->vec3Map.begin() ; i != renderer->vec3Map.end(); i++)
	{
		object->AddVec3Value((*i).first, (*i).second);
	}

	object->textures.clear();
	object->textures.assign(renderer->textures.begin(), renderer->textures.end());
}

void RenderObjectManager::RemoveRenderer(Renderer * renderer)
{
	if (renderer == nullptr)
	{
		return;
	}

	if (!ContainRenderer(renderer))
	{
		return;
	}

	for (auto i = rendererPairs.begin(); i != rendererPairs.end(); i++)
	{
		if ((*i).Contain(renderer))
		{
			DeleteRenderObject((*i).object);
			rendererPairs.erase(i);
		}
	}

}

//void RenderObjectManager::GenerateRenderObjects()
//{
//	World* activeWorld = WorldManager::active;
//
//	vector<GameObject*> gameObjects = activeWorld->gameObjects;
//
//	if (renderObjects.size() < 1)
//	{
//
//
//		RenderObject *robj = new RenderObject();
//		Cube cube1;
//		robj->vertices.assign(cube1.vertices, cube1.vertices + sizeof(cube1.vertices) / sizeof(cube1.vertices[0]));
//
//		//robj->vertices = {
//		//	vec3(-1, 1, 1),vec3(-1,-1, 1),vec3( 1,-1, 1),vec3( 1, 1, 1),//front
//		//	vec3( 1, 1,-1),vec3( 1,-1,-1),vec3(-1,-1,-1),vec3(-1, 1,-1),//back
//		//	vec3(-1, 1,-1),vec3(-1,-1,-1),vec3(-1,-1, 1),vec3(-1, 1, 1),//left
//		//	vec3( 1, 1, 1),vec3( 1,-1, 1),vec3( 1,-1,-1),vec3( 1, 1,-1),//right
//		//	vec3(-1, 1,-1),vec3(-1, 1, 1),vec3( 1, 1, 1),vec3( 1, 1,-1),//top
//		//	vec3( 1,-1, 1),vec3( 1,-1,-1),vec3(-1,-1,-1),vec3(-1,-1, 1)//bottom
//		//};
//
//		robj->uvs.assign(cube1.uvs, cube1.uvs + sizeof(cube1.uvs) / sizeof(cube1.uvs[0]));
//		//robj->uvs = {
//		//	vec2(0,0),vec2(0,1),vec2(1,1),vec2(1,0),//front
//		//	vec2(0,0),vec2(0,1),vec2(1,1),vec2(1,0),//back
//		//	vec2(0,0),vec2(0,1),vec2(1,1),vec2(1,0),//left
//		//	vec2(0,0),vec2(0,1),vec2(1,1),vec2(1,0),//right
//		//	vec2(0,0),vec2(0,1),vec2(1,1),vec2(1,0),//top
//		//	vec2(0,0),vec2(0,1),vec2(1,1),vec2(1,0)//bottom
//		//};
//
//		robj->indices.assign(cube1.indices, cube1.indices + sizeof(cube1.indices) / sizeof(cube1.indices[0]));
//		//robj->indices = {
//		//		0,1,2,3,2,0,
//		//		4,5,6,7,6,4,
//		//		8,9,10,11,10,8,
//		//		12,13,14,15,14,12,
//		//		16,17,18,19,18,16,
//		//		20,21,22,23,22,20
//		//};
//
//		Texture* tex = new Texture();
//		tex->path = "Resources/Textures/test.png";
//		tex->textureType = BASE_TEXTURE;
//		tex->LoadTexture();
//
//		robj->textures.push_back(tex);
//		robj->shader = ShaderManager::GetShader("UnlitTexture");
//		robj->func_shader = [](Shader* ss) {
//			Camera* camera = WorldManager::active->camera;
//			ss->setVec3("_color", glm::vec3(1.0f, 1.0f, 1.0f));
//			ss->setMat4("_projection", camera->projectionMatrix);
//			ss->setMat4("_view", camera->worldToViewMatrix);
//			mat4 model = mat4(1);
//			model = rotate(model, radians(30.0f), vec3(0, 1, 0));
//			ss->setMat4("_model", model);
//		};
//
//		renderObjects.push_back(robj);
//	}
//}
//
//void RenderObjectManager::ClearRenderObjects()
//{
//	for (std::vector<RenderObject*>::iterator it = renderObjects.begin();
//		it != renderObjects.end(); it++)
//	{
//		RenderObject* ptr = *it;
//		if (ptr->isDeleted)
//		{
//			ptr->ClearGeometry();
//			renderObjects.erase(it);
//			delete ptr;
//		}
//	}
//}


int RenderObjectManager::ContainRenderer(Renderer* renderer)
{
	for (int i = 0; i < rendererPairs.size(); i++)
	{
		if (rendererPairs[i].Contain(renderer))
		{
			return i;
		}
	}
	return -1;
}

void RenderObjectManager::DeleteRenderObject(RenderObject * object)
{
	for (auto i = renderObjects.begin(); i != renderObjects.end(); i++)
	{
		if (*i == object)
		{
			renderObjects.erase(i);
			delete object;
		}
	}
}

