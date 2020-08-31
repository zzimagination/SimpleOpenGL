#include "RendererGenerator.h"
#include "Renderer.h"
#include "RenderObject.h"
#include <vector>

RendererGenerator::RendererGenerator(Renderer *r) :renderer(r)
{
}

RenderObject* RendererGenerator::Generate()
{
	RenderObject *renderObject = new RenderObject();
	renderObject->vertexBuffer = renderer->GetVertices();
	renderObject->uvBuffer = renderer->GetUV();
	renderObject->normalBuffer = renderer->GetNormal();
	return renderObject;
}
