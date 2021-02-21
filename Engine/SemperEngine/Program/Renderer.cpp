#include "Renderer.h"
#include "RenderCollection.h"
#include "GameObject.h"

namespace SemperEngine
{
	using namespace std;
	using namespace Core;

	Renderer::Renderer()
	{
		_object = unique_ptr<RenderCustomObject>(new RenderCustomObject);
		_object->mesh = shared_ptr<Mesh>(new Mesh());
		_object->material = shared_ptr<Material>(new Material());
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
	void Renderer::AddRenderLayer(int layer)
	{
		_object->layer.Add(layer);
	}
	RenderLayer Renderer::GetRenderLayer()
	{
		return _object->layer;
	}
}