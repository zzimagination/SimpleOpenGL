#include "GraphicRenderer.h"
#include "GraphicCommandManager.h"
#include "GraphicResource.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		void GraphicRenderer::Wireframe(bool enable)
		{
			GraphicCommandManager::SetWireframe(enable);
		}

		void GraphicRenderer::RenderScreen(
			RenderOperation operation,
			ShaderProperty sproperty,
			vector<GraphicTextureInfo> textures)
		{
			GraphicVertexInfo vertex;
			vertex.info = GraphicResource::screenVertexData;
			RenderMatrix matrix = { Matrix4x4::Identity() ,Matrix4x4::Identity() ,Matrix4x4::Identity() };
			GraphicCommandManager::Draw(vertex, operation, matrix, sproperty, textures);
		}

		void GraphicRenderer::Render(
			GraphicVertexInfo vertex,
			RenderOperation operation,
			RenderMatrix matrix,
			ShaderProperty sproperty,
			vector<GraphicTextureInfo> textures)
		{
			GraphicCommandManager::Draw(vertex, operation, matrix, sproperty, textures);
		}

		void GraphicRenderer::Clear(Color color, Graphic::ClearMode mode)
		{
			GraphicCommandManager::Clear(color, mode);
		}

		void GraphicRenderer::Clear(Color color)
		{
			GraphicCommandManager::Clear(color, ClearColorDepth);
		}
	}
}