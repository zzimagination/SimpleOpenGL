#include "RenderDraw.h"
#include "VertexData.h"
#include "TextureData.h"

#ifdef OPENGL
#include <glad/glad.h>
#endif

Matrix4x4 RenderDraw::model;
Matrix4x4 RenderDraw::view;
Matrix4x4 RenderDraw::projection;
int RenderDraw::drawCount;

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

void RenderDraw::SetShader(Material* material)
{
	material->shader->Use();
	for (int i = 0; i < material->floatProperty.Size(); i++)
	{
		string name = material->floatProperty.GetName(i);
		float value = material->floatProperty.GetValue(i);
		material->shader->SetValue(name, value);
	}

	for (int i = 0; i < material->vector2Property.Size(); i++)
	{
		string name = material->vector2Property.GetName(i);
		Vector2 value = material->vector2Property.GetValue(i);
		material->shader->SetValue(name, value);
	}

	for (int i = 0; i < material->vector3Property.Size(); i++)
	{
		string name = material->vector3Property.GetName(i);
		Vector3 value = material->vector3Property.GetValue(i);
		material->shader->SetValue(name, value);
	}

	for (int i = 0; i < material->vector4Property.Size(); i++)
	{
		string name = material->vector4Property.GetName(i);
		Vector4 value = material->vector4Property.GetValue(i);
		material->shader->SetValue(name, value);
	}

	for (int i = 0; i < material->matrixProperty.Size(); i++)
	{
		string name = material->matrixProperty.GetName(i);
		Matrix4x4 value = material->matrixProperty.GetValue(i);
		material->shader->SetValue(name, value);
	}

	material->shader->SetValue(MODEL_MATRIX, model);
	material->shader->SetValue(VIEW_MATRIX, view);
	material->shader->SetValue(PROJECTION_MARIX, projection);
}

void RenderDraw::SetTransform(Matrix4x4 model, Matrix4x4 view, Matrix4x4 projection)
{
	RenderDraw::model = model;
	RenderDraw::view = view;
	RenderDraw::projection = projection;
}

void RenderDraw::SetVertexData(VertexData* data)
{
	data->UseData();
	drawCount = data->GetCount();
}

void RenderDraw::SetTextureData(TextureData * data)
{
	data->UseData();
}

void RenderDraw::Draw()
{
	glDrawElements(GL_TRIANGLES, drawCount, GL_UNSIGNED_INT, 0);
}
