#include "RenderDraw.h"
#include "VertexData.h"
#include "TextureData.h"

#ifdef OPENGL
#include <glad/glad.h>
#endif

namespace SemperEngine {

	Matrix4x4 RenderDraw::model;
	Matrix4x4 RenderDraw::view;
	Matrix4x4 RenderDraw::projection;
	int RenderDraw::drawCount;
	int RenderDraw::textureIndex;

	void RenderDraw::SetClear(int mode, Vector4 color)
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

	void RenderDraw::SetDepthTest(bool test)
	{
		SetDepthTest(test, DepthTestFunc::LEqual);
	}

	void RenderDraw::SetDepthTest(bool test, DepthTestFunc f)
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

	void RenderDraw::SetCullFace(bool cull)
	{
		SetCullFace(cull, CullFace::Back);
	}

	void RenderDraw::SetCullFace(bool cull, CullFace mode)
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

	void RenderDraw::SetShader(ShaderProgram * shader,
		vector<ShaderProperty<float>> floatv,
		vector<ShaderProperty<Vector2>> vector2,
		vector<ShaderProperty<Vector3>> vector3,
		vector<ShaderProperty<Vector4>> vector4,
		vector<ShaderProperty<Matrix4x4>> matrix)
	{
		shader->Use();
		shader->SetValue(MODEL_MATRIX, model);
		shader->SetValue(VIEW_MATRIX, view);
		shader->SetValue(PROJECTION_MARIX, projection);

		for (int i = 0; i < floatv.size(); i++)
		{
			string name = floatv[i].name;
			float value = floatv[i].value;
			shader->SetValue(name, value);
		}

		for (int i = 0; i < vector2.size(); i++)
		{
			string name = vector2[i].name;
			Vector2 value = vector2[i].value;
			shader->SetValue(name, value);
		}

		for (int i = 0; i < vector3.size(); i++)
		{
			string name = vector3[i].name;
			Vector3 value = vector3[i].value;
			shader->SetValue(name, value);
		}

		for (int i = 0; i < vector4.size(); i++)
		{
			string name = vector4[i].name;
			Vector4 value = vector4[i].value;
			shader->SetValue(name, value);
		}

		for (int i = 0; i < matrix.size(); i++)
		{
			string name = matrix[i].name;
			Matrix4x4 value = matrix[i].value;
			shader->SetValue(name, value);
		}

		textureIndex = GL_TEXTURE0;
	}

	void RenderDraw::SetTransform(Matrix4x4 model, Matrix4x4 view, Matrix4x4 projection)
	{
		RenderDraw::model = model;
		RenderDraw::view = view;
		RenderDraw::projection = projection;
	}

	void RenderDraw::SetVertexData(VertexData* data)
	{
		glBindVertexArray(data->VAO);
		drawCount = data->GetCount();
	}

	void RenderDraw::SetTextureData(TextureData * data)
	{
		if (textureIndex > MAX_TEXTURE_COUNT)
		{
			return;
		}
		glActiveTexture(textureIndex);
		glBindTexture(GL_TEXTURE_2D, textureIndex);
		textureIndex++;
	}

	void RenderDraw::Draw()
	{
		glDrawElements(GL_TRIANGLES, drawCount, GL_UNSIGNED_INT, 0);
	}
}