#include "RenderObject.h"

RenderObject::RenderObject()
{
}

RenderObject::~RenderObject()
{
}

bool RenderObject::HasBatch()
{
	return batch != nullptr;
}

bool RenderObject::IsBreakBatch()
{
	if (_breakBatch)
	{
		
		return true;
	}
	else
	{
		return false;
	}
}

Vector3 * RenderObject::GetVertices()
{
	return vertexBuffer;
}

int RenderObject::GetVertexCount()
{
	return vertexCount;
}

void RenderObject::SetVertices(Vector3 * buffer, int count)
{
	_breakBatch = true;
	vertexCount = count;
	vertexBuffer = buffer;
}

int * RenderObject::GetIndex()
{
	return indexBuffer;
}

void RenderObject::SetIndex(int * buffer)
{
	_breakBatch = true;
	indexBuffer = buffer;
}

Vector2 * RenderObject::GetUV()
{
	return uvBuffer;
}

void RenderObject::SetUV(Vector2 * buffer)
{
	_breakBatch = true;
	uvBuffer = buffer;
}

Material * RenderObject::GetMaterial()
{
	return material;
}

void RenderObject::SetMaterial(Material * mat)
{
	_breakBatch = true;
	material = mat;
}

Matrix4x4* RenderObject::GetModelMatrix()
{
	return &modelMatrix;
}

void RenderObject::SetModelMatrix(Matrix4x4 matrix)
{
	modelMatrix = matrix;
}

void RenderObject::SetRenderBatch(RenderBatch * renderBatch)
{
	_breakBatch = false;
	this->batch = renderBatch;
}
