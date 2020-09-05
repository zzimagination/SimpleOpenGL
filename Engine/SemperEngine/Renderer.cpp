#include "Renderer.h"
#include "RenderCollector.h"
#include "RendererGenerator.h"
#include "RenderObject.h"
#include "GameObject.h"
#include "Transform.h"

namespace SemperEngine {

	Renderer::Renderer()
	{
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::Start()
	{
		Collect();
		GenerateRenderObject();
	}

	void Renderer::Update()
	{
		UpdateRenderObject();
	}

	void Renderer::End()
	{
		Drop();
		DeleteRenderObject();
	}

	void Renderer::Collect()
	{
		RenderCollector::CollectRenderer(this);
	}

	void Renderer::Drop()
	{
		RenderCollector::DropRenderer(this);
	}

	Material * Renderer::GetMaterial()
	{
		return _material;
	}

	void Renderer::SetMaterial(Material * material)
	{
		this->_material = material;
	}

	RenderObject * Renderer::GetRenderObject()
	{
		return _renderObject;
	}

	void Renderer::GenerateRenderObject()
	{
		_renderObject = new RenderObject();
		UpdateRenderObject();
	}

	void Renderer::UpdateRenderObject()
	{
		_renderObject->renderVertex = &cube;
		_renderObject->modelMatrix = gameObject->GetTransform()->GetModelMatrix();
		_renderObject->shader = _material->shader;
		_renderObject->floatProperty = _material->floatProperty;
		_renderObject->vector2Property = _material->vector2Property;
		_renderObject->vector3Property = _material->vector3Property;
		_renderObject->vector4Property = _material->vector4Property;
		_renderObject->matrixProperty = _material->matrixProperty;
		_renderObject->textures = _material->textures;
	}

	void Renderer::DeleteRenderObject()
	{
		delete _renderObject;
		_renderObject = nullptr;
	}

}