#include "Cube.h"
#include "Resource.h"
#include "RenderCollection.h"
#include "Debug.h"

namespace SemperEngine
{
	using namespace std;
	using namespace Core;

	Cube::Cube()
	{
		_cube = Resource::CreateCube();
		material = shared_ptr<Material>(new Material("Unlit"));
		material->AddProperty("_color", Float4(1, 1, 1, 1));
		_renderObject = unique_ptr<RenderObject>(new RenderObject());
	}

	Cube::~Cube()
	{
	}

	void Cube::Start()
	{
		_renderObject->modelMatrix = transform.GetModelMatrix();
		_renderObject->material = material;
		_renderObject->vertexData = this->_cube;
	}

	void Cube::Update()
	{
		_renderObject->modelMatrix = transform.GetModelMatrix();
		Core::RenderCollection::AddRenderObject(_renderObject->mylife);
	}

	RenderLayer Cube::GetRenderLayer()
	{
		return _renderObject->layer;
	}

	void Cube::AddRenderLayer(int layer)
	{
		_renderObject->layer.Add(layer);
	}

}