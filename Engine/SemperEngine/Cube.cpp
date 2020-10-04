#include "Cube.h"
#include "VertexDataCenter.h"
#include "RenderCollection.h"
#include "Debug.h"

namespace SemperEngine
{
	using namespace std;
	using namespace Core;

	Cube::Cube()
	{
		
	}

	Cube::~Cube()
	{
		
	}

	void Cube::Start()
	{
		_cube = VertexDataCenter::LoadCube(false);
		_renderObject = unique_ptr<RenderObject>(new RenderObject());
		_material = unique_ptr<Material>(new Material("Unlit"));
		_material->SetVector4(Vector4(0.8f, 0.2f, 0.2f, 1), "_color");
		_renderObject->modelMatrix = transform.GetModelMatrix();
		_renderObject->material = _material.get();
		_renderObject->vertexData = this->_cube;
		Debug::Log("Cube Start");
	}

	void Cube::Update()
	{
		_renderObject->modelMatrix = transform.GetModelMatrix();
		Core::RenderCollection::AddRenderObject(_renderObject->mylife);
	}

	void Cube::End()
	{
		_cube.Dispose();
		Debug::Log("Cube End");
	}
}