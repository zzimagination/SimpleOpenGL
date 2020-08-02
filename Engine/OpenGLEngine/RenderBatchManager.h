#ifndef RENDERBATCH_MANAGER
#define RENDERBATCH_MANAGER

#include <vector>

using namespace std;

class RenderBatch;
class RenderObject;
class Camera;

class RenderBatchManager
{
public:

	static vector<RenderBatch> batchs;

public:

	static void GenerateBatchs(vector<RenderObject*> renderObjects);

	static void ClearBatchs();

	static void DrawBatchs(Camera* camera);
};


#endif // !RENDERBATCH_MANAGER
