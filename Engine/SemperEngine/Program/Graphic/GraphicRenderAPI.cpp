#include "GraphicRenderAPI.h"
#include "GraphicShaderManager.h"
#include "GraphicShader.h"
#include "GL/GLRendererAPI.h"
#include "GL/GLResourceAPI.h"
#include "../GameSetting.h"

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
			GLRenderAPI::SetShaderValue(_shader.opengl_id, name, value);
		}

		void GraphicRenderAPI::SetShaderProperty(std::string name, Float2& value)
		{
			GLRenderAPI::SetShaderValue(_shader.opengl_id, name, value);
		}

		void GraphicRenderAPI::SetShaderProperty(std::string name, Float3& value)
		{
			GLRenderAPI::SetShaderValue(_shader.opengl_id, name, value);
		}

		void GraphicRenderAPI::SetShaderProperty(std::string name, Float4& value)
		{
			GLRenderAPI::SetShaderValue(_shader.opengl_id, name, value);
		}

		void GraphicRenderAPI::SetShaderProperty(std::string name, Matrix4x4& value)
		{
			GLRenderAPI::SetShaderValue(_shader.opengl_id, name, value);
		}

		void GraphicRenderAPI::SetShaderProperty(int id, GraphicTextureData& data)
		{
			GLRenderAPI::BindTexture2D(id, data.glID);
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

		void GraphicRenderAPI::CreateRecord(GraphicRecord* record)
		{
			record->glFrameBuffer = GLRenderAPI::CreateFrameBuffer();
			if (record->msaa > 0)
			{
				GLRenderAPI::SetMSAA(true);
				GLRenderAPI::BindFrameBuffer(record->glFrameBuffer);
				GraphicTextureData textureData;
				auto msTexID = GLRenderAPI::AttachMSTexture(record->width, record->height, 0, record->msaa);
				textureData.SetGLTexture(msTexID);
				record->textures.push_back(textureData);
				record->glRenderBuffer = GLRenderAPI::AttachMSDepth(record->width, record->height, record->msaa);
				GLRenderAPI::CheckFrameBuffer(record->glFrameBuffer);
				GLRenderAPI::CloseFrameBuffer(); //optimize
				return;
			}

			GLRenderAPI::BindFrameBuffer(record->glFrameBuffer);
			GraphicTextureData textureData;
			auto texID = GLRenderAPI::AttachTexture(record->width, record->height, GLRenderAPI::ColorType::RGB, 0);
			textureData.SetGLTexture(texID);
			record->textures.push_back(textureData);
			record->glRenderBuffer = GLRenderAPI::AttachDepth(record->width, record->height);
			GLRenderAPI::CheckFrameBuffer(record->glFrameBuffer);
			GLRenderAPI::CloseFrameBuffer(); //optimize
		}

		void GraphicRenderAPI::StartRecord(GraphicRecord* record)
		{
			GLRenderAPI::SetMSAA(record->MSAAEnable());
			GLRenderAPI::BindFrameBuffer(record->glFrameBuffer);
		}

		void GraphicRenderAPI::StopRecord(GraphicRecord* record)
		{
			GLRenderAPI::CloseFrameBuffer();
			GLRenderAPI::SetMSAA(record->MSAAEnable());
		}

		void GraphicRenderAPI::DeleteRecord(GraphicRecord* record)
		{
			GLRenderAPI::DeleteFrameBuffer(record->glFrameBuffer);
			for (auto tex = record->textures.begin(); tex != record->textures.end(); tex++)
			{
				GLResourceAPI::ClearTextureData(tex->glID);
			}
			if (record->glRenderBuffer >= 0)
			{
				GLRenderAPI::DeleteRenderBuffer(record->glRenderBuffer);
			}
		}

		void GraphicRenderAPI::DefaultFrameBuffer(GraphicRecord* record)
		{
			GLRenderAPI::BlitFrameBuffer(record->glFrameBuffer, 0, record->width, record->height, (int)GLRenderAPI::Mask::Color, (int)GLRenderAPI::Filter::Linear);
			GLRenderAPI::BindFrameBuffer(0);
		}
	}
}