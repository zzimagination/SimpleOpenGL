#include "MeshObject.h"
#include "GraphicResource.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

#pragma region Cube
		array<Float3, 24> CubeData::vertices = {
		Float3(-0.5f, 0.5f, 0.5f),Float3(-0.5f,-0.5f, 0.5f),Float3(0.5,-0.5f, 0.5f),Float3(0.5f, 0.5f, 0.5f),//front
		Float3(0.5f, 0.5f,-0.5f),Float3(0.5f,-0.5f,-0.5f),Float3(-0.5f,-0.5f,-0.5f),Float3(-0.5f, 0.5f,-0.5f),//back
		Float3(-0.5f, 0.5f,-0.5f),Float3(-0.5f,-0.5f,-0.5f),Float3(-0.5f,-0.5f, 0.5f),Float3(-0.5f, 0.5f, 0.5f),//left
		Float3(0.5f, 0.5f, 0.5f),Float3(0.5f,-0.5f, 0.5f),Float3(0.5f,-0.5f,-0.5f),Float3(0.5f, 0.5f,-0.5f),//right
		Float3(-0.5f, 0.5f,-0.5f),Float3(-0.5f, 0.5f, 0.5f),Float3(0.5f, 0.5f, 0.5f),Float3(0.5f, 0.5f,-0.5f),//top
		Float3(0.5f,-0.5f, 0.5f),Float3(0.5f,-0.5f,-0.5f),Float3(-0.5f,-0.5f,-0.5f),Float3(-0.5f,-0.5f, 0.5f)//bottom
		};

		array<Float2, 24> CubeData::uv = {
			   Float2(0,0),Float2(0,1),Float2(1,1),Float2(1,0),//front
			   Float2(0,0),Float2(0,1),Float2(1,1),Float2(1,0),//back
			   Float2(0,0),Float2(0,1),Float2(1,1),Float2(1,0),//left
			   Float2(0,0),Float2(0,1),Float2(1,1),Float2(1,0),//right
			   Float2(0,0),Float2(0,1),Float2(1,1),Float2(1,0),//top
			   Float2(0,0),Float2(0,1),Float2(1,1),Float2(1,0)//bottom
		};

		array<int, 36> CubeData::indices = {
			0, 1, 2, 2, 3, 0,
			4, 5, 6, 6, 7, 4,
			8, 9,10,10,11, 8,
		   12,13,14,14,15,12,
		   16,17,18,18,19,16,
		   22,21,20,20,23,22
		};
#pragma endregion

#pragma region ScreenVertex

		array<Float3, 4> ScreenVertexData::vertices = { Float3(-1,-1,0), Float3(1,-1,0), Float3(1,1,0), Float3(-1,1,0) };

		array<Float2, 4> ScreenVertexData::uv = { Float2(0,0), Float2(1,0),Float2(1,1), Float2(0,1) };

		array<int, 6> ScreenVertexData::indices = { 0,1,3,1,2,3 };
#pragma endregion

		MeshObject* MeshObject::Create()
		{
			auto object = new MeshObject;
			return object;
		}
		MeshObject* MeshObject::CreateCube()
		{
			auto object = new MeshObject;
			object->vertices.Resize(CubeData::vertices.size());
			object->vertices.Copy(CubeData::vertices.data());
			object->uv.Resize(CubeData::uv.size());
			object->uv.Copy(CubeData::uv.data());
			object->index.Resize(CubeData::indices.size());
			object->index.Copy(CubeData::indices.data());
			return object;
		}
		MeshObject* MeshObject::CreateRectangle()
		{
			auto object = new MeshObject;
			object->vertices.Resize(ScreenVertexData::vertices.size());
			object->vertices.Copy(ScreenVertexData::vertices.data());
			object->uv.Resize(ScreenVertexData::uv.size());
			object->uv.Copy(ScreenVertexData::uv.data());
			object->index.Resize(ScreenVertexData::indices.size());
			object->index.Copy(ScreenVertexData::indices.data());
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
			DeleteGraphicResource();
		}

		void MeshObject::EndModify()
		{
			DeleteGraphicResource();
		}

		void MeshObject::CreateGraphicResource()
		{
			if (graphicBind)
			{
				return;
			}
			graphicBind = true;

			GraphicVertexResource resource;
			resource.vertices = &vertices;
			resource.uv = &uv;
			resource.index = &index;
			graphicDataInfo = GraphicResource::AddVertexData(resource);
		}

		void MeshObject::DeleteGraphicResource()
		{
			if (!graphicBind)
			{
				return;
			}
			graphicBind = false;

			GraphicResource::RemoveVertexData(graphicDataInfo);
			graphicDataInfo = GraphicDataInfo();
		}

		MeshObject* MeshObject::Copy()
		{
			return nullptr;
		}
	}
}