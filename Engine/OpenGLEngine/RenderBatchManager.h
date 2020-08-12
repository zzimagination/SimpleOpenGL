#ifndef RENDERBATCH_MANAGER
#define RENDERBATCH_MANAGER

#include <vector>

using namespace std;

class RenderObject;
class Texture;
class RenderVertex;
class RenderBatch;
class Camera;
class TextureData;
class VertexData;

class RenderBatchManager
{
public:

	static vector<RenderBatch> *frontBatchs;

	static vector<RenderBatch> *backBatchs;

public:

	static void GenerateBatchs(vector<RenderObject*> renderObjects, Camera *camera);

	static void SwapBuffer();

	static void ClearBatchs();

};


#endif // !RENDERBATCH_MANAGER
