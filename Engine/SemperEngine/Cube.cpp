#include "Cube.h"
#include "Time.h"
#include "World.h"
#include "RenderCollection.h"
#include "GraphicCommandManager.h"
#include "GameObjectCreator.h"

namespace SemperEngine
{
	using namespace std;
	using namespace Core;

	Cube::Cube()
	{
		_renderObject = unique_ptr<RenderObject>(new RenderObject());
		_material= shared_ptr<Material>(new Material("Unlit"));
	}

	Cube::~Cube()
	{
	}

	void Cube::Start()
	{
		GraphicCommandManager::AddVertexBuffer(&_cubeData);
		_renderObject->modelMatrix = transform.GetModelMatrix();
		_renderObject->material = _material.get();
		_renderObject->renderVertex = &_cubeData;

	}

	void Cube::Update()
	{
		_renderObject->modelMatrix = transform.GetModelMatrix();
		_renderObject->material = _material.get();
		Core::RenderCollection::AddRenderObject(_renderObject->mylife);
	}

	void Cube::End()
	{
		GraphicCommandManager::ClearVertexBuffer(&_cubeData);
	}

	void Cube::SetMaterial(std::shared_ptr<Material> material)
	{
		_material = material;
	}

}