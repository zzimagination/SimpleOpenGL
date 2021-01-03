#ifndef IRENDER_GENERATOR
#define IRENDER_GENERATOR

class RenderObjectGenerator;

class IRenderGenerator {
public:
	
	virtual RenderObjectGenerator GetGenerator() = 0;
};
#endif // !IRENDER_GENERATOR
