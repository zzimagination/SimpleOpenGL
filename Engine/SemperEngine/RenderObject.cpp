#include "RenderObject.h"
namespace SemperEngine {
	RenderObject::RenderObject()
	{
	}

	RenderObject::~RenderObject()
	{
	}

	bool RenderObject::HasBatch()
	{
		return batch != nullptr;
	}

	bool RenderObject::IsBreakBatch()
	{
		if (_breakBatch)
		{

			return true;
		}
		else
		{
			return false;
		}
	}

	void RenderObject::BreakBatch()
	{
		_breakBatch = true;
	}


	void RenderObject::SetRenderBatch(RenderBatch * renderBatch)
	{
		_breakBatch = false;
		this->batch = renderBatch;
	}
}