#ifndef RENDEROBJECT_MANAGER
#define RENDEROBJECT_MANAGER
#include <vector>
#include "RenderObject.h"
#include "Renderer.h"
#include "Camera.h"
namespace SemperEngine {
	using namespace std;

	class RenderObjectManager
	{
	private:

		static vector<RenderObject*> renderObjects;

	public:

		static void Culling(Camera *camera, vector<RenderObject*> &objects);

		static void AddRenderObject(RenderObject* object);

		static void AddRenderObject(vector<RenderObject*> objects);

		static vector<RenderObject*> GetRenderObject();

		static void ClearRenderObject();
	};

}
#endif // !RENDEROBJECT_MANAGER

