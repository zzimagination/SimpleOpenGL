#ifndef RENDERERGENERATOR
#define RENDERERGENERATOR
#include "RenderObjectGenerator.h"

class Renderer;

class RendererGenerator : public RenderObjectGenerator
{
public:

	Renderer* renderer;

public:

	RendererGenerator(Renderer* r);

public:

	virtual RenderObject* Generate() override;
};

#endif // !RENDERERGENERATOR
