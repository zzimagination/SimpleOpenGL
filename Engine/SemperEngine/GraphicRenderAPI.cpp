#include "GraphicRenderAPI.h"
#include "GraphicShaderManager.h"
#include "GraphicShader.h"
#include "VertexData.h"
#include "Texture.h"
#include "GraphicDataCenter.h"
#include "GLRendererAPI.h"


namespace SemperEngine {

	namespace Core {

		using namespace std;
		using namespace GraphicAPI;

		GraphicShader GraphicRenderAPI::_shader;

		int GraphicRenderAPI::_vertexCount = 0;

		void GraphicRenderAPI::SetClearColor(Color color)
		{
			GLRenderAPI::SetClearColor(color);
		}
		void GraphicRenderAPI::SetClear(int mode)
		{
			GLRenderAPI::SetClear(mode);
		}
		void GraphicRenderAPI::SetDepthTest(bool enable)
		{
			GLRenderAPI::SetDepthTest(enable);
		}
		void GraphicRenderAPI::SetDepthTestFunc(int func)
		{
			GLRenderAPI::SetDepthTestFunc(func);
		}
		void GraphicRenderAPI::SetCullFace(bool enable)
		{
			GLRenderAPI::SetCullFace(enable);
		}
		void GraphicRenderAPI::SetCullMode(int mode)
		{
			GLRenderAPI::SetCullMode(mode);
		}

		void GraphicRenderAPI::SetBlend(bool enable)
		{
			GLRenderAPI::SetBlend(enable);
		}

		void GraphicRenderAPI::SetBlendFunc()
		{
			GLRenderAPI::SetBlendFunc(0x0302, 0x0303);
		}

		void GraphicRenderAPI::SetVertexData(GraphicVertexData& data)
		{
			GLRenderAPI::BindVertexBuffer(data.VAO);
			_vertexCount = data.pointCount;
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
			GraphicAPI::GLRenderAPI::DrawElements(_vertexCount);
		}

		void GraphicRenderAPI::SetWireframe(bool enable)
		{
			GLRenderAPI::SetWireframe(enable);
		}
	}
}