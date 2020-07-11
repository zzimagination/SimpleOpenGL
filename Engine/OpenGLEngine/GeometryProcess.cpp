#include<glad/glad.h>
#include "GeometryProcess.h"
#include "RenderBatch.h"
#include "ShaderManager.h"
#include "ShaderProgram.h"
#include "BatchManager.h"
#include "RenderObjectManager.h"

void GeometryProcess::BindVertexArray()
{
	for (size_t i = 0; i < RenderObjectManager::renderObjects.size(); i++)
	{
		RenderObjectManager::renderObjects[i]->SetupGeometry();
	}
}
