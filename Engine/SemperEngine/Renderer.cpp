#include "Renderer.h"
#include "RenderCollection.h"
#include "RendererGenerator.h"
#include "RenderObject.h"
#include "GameObject.h"
#include "Transform.h"

namespace SemperEngine {

	using namespace std;

	Renderer::Renderer() :Component()
	{
	}

	Renderer::~Renderer()
	{
	}

	std::vector<RenderObject*> Renderer::GetRenderObjects()
	{
		return _renderObjects;
	}

	void Renderer::AddToCollection()
	{
	}

	void Renderer::RemoveFromCollection()
	{
	}
}