#include "Model.h"

namespace SemperEngine
{
	using namespace std;

	Model::Model(Core::ModelObject* object)
	{
		this->object = object;
		this->object->Use();
	}
	Model::~Model()
	{
		this->object->Dispose();
	}
	std::shared_ptr<Mesh> Model::GetMesh()
	{
		auto mesh = object->GetMeshObject();
		if (mesh == nullptr)
		{
			return shared_ptr<Mesh>();
		}
		return shared_ptr<Mesh>(new Mesh(mesh));
	}
}