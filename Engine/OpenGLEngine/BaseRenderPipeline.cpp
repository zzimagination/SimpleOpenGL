#include <glad/glad.h>
#include "ProjectSetting.h"
#include "GeometryProcess.h"
#include "BaseRenderPipeline.h"
#include "BatchManager.h"
#include "RenderObject.h"
#include "RenderObjectManager.h"
#include "ShaderManager.h"

void BaseRenderPipeline::Render()
{
	int windowWidth = ProjectSetting::GetWindowWidth();
	int windowHeight = ProjectSetting::GetWindowHeight();

	RenderObjectManager::GenerateRenderObjects();

	GeometryProcess::BindVertexArray();

	BatchManager::GenerateBatchs();

	glViewport(0, 0, windowWidth, windowHeight);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	BatchManager::DrawBatchs();

	BatchManager::ClearBatchs();
	RenderObjectManager::ClearRenderObjects();
}
