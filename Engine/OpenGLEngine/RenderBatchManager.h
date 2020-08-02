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

	static vector<RenderBatch*> batchs;

private:

	static vector<RenderObject*> _noBatchObjects;

public:

	static void GenerateBatchs(vector<RenderObject*> renderObjects);

	static void ClearBatchs();

	static void DrawBatchs(Camera* camera);

private:

	static void GenerateNewBatchs();
};


#endif // !RENDERBATCH_MANAGER
