#include "MeshObject.h"
#include "GraphicResource.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		MeshObject* MeshObject::Create()
		{
			auto object = new MeshObject;
			object->data = unique_ptr<VertexData>(new VertexData);
			return object;
		}
		MeshObject* MeshObject::CreateCube()
		{
			auto object = new MeshObject;
			object->data = unique_ptr<VertexData>(VertexData::CreateCube());
			return object;
		}
		MeshObject* MeshObject::CreateRectangle()
		{
			auto object = new MeshObject;
			object->data = unique_ptr<VertexData>(VertexData::CreateRectangle());
			return object;
		}

		MeshObject::MeshObject()
		{
		}

		MeshObject::~MeshObject()
		{
		}

		void MeshObject::EndDelete()
		{
			if (graphicBind)
			{
				graphicBind = false;
				GraphicResource::RemoveVertexData(graphicDataInfo);
			}
		}

		void MeshObject::EndModify()
		{
			if (graphicBind)
			{
				graphicBind = false;
				GraphicResource::RemoveVertexData(graphicDataInfo);
			}
		}

		MeshObject* MeshObject::Copy()
		{
			return nullptr;
		}

		void MeshObject::SetVertex(ArrayList<Float3> vertices)
		{
			data->vertices = vertices;
			Modify();
		}

		ArrayList<Float3> MeshObject::GetVertex()
		{
			return data->vertices;
		}
	}
}