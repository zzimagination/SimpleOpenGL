#include "MeshObject.h"
#include "ResourceDataCenter.h"
#include "GraphicDataCenter.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		MeshObject* MeshObject::Create()
		{
			auto object = new MeshObject;
			object->resourcePackage = ResourceDataCenter::CreateVertexData();
			return object;
		}
		MeshObject* MeshObject::CreateCube()
		{
			auto object = new MeshObject;
			object->resourcePackage = ResourceDataCenter::CreateCube();
			return object;
		}
		MeshObject::MeshObject()
		{
		}

		MeshObject::~MeshObject()
		{
		}

		void MeshObject::EndCreate()
		{
			graphicDataInfo = GraphicDataCenter::AddVertexData(resourcePackage.GetResource());
		}

		void MeshObject::EndDelete()
		{
			resourcePackage.Dispose();
			GraphicDataCenter::RemoveVertexData(graphicDataInfo);
		}

		void MeshObject::EndModify()
		{
			GraphicDataCenter::RemoveVertexData(graphicDataInfo);
			graphicDataInfo = GraphicDataCenter::AddVertexData(resourcePackage.GetResource());
		}

		MeshObject* MeshObject::Copy()
		{
			auto package = ResourceDataCenter::CopyVertexData(resourcePackage);
			auto obj = new MeshObject;
			obj->resourcePackage = package;
			return obj;
		}

		void MeshObject::SetVertex(ArrayList<Float3> vertices)
		{
			resourcePackage.GetResource()->vertices = vertices;
			Modify();
		}

		ArrayList<Float3> MeshObject::GetVertex()
		{
			return resourcePackage.GetResource()->vertices;
		}
	}
}