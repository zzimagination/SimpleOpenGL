#pragma once
#include "RenderBatch.h"
#include <vector>
class BatchManager
{
public:
	static std::vector<RenderBatch> batchList;

	static void GenerateBatchs();

	static void DrawBatchs();

	static void ClearBatchs();
};

