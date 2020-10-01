#include "GraphicRenderDraw.h"
#include "GraphicVertexData.h"
#include "GraphicTextureData.h"
#include "GraphicShaderManager.h"
#include "GraphicShader.h"
#include "VertexData.h"
#include "Texture.h"

#ifdef OPENGL
#include <glad/glad.h>
#endif

namespace SemperEngine {

	Matrix4x4 GraphicRenderDraw::model;
	Matrix4x4 GraphicRenderDraw::view;
	Matrix4x4 GraphicRenderDraw::projection;
	int GraphicRenderDraw::drawCount;
	int GraphicRenderDraw::textureIndex;

	void GraphicRenderDraw::TestRender()
	{
		float vertices[24] = {
			0.5, 0.5, 0,
			0.5, -0.5, 0,
			-0.5, 0.5, 0,
			-0.5, -0.5, 0,
			-0.5, 0.5, 0,
			0.5, -0.5, 0
		};

		unsigned int VAO, VBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 24, vertices, GL_STATIC_DRAW);//首先执行这个
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
		auto shader = ShaderManager::GetShader("Debug");
		shader->SetValue("_projection", Matrix4x4::Identity());
		shader->SetValue("_view", Matrix4x4::Identity());
		shader->SetValue("_model", Matrix4x4::Identity());
		shader->Use();

		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDeleteBuffers(1, &VBO);
		glDeleteVertexArrays(1, &VAO);
	}

	void GraphicRenderDraw::SetClear(int mode, Vector4 color)
	{
		int m = 0;
		if ((mode & ClearMode::Color) != 0)
		{
			m |= GL_COLOR_BUFFER_BIT;
			glClearColor(color.x, color.y, color.z, color.w);
		}
		if ((mode & ClearMode::Depth) != 0)
		{
			m |= GL_DEPTH_BUFFER_BIT;
		}
		if ((mode&ClearMode::Stencil) != 0)
		{
			m |= GL_STENCIL_BUFFER_BIT;
		}
		glClear(m);
	}

	void GraphicRenderDraw::SetDepthTest(bool test)
	{
		SetDepthTest(test, DepthTestFunc::LEqual);
	}

	void GraphicRenderDraw::SetDepthTest(bool test, DepthTestFunc f)
	{
		if (test)
		{
			switch (f)
			{
			case Never: glDepthFunc(GL_NEVER);
				break;
			case Less: glDepthFunc(GL_LESS);
				break;
			case Equal:glDepthFunc(GL_EQUAL);
				break;
			case LEqual: glDepthFunc(GL_LEQUAL);
				break;
			case Greater: glDepthFunc(GL_GREATER);
				break;
			case GEqual: glDepthFunc(GL_GEQUAL);
				break;
			case NotEqual:glDepthFunc(GL_NOTEQUAL);
				break;
			case Always: glDepthFunc(GL_ALWAYS);
				break;
			}
			glEnable(GL_DEPTH_TEST);
		}
		else
		{
			glDisable(GL_DEPTH_TEST);
		}
	}

	void GraphicRenderDraw::SetCullFace(bool cull)
	{
		SetCullFace(cull, CullFace::Back);
	}

	void GraphicRenderDraw::SetCullFace(bool cull, CullFace mode)
	{
		if (cull)
		{
			switch (mode)
			{
			case Front:
				glCullFace(GL_FRONT);
				break;
			case Back:
				glCullFace(GL_BACK);
				break;
			}
			glEnable(GL_CULL_FACE);
		}
		else
		{
			glDisable(GL_CULL_FACE);
		}
	}

	void GraphicRenderDraw::SetShader(Material* material)
	{
		auto shader = material->shader;
		auto floatProperty = material->floatProperty;
		auto vector2Property = material->vector2Property;
		auto vector3Property = material->vector3Property;
		auto vector4Property = material->vector4Property;
		auto matrix4x4Property = material->matrix4x4Property;

		shader->Use();
		shader->SetValue(MODEL_MATRIX, model);
		shader->SetValue(VIEW_MATRIX, view);
		shader->SetValue(PROJECTION_MARIX, projection);

		auto floatValues = floatProperty.GetKeyValues();
		for (int i = 0; i < floatValues.size(); i++)
		{
			string name = floatValues[i].first;
			float value = floatValues[i].second;
			shader->SetValue(name, value);
		}

		auto vector2Values = vector2Property.GetKeyValues();
		for (int i = 0; i < vector2Values.size(); i++)
		{
			string name = vector2Values[i].first;
			Vector2 value = vector2Values[i].second;
			shader->SetValue(name, value);
		}

		auto vector3Values = vector3Property.GetKeyValues();
		for (int i = 0; i < vector3Values.size(); i++)
		{
			string name = vector3Values[i].first;
			Vector3 value = vector3Values[i].second;
			shader->SetValue(name, value);
		}

		auto vector4Values = vector4Property.GetKeyValues();
		for (int i = 0; i < vector4Values.size(); i++)
		{
			string name = vector4Values[i].first;
			Vector4 value = vector4Values[i].second;
			shader->SetValue(name, value);
		}

		auto matrix4x4 = matrix4x4Property.GetKeyValues();
		for (int i = 0; i < matrix4x4.size(); i++)
		{
			string name = matrix4x4[i].first;
			Matrix4x4 value = matrix4x4[i].second;
			shader->SetValue(name, value);
		}

		textureIndex = GL_TEXTURE0;
	}

	void GraphicRenderDraw::SetTransform(Matrix4x4 model, Matrix4x4 view, Matrix4x4 projection)
	{
		GraphicRenderDraw::model = model;
		GraphicRenderDraw::view = view;
		GraphicRenderDraw::projection = projection;
	}

	void GraphicRenderDraw::SetVertexData(GraphicVertexData &data)
	{
		glBindVertexArray(data.VAO);
		drawCount = data.pointCount;
	}

	void GraphicRenderDraw::SetTextureData(GraphicTextureData * data)
	{
		if (textureIndex > MAX_TEXTURE_COUNT)
		{
			return;
		}
		glActiveTexture(textureIndex);
		glBindTexture(GL_TEXTURE_2D, textureIndex);
		textureIndex++;
	}

	void GraphicRenderDraw::Draw()
	{
		glDrawElements(GL_TRIANGLES, drawCount, GL_UNSIGNED_INT, 0);
	}

	GraphicVertexData GraphicRenderDraw::AddVertexData(Vector3* vertices, Vector2* uv, int* index, int count)
	{
		unsigned VAO = 0, VBO = 0, EBO = 0, pointCount = 0;

		if (count >= 4)
		{
			pointCount = count / 4 * 6;
			if (count / 4 * 6 != pointCount)
			{
				throw "indexSize is not match indexSize vertexData";
			}
		}
		else
		{
			pointCount = count;
		}

		int verticesSize = count * sizeof(Vector3);
		int uvSize = count * sizeof(Vector2);
		int indexSize = pointCount * sizeof(int);
		int totalSize = verticesSize + uvSize + indexSize;

		if (verticesSize == 0 || indexSize == 0)
		{
			throw "vertexData is null";
		}

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

		glBufferData(GL_ARRAY_BUFFER, totalSize, 0, GL_STATIC_DRAW);//首先执行这个
		int offset = 0;
		glBufferSubData(GL_ARRAY_BUFFER, offset, verticesSize, vertices);
		offset += verticesSize;
		if (uvSize > 0) {
			glBufferSubData(GL_ARRAY_BUFFER, offset, uvSize, uv);
			offset += uvSize;
		}

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexSize, index, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vector3), (void*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vector2), (void*)verticesSize);

		// note that this is allowed, the call to glVertexAttribPointer registered VBO 
		// as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
		// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
		glBindVertexArray(0);

		auto result = GraphicVertexData(VAO, VBO, EBO, pointCount);
		return result;
	}

	GraphicTextureData * GraphicRenderDraw::AddTextureData(Texture * data)
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

	void GraphicRenderDraw::ClearVertexData(GraphicVertexData& data)
	{
		glDeleteBuffers(1, &data.EBO);//注意顺序
		glDeleteBuffers(1, &data.VBO);
		glDeleteVertexArrays(1, &data.VAO);
	}

	void GraphicRenderDraw::ClearTextureData(GraphicTextureData * data)
	{
		glDeleteTextures(1, &data->textureId);
	}
}