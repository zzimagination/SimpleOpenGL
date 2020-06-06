#include "Renderer.h"
#include "../Render/RenderObjectManager.h"

Renderer * Renderer::GetType()
{
	return this;
}

void Renderer::Start()
{
	RenderObjectManager::AddRenderer(this);
}

void Renderer::Update()
{
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
