#include <glad/glad.h>
#include "ProjectSetting.h"
#include "GeometryProcess.h"
#include "BaseRenderPipeline.h"
#include "BatchManager.h"

void BaseRenderPipeline::Render()
{
	GeometryProcess::BindVertexArray();

	int windowWidth = ProjectSetting::GetWindowWidth();
	int windowHeight = ProjectSetting::GetWindowHeight();

	glViewport(0, 0, windowWidth, windowHeight);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (int i = 0; i < BatchManager::batchList.size(); i++)
	{
		BatchManager::batchList[i].DrawCall();
	}
	BatchManager::batchList.clear();
}
