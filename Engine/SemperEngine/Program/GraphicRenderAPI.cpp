#include "GraphicRenderAPI.h"
#include "GraphicShaderManager.h"
#include "GraphicShader.h"
#include "Texture.h"
#include "GraphicResource.h"
#include "GLRendererAPI.h"

namespace SemperEngine {

	namespace Core {

		using namespace std;
		using namespace GraphicAPI;

		GraphicShader GraphicRenderAPI::_shader;

		int GraphicRenderAPI::_vertexCount = 0;

		GraphicRenderAPI::DrawType GraphicRenderAPI::_drawType = GraphicRenderAPI::DrawType::Nomal;

		void GraphicRenderAPI::SetClearColor(Color color)
		{
			GLRenderAPI::SetClearColor(color);
		}
		void GraphicRenderAPI::SetClear(Graphic::ClearMode mode)
		{
			GLRenderAPI::SetClear(mode);
		}
		void GraphicRenderAPI::SetDepthTest(bool enable)
		{
			GLRenderAPI::SetDepthTest(enable);
		}
		void GraphicRenderAPI::SetDepthTestFunc(Graphic::DepthFunc func)
		{
			GLRenderAPI::SetDepthTestFunc(func);
		}
		void GraphicRenderAPI::SetCullFace(bool enable)
		{
			GLRenderAPI::SetCullFace(enable);
		}
		void GraphicRenderAPI::SetCullMode(Graphic::CullFace face)
		{
			GLRenderAPI::SetCullMode(face);
		}

		void GraphicRenderAPI::SetBlend(bool enable)
		{
			GLRenderAPI::SetBlend(enable);
		}

		void GraphicRenderAPI::SetBlendFunc()
		{
			GLRenderAPI::SetBlendFunc(0x0302, 0x0303);
		}

		void GraphicRenderAPI::SetVertexData(GraphicVertexData data)
		{
			GLRenderAPI::BindVertexBuffer(data.VAO);
			_vertexCount = data.pointCount;
			_drawType = data.indexDraw ? DrawType::Index : DrawType::Nomal;
		}

		void GraphicRenderAPI::SetShader(std::string shader)
		{
			_shader = GraphicShaderManager::FindShader(shader);
			GLRenderAPI::SetShader(_shader.opengl_id);
		}

		void GraphicRenderAPI::SetShaderProperty(std::string name, float& value)
		{
			GLRenderAPI::SetShaderValue(name, value);
		}

		void GraphicRenderAPI::SetShaderProperty(std::string name, Float2& value)
		{
			GLRenderAPI::SetShaderValue(name, value);
		}

		void GraphicRenderAPI::SetShaderProperty(std::string name, Float3& value)
		{
			GLRenderAPI::SetShaderValue(name, value);
		}

		void GraphicRenderAPI::SetShaderProperty(std::string name, Float4& value)
		{
			GLRenderAPI::SetShaderValue(name, value);
		}

		void GraphicRenderAPI::SetShaderProperty(std::string name, Matrix4x4& value)
		{
			GLRenderAPI::SetShaderValue(name, value);
		}

		void GraphicRenderAPI::SetShaderProperty(int id, GraphicTextureData& data)
		{
			GLRenderAPI::BindTexture2D(id, data.glid);
		}

		void GraphicRenderAPI::Draw()
		{
			switch (_drawType)
			{
			case DrawType::Nomal:
				GLRenderAPI::DrawTriangles(_vertexCount);
				break;
			case DrawType::Index:
				GLRenderAPI::DrawElements(_vertexCount);
				break;
			default:
				break;
			}
			_vertexCount = 0;
			_drawType = DrawType::Nomal;
		}

		void GraphicRenderAPI::SetWireframe(bool enable)
		{
			GLRenderAPI::SetWireframe(enable);
		}
	}
}