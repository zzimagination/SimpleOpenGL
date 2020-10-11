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
		_cube = VertexDataCenter::LoadCube(false);
		_cube.Use(this);
		material = shared_ptr<Material>(new Material("Unlit"));
		material->AddShaderProperty("_color", Vector4(1, 1, 1, 1));
	}

	Cube::~Cube()
	{
		
	}

	void Cube::Start()
	{
		_renderObject = unique_ptr<RenderObject>(new RenderObject());
		_renderObject->modelMatrix = transform.GetModelMatrix();
		_renderObject->material = material;
		_renderObject->vertexData = this->_cube;
	}

	void Cube::Update()
	{
		_renderObject->modelMatrix = transform.GetModelMatrix();
		Core::RenderCollection::AddRenderObject(_renderObject->mylife);
	}

	void Cube::End()
	{
		_cube.Dispose();
	}
}