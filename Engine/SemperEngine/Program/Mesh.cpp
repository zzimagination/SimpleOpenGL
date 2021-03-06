#include "Mesh.h"
#include "ResourceObjectCenter.h"

namespace Semper
{
	using namespace Core;

	Mesh::Mesh()
	{
		_object = MeshObject::Create();
		_object->Use();
	}

	Mesh::Mesh(Core::MeshObject* obj)
	{
		_object = obj;
		_object->Use();
	}

	Mesh::~Mesh()
	{
		_object->Dispose();
	}

	Mesh* Mesh::Copy()
	{
		auto obj = _object->Copy();
		auto copy = new Mesh(obj);
		return copy;
	}
	ArrayList<Float3> Mesh::GetVertices()
	{
		return _object->vertices;
	}
	void Mesh::SetVertices(ArrayList<Float3> vertices)
	{
		_object->vertices = vertices;
		_object->Modify();
	}
	ResourceObject* Mesh::GetObject()
	{
		return _object;
	}
}