#ifndef RENDERBATCH_MANAGER
#define RENDERBATCH_MANAGER

#include <vector>
namespace SemperEngine {
	using namespace std;

	class RenderObject;
	class Texture;
	class RenderVertexData;
	class RenderBatch;
	class Camera;
	class GraphicTextureData;
	class GraphicVertexData;

	class RenderBatchManager
	{
	public:

		static vector<RenderBatch> *frontBatchs;

		static vector<RenderBatch> *backBatchs;

	public:

		static void GenerateBatchs(vector<RenderObject*> renderObjects, Camera *camera);

		static void SwapBatches();

		static void ClearBatchs();

	};
}

#endif // !RENDERBATCH_MANAGER
