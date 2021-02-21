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
		_renderObject = unique_ptr<RenderCustomObject>(new RenderCustomObject());
		_renderObject->material = shared_ptr<Material>(new Material());
		_renderObject->material->AddProperty("_color", Float4(1, 1, 1, 1));
		_renderObject->mesh = Resource::CreateCube();
	}

	Cube::~Cube()
	{
	}

	void Cube::Start()
	{
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

	std::shared_ptr<Material> Cube::GetMaterial()
	{
		return _renderObject->material;
	}

	void Cube::SetMaterial(std::shared_ptr<Material> mat)
	{
		_renderObject->material = mat;
	}

}