#include "Mesh.h"
#include "ResourceObjectCenter.h"

namespace SemperEngine
{
	using namespace Core;

	Mesh::Mesh()
	{
		object = MeshObject::Create();
		object->Use();
	}

	Mesh::Mesh(Core::MeshObject* obj)
	{
		object = obj;
		object->Use();
	}

	Mesh::~Mesh()
	{
		object->Dispose();
	}

	Mesh* Mesh::Copy()
	{
		auto obj = object->Copy();
		auto copy = new Mesh(obj);
		return copy;
	}
	ArrayList<Float3> Mesh::GetVertices()
	{
		return object->GetVertex();
	}
	void Mesh::SetVertices(ArrayList<Float3> vertices)
	{
		object->SetVertex(vertices);
	}
}