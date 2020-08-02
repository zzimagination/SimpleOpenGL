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
	DeleteRenderObject();
	delete material;
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

vector<Vector3> Renderer::GetVertices()
{
	vector<Vector3> vertices(cube.vertices, cube.vertices + sizeof(cube.vertices)/sizeof(Vector3));
	return vertices;
}

vector<int> Renderer::GetIndex()
{
	vector<int> index(cube.indices, cube.indices + sizeof(cube.indices) / sizeof(int));
	return index;
}

vector<Vector2> Renderer::GetUV()
{
	vector<Vector2> uv(cube.uvs, cube.uvs + sizeof(cube.uvs) / sizeof(Vector2));
	return uv;
}

vector<Vector3> Renderer::GetNormal()
{
	return vector<Vector3>();
}

RenderObject * Renderer::GetRenderObject()
{
	return _renderObject;
}

void Renderer::GenerateRenderObject()
{
	_renderObject = new RenderObject();
	_renderObject->vertexBuffer = GetVertices();
	_renderObject->uvBuffer = GetUV();
	_renderObject->indexBuffer = GetIndex();
	_renderObject->normalBuffer = GetNormal();
	_renderObject->material = material;
	_renderObject->modelMatrix = GetModelMatrix();
}

void Renderer::UpdateRenderObject()
{
	_renderObject->modelMatrix = GetModelMatrix();
}

void Renderer::DeleteRenderObject()
{
	delete _renderObject;
	_renderObject = nullptr;
}

