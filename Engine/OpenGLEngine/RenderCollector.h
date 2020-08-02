#ifndef RENDERER_COLLECTOR
#define RENDERER_COLLECTOR

#include <vector>

using namespace std;

class Renderer;
class RenderObject;

class RenderCollector
{
public:

	static vector<Renderer*> renderers;

public:

	static void CollectRenderer(Renderer* renderer);

	static void DropRenderer(Renderer* renderer);

	static vector<RenderObject*> GetRenderObjects();

private:

	static bool HasRenderer(Renderer* renderer);
};

#endif // !RENDERER_COLLECTOR

