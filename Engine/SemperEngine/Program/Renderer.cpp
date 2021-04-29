#include "Renderer.h"
#include "RenderCollection.h"
#include "GameObject.h"
#include "Debug.h"

namespace Semper
{
	using namespace std;
	using namespace Core;

	Renderer::Renderer()
	{
		_object = unique_ptr<RenderCustomObject>(new RenderCustomObject);
		_object->mesh = shared_ptr<Mesh>(new Mesh());
	}
	Renderer::~Renderer()
	{
	}
	void Renderer::Start()
	{
	}
	void Renderer::Update()
	{
		_object->modelMat = gameObject->transform.GetModelMatrix();
		RenderCollection::AddCustomObject(_object.get());
	}
	void Renderer::SetMesh(std::shared_ptr<Mesh> mesh)
	{
		_object->mesh = mesh;
	}
	std::shared_ptr<Mesh> Renderer::GetMesh()
	{
		return _object->mesh;
	}
	void Renderer::SetMaterial(std::shared_ptr<Material> material)
	{
		_object->material = material;
	}
	std::shared_ptr<Material> Renderer::GetMaterial()
	{
		return _object->material;
	}
	void Renderer::AddRenderLayer(int layer)
	{
		_object->layer.Add(layer);
	}
	RenderLayer Renderer::GetRenderLayer()
	{
		return _object->layer;
	}
}