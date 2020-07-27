#ifndef RENDERBATCH_MANAGER
#define RENDERBATCH_MANAGER

#include "RenderBatch.h"
#include "RenderObject.h"
#include <vector>

class RenderBatchManager
{
public:

	static std::vector<RenderBatch> batchList;

	static vector<RenderBatch*> batchs;

public:

	static void GenerateBatchs();

	static void GenerateBatchs(vector<RenderObject*> renderObjects);

	static void DrawBatchs();
};


#endif // !RENDERBATCH_MANAGER
