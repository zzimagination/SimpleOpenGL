#include "ModelObject.h"

namespace SemperEngine
{
	namespace Core
	{
		ModelObject::~ModelObject()
		{
		}
		void ModelObject::OnUse()
		{
			if (root.mesh != nullptr)
			{
				root.mesh->Use();
			}
			UseMesh(root);
		}
		void ModelObject::OnDispose()
		{
			if (root.mesh != nullptr)
			{
				root.mesh->Dispose();
			}
			DisposeMesh(root);
		}
		MeshObject* ModelObject::GetMeshObject()
		{
			if (root.mesh != nullptr)
			{
				return root.mesh;
			}

			if (root.children.size() > 0)
			{
				return root.children[0].mesh;
			}
			return nullptr;
		}
		MeshObject* ModelObject::GetMeshObject(std::string name)
		{
			return nullptr;
		}
		void ModelObject::UseMesh(Node& node)
		{
			for (size_t i = 0; i < node.children.size(); i++)
			{
				node.children[i].mesh->Use();
				UseMesh(node.children[i]);
			}
		}
		void ModelObject::DisposeMesh(Node& node)
		{
			for (size_t i = 0; i < node.children.size(); i++)
			{
				node.children[i].mesh->Dispose();
				DisposeMesh(node.children[i]);
			}
		}
	}
}