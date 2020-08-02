#include "Renderer.h"
#include "RenderCollector.h"
#include "GameObject.h"
#include "RendererGenerator.h"
#include "RenderObject.h"

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
	Drop();
	DeleteRenderObject();
}

void Renderer::Start()
{
	GenerateRenderObject();
	Collect();
}

void Renderer::Update()
{
	UpdateRenderObject();
}

void Renderer::Collect()
{
	RenderCollector::CollectRenderer(this);
}

void Renderer::Drop()
{
	RenderCollector::DropRenderer(this);
}

Matrix4x4 Renderer::GetModelMatrix()
{
	return gameObject->transform.GetModelMatrix();
}

Vector3* Renderer::GetVertices()
{
	return cube.vertices;
}

int Renderer::GetVertexCount()
{
	return sizeof(cube.vertices) / sizeof(Vector3);
}

int* Renderer::GetIndex()
{
	return cube.indices;
}

Vector2* Renderer::GetUV()
{
	return cube.uvs;
}

RenderObject * Renderer::GetRenderObject()
{
	return _renderObject;
}

void Renderer::GenerateRenderObject()
{
	_renderObject = new RenderObject();
	_renderObject->SetVertices(GetVertices(), GetVertexCount());
	_renderObject->SetUV(GetUV());
	_renderObject->SetIndex(GetIndex());
	_renderObject->SetMaterial(material);
	_renderObject->SetModelMatrix(GetModelMatrix());
}

void Renderer::UpdateRenderObject()
{
	_renderObject->SetModelMatrix(GetModelMatrix());
}

void Renderer::DeleteRenderObject()
{
	delete _renderObject;
	_renderObject = nullptr;
}

