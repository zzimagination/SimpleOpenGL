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
		material = shared_ptr<Material>(new Material("Unlit"));
		material->AddProperty("_color", Float4(1, 1, 1, 1));
		mesh = Resource::CreateCube();
		_renderObject = unique_ptr<RenderCustomObject>(new RenderCustomObject());
	}

	Cube::~Cube()
	{
	}

	void Cube::Start()
	{
		_renderObject->modelMat = transform.GetModelMatrix();
		_renderObject->material = material;
		_renderObject->mesh = mesh;
	}

	void Cube::Update()
	{
		_renderObject->modelMat = transform.GetModelMatrix();
		Core::RenderCollection::AddCustomObject(_renderObject.get());
	}

	RenderLayer Cube::GetRenderLayer()
	{
		return _renderObject->layer;
	}

	void Cube::AddRenderLayer(int layer)
	{
		_renderObject->layer.Add(layer);
	}

	std::shared_ptr<Mesh> Cube::GetMesh()
	{
		return _renderObject->mesh;
	}

}