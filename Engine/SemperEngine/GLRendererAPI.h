#pragma once
#ifndef __GL_RENDERAPI__
#define __GL_RENDERAPI__

#include <vector>
#include <memory>
#include <string>
#include "Mathz.h"
#include "Render.h"

namespace SemperEngine
{
	namespace Core
	{
		namespace GraphicAPI
		{
			class GLRenderAPI
			{
			private:

				static unsigned int _shader;

			public:

				static void SetWireframe(bool enable);

				static void SetClearColor(Color color);

				static void SetClear(RenderEnum::ClearMode mode);

				static void SetDepthTest(bool enable);

				static void SetDepthTestFunc(RenderEnum::DepthFunc func);

				static void SetCullFace(bool enable);

				static void SetCullMode(RenderEnum::CullFace face);

				static void SetBlendFunc(int source, int dest);

				static void SetBlend(bool enable);

				static void BindVertexBuffer(unsigned int VAO);

				static void BindTexture2D(int id, unsigned int tex);

				static void SetShader(unsigned int program);

				static void SetShaderValue(const std::string& name, bool value);

				static void SetShaderValue(const std::string& name, int value);

				static void SetShaderValue(const std::string& name, float value);

				static void SetShaderValue(const std::string& name, const Float2& value);

				static void SetShaderValue(const std::string& name, const Float3& value);

				static void SetShaderValue(const std::string& name, const Float4& value);

				static void SetShaderValue(const std::string& name, const Matrix4x4& mat);

				static void DrawElements(int count);

				static void DrawLines(int count);
			};
		}
	}
}
#endif // !GL_RENDERER
