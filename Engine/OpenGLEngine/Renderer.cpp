#include "Renderer.h"
#include "RenderObjectManager.h"
#include "GameObject.h"

Renderer * Renderer::GetType()
{
	return this;
}

void Renderer::Start()
{
	SetModelMatrix(gameObject->transform.GetModelMatrix());
	RenderObjectManager::AddRenderer(this);
}

void Renderer::Update()
{
	SetModelMatrix(gameObject->transform.GetModelMatrix());
	RenderObjectManager::UpdateRenderer(this);
}

void Renderer::SetModelMatrix(mat4 model)
{
	modelMatrix = model;
}

void Renderer::AddTexture(Texture * tex)
{
	textures.push_back(tex);
}

void Renderer::RemoveTexture(Texture * tex)
{
	for (auto i = textures.begin(); i != textures.end(); i++)
	{
		if (*i == tex)
		{
			textures.erase(i);
		}
	}
}
