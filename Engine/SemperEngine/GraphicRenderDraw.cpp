#include "GraphicRenderDraw.h"
#include "GraphicVertexData.h"
#include "GraphicTextureData.h"
#include "GraphicShaderManager.h"
#include "GraphicShader.h"
#include "VertexData.h"
#include "Texture.h"

#include "GLRendererAPI.h"

#ifdef OPENGL
#include <glad/glad.h>
#endif

namespace SemperEngine {

	namespace Core {

		using namespace GraphicAPI;
		
		GraphicVertexData GraphicRenderDraw::_vertexData;

		Matrix4x4 GraphicRenderDraw::_model;

		Matrix4x4 GraphicRenderDraw::_view;

		Matrix4x4 GraphicRenderDraw::_projection;

		Material* GraphicRenderDraw::_material;



		int GraphicRenderDraw::textureIndex;

		void GraphicRenderDraw::SetClearColor(Vector4 color)
		{
			GLRenderAPI::SetClearColor(color);
		}
		void GraphicRenderDraw::SetClear(int mode)
		{
			GLRenderAPI::SetClear(mode);
		}
		void GraphicRenderDraw::SetDepthTest(bool enable)
		{
			GLRenderAPI::SetDepthTest(enable);
		}
		void GraphicRenderDraw::SetDepthTestFunc(int func)
		{
			GLRenderAPI::SetDepthTestFunc(func);
		}
		void GraphicRenderDraw::SetCullFace(bool enable)
		{
			GLRenderAPI::SetCullFace(enable);
		}
		void GraphicRenderDraw::SetCullMode(int mode)
		{
			GLRenderAPI::SetCullMode(mode);
		}

		void GraphicRenderDraw::SetVertexData(GraphicVertexData& data)
		{
			_vertexData = data;
		}

		void GraphicRenderDraw::SetTransform(Matrix4x4 &model, Matrix4x4 &view, Matrix4x4 &projection)
		{
			_model = model;
			_view = view;
			_projection = projection;
		}

		void GraphicRenderDraw::SetMaterial(Material* material)
		{
			_material = material;
		}

		void GraphicRenderDraw::Draw()
		{
			GLRenderAPI::BindVertexBuffer(_vertexData.VAO);
			GLRenderAPI::SetShader(_material->shader.opengl_id);

			GLRenderAPI::SetShaderValue(MODEL_MATRIX, _model);
			GLRenderAPI::SetShaderValue(VIEW_MATRIX, _view);
			GLRenderAPI::SetShaderValue(PROJECTION_MARIX, _projection);

			auto floatValues = _material->floatProperty.GetKeyValues();
			for (int i = 0; i < floatValues.size(); i++)
			{
				string name = floatValues[i].first;
				float value = floatValues[i].second;
				GLRenderAPI::SetShaderValue(name, value);
			}
			auto vector2Values = _material->vector2Property.GetKeyValues();
			for (int i = 0; i < vector2Values.size(); i++)
			{
				string name = vector2Values[i].first;
				Vector2 value = vector2Values[i].second;
				GLRenderAPI::SetShaderValue(name, value);
			}
			auto vector3Values = _material->vector3Property.GetKeyValues();
			for (int i = 0; i < vector3Values.size(); i++)
			{
				string name = vector3Values[i].first;
				Vector3 value = vector3Values[i].second;
				GLRenderAPI::SetShaderValue(name, value);
			}
			auto vector4Values = _material->vector4Property.GetKeyValues();
			for (int i = 0; i < vector4Values.size(); i++)
			{
				string name = vector4Values[i].first;
				Vector4 value = vector4Values[i].second;
				GLRenderAPI::SetShaderValue(name, value);
			}
			auto matrix4x4 = _material->matrix4x4Property.GetKeyValues();
			for (int i = 0; i < matrix4x4.size(); i++)
			{
				string name = matrix4x4[i].first;
				Matrix4x4 value = matrix4x4[i].second;
				GLRenderAPI::SetShaderValue(name, value);
			}

			GraphicAPI::GLRenderAPI::DrawElements(_vertexData.pointCount);
		}




		void GraphicRenderDraw::SetTextureData(GraphicTextureData* data)
		{
			if (textureIndex > MAX_TEXTURE_COUNT)
			{
				return;
			}
			glActiveTexture(textureIndex);
			glBindTexture(GL_TEXTURE_2D, textureIndex);
			textureIndex++;
		}

		GraphicTextureData* GraphicRenderDraw::AddTextureData(Texture* data)
		{
			unsigned int textureID;
			glGenTextures(1, &textureID);
			GLenum format, internalFormal;
			format = GL_RGBA;
			internalFormal = GL_RGBA;
			glBindTexture(GL_TEXTURE_2D, textureID);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
			glTexImage2D(GL_TEXTURE_2D, 0, internalFormal, data->width, data->height, 0, format, GL_UNSIGNED_BYTE, data->data);
			auto result = new GraphicTextureData(data, textureID);
			return result;
		}

		void GraphicRenderDraw::ClearTextureData(GraphicTextureData* data)
		{
			glDeleteTextures(1, &data->textureId);
		}
	}
}