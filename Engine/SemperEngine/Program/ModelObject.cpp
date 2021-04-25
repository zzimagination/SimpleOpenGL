#include "ModelObject.h"

namespace Semper
{
	namespace Core
	{
		ModelObject::~ModelObject()
		{
		}
		void ModelObject::OnUse()
		{
			UseMesh(root);
		}
		void ModelObject::OnDispose()
		{
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
			if (node.mesh != nullptr)
			{
				node.mesh->Use();
			}
			for (size_t i = 0; i < node.children.size(); i++)
			{
				UseMesh(node.children[i]);
			}
		}
		void ModelObject::DisposeMesh(Node& node)
		{
			if (node.mesh != nullptr)
			{
				node.mesh->Dispose();
			}
			for (size_t i = 0; i < node.children.size(); i++)
			{
				DisposeMesh(node.children[i]);
			}
		}
	}
}