#include <glad/glad.h>
#include "../ProjectSetting.h"
#include "GeometryProcess.h"
#include "BaseRenderPipeline.h"
#include "BatchManager.h"
#include "RenderObject.h"
#include "RenderObjectManager.h"
#include "ShaderManager.h"

void BaseRenderPipeline::Render()
{
	GeometryProcess::BindVertexArray();

	BatchManager::GenerateBatchs();

	//int windowWidth = ProjectSetting::GetWindowWidth();
	//int windowHeight = ProjectSetting::GetWindowHeight();
	//glViewport(0, 0, windowWidth, windowHeight);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	BatchManager::DrawBatchs();
	//RenderObjectManager::ClearRenderObjects();
}
