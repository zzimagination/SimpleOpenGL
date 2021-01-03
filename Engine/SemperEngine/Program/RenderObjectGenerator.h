#ifndef RENDEROBJECTGENERATOR
#define RENDEROBJECTGENERATOR

class RenderObject;

class RenderObjectGenerator
{
public:

	virtual RenderObject* Generate() {
		return nullptr;
	}
};

#endif // !RENDEROBJECTGENERATOR


