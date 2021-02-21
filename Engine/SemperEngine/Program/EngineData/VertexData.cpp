#include "VertexData.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		VertexData* VertexData::CreateCube()
		{
			auto cube = new VertexData();
			cube->vertices.Resize(CubeData::vertices.size());
			cube->vertices.Copy(CubeData::vertices.data());
			cube->uv.Resize(CubeData::uv.size());
			cube->uv.Copy(CubeData::uv.data());
			cube->index.Resize(CubeData::indices.size());
			cube->index.Copy(CubeData::indices.data());
			return cube;
		}

		VertexData* VertexData::CreateRectangle()
		{
			auto vert = new VertexData();
			vert->vertices.Resize(ScreenVertexData::vertices.size());
			vert->vertices.Copy(ScreenVertexData::vertices.data());
			vert->uv.Resize(ScreenVertexData::uv.size());
			vert->uv.Copy(ScreenVertexData::uv.data());
			vert->index.Resize(ScreenVertexData::indices.size());
			vert->index.Copy(ScreenVertexData::indices.data());
			return vert;
		}

		VertexData::VertexData()
		{
		}

		VertexData::~VertexData()
		{
		}

		VertexData* VertexData::Copy()
		{
			auto data = new VertexData();
			data->vertices.Resize(vertices.Size());
			data->vertices.Copy(vertices.DataPtr());
			data->uv.Resize(uv.Size());
			data->uv.Copy(uv.DataPtr());
			data->index.Resize(index.Size());
			data->index.Copy(index.DataPtr());
			return data;
		}


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

		array<Float2, 4> ScreenVertexData::uv = { Float2(0,1), Float2(1,1),Float2(1,0), Float2(0,0) };

		array<int, 6> ScreenVertexData::indices = { 0,1,3,1,2,3 };
#pragma endregion

	}
}