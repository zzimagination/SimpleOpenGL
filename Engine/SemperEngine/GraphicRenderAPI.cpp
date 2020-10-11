#include "GraphicRenderAPI.h"
#include "GraphicVertexData.h"
#include "GraphicTextureData.h"
#include "GraphicShaderManager.h"
#include "GraphicShader.h"
#include "VertexData.h"
#include "Texture.h"

#include "GLRendererAPI.h"


namespace SemperEngine {

	namespace Core {

		using namespace GraphicAPI;

		GraphicVertexData GraphicRenderAPI::_vertexData;

		Matrix4x4 GraphicRenderAPI::_model;

		Matrix4x4 GraphicRenderAPI::_view;

		Matrix4x4 GraphicRenderAPI::_projection;

		GraphicShader GraphicRenderAPI::_shader;

		ShaderProperty GraphicRenderAPI::_shaderProperty;

		int GraphicRenderAPI::textureIndex;

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

		void GraphicRenderAPI::SetVertexData(GraphicVertexData& data)
		{
			_vertexData = data;
		}

		void GraphicRenderAPI::SetTransform(Matrix4x4& model, Matrix4x4& view, Matrix4x4& projection)
		{
			_model = model;
			_view = view;
			_projection = projection;
		}

		void GraphicRenderAPI::SetShader(std::string shader)
		{
			_shader = GraphicShaderManager::FindShader(shader);
		}

		void GraphicRenderAPI::SetShaderProperty(ShaderProperty value)
		{
			_shaderProperty = value;
		}

		void GraphicRenderAPI::Draw()
		{
			GLRenderAPI::BindVertexBuffer(_vertexData.VAO);

			GLRenderAPI::SetShader(_shader.opengl_id);
			GLRenderAPI::SetShaderValue(MODEL_MATRIX, _model);
			GLRenderAPI::SetShaderValue(VIEW_MATRIX, _view);
			GLRenderAPI::SetShaderValue(PROJECTION_MARIX, _projection);
			auto f = _shaderProperty.floatProperty;
			for (auto i = f.begin(); i != f.end(); i++)
			{
				string name = i->first;
				float value = i->second;
				GLRenderAPI::SetShaderValue(name, value);
			}
			auto v2 = _shaderProperty.vector2Property;
			for (auto i = v2.begin(); i != v2.end(); i++)
			{
				string name = i->first;
				Vector2 value = i->second;
				GLRenderAPI::SetShaderValue(name, value);
			}
			auto v3 = _shaderProperty.vector3Property;
			for (auto i = v3.begin(); i != v3.end(); i++)
			{
				string name = i->first;
				Vector3 value = i->second;
				GLRenderAPI::SetShaderValue(name, value);
			}
			auto v4 = _shaderProperty.vector4Property;
			for (auto i = v4.begin(); i != v4.end(); i++)
			{
				string name = i->first;
				Vector4 value = i->second;
				GLRenderAPI::SetShaderValue(name, value);
			}
			auto m4 = _shaderProperty.matrix4x4Property;
			for (auto i = m4.begin(); i != m4.end(); i++)
			{
				string name = i->first;
				Matrix4x4 value = i->second;
				GLRenderAPI::SetShaderValue(name, value);
			}

			GraphicAPI::GLRenderAPI::DrawElements(_vertexData.pointCount);
		}

		void GraphicRenderAPI::SetWireframe(bool enable)
		{
			GLRenderAPI::SetWireframe(enable);
		}




		void GraphicRenderAPI::SetTextureData(GraphicTextureData* data)
		{
			//if (textureIndex > MAX_TEXTURE_COUNT)
			//{
			//	return;
			//}
			//glActiveTexture(textureIndex);
			//glBindTexture(GL_TEXTURE_2D, textureIndex);
			//textureIndex++;
		}

		GraphicTextureData* GraphicRenderAPI::AddTextureData(Texture* data)
		{
			unsigned int textureID = 0;
			//glGenTextures(1, &textureID);
			//GLenum format, internalFormal;
			//format = GL_RGBA;
			//internalFormal = GL_RGBA;
			//glBindTexture(GL_TEXTURE_2D, textureID);
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
			//glTexImage2D(GL_TEXTURE_2D, 0, internalFormal, data->width, data->height, 0, format, GL_UNSIGNED_BYTE, data->data);
			auto result = new GraphicTextureData(data, textureID);
			return result;
		}

		void GraphicRenderAPI::ClearTextureData(GraphicTextureData* data)
		{
			//glDeleteTextures(1, &data->textureId);
		}
	}
}