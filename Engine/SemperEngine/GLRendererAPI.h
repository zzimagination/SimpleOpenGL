#pragma once
#ifndef GL_RENDERAPI
#define GL_RENDERAPI

#include <vector>
#include <memory>
#include <string>
#include "Mathz.h"

namespace SemperEngine
{
	namespace GraphicAPI
	{
		class GLRenderAPI
		{
		private:

			static unsigned int _shader;

		public:

			static void SetClearColor(Vector4 color);

			static void SetClear(int mode);

			static void SetDepthTest(bool enable);

			static void SetDepthTestFunc(int func);

			static void SetCullFace(bool enable);

			static void SetCullMode(int mode);

			static void BindVertexBuffer(unsigned int VAO);

			static void SetShader(unsigned int program);

			static void SetShaderValue(const std::string& name, bool value);

			static void SetShaderValue(const std::string& name, int value);

			static void SetShaderValue(const std::string& name, float value);

			static void SetShaderValue(const std::string& name, const Vector2& value);

			static void SetShaderValue(const std::string& name, const Vector3& value);

			static void SetShaderValue(const std::string& name, const Vector4& value);

			static void SetShaderValue(const std::string& name, const Matrix4x4& mat);

			static void DrawElements(int count);
		};
	}
}

#endif // !GL_RENDERER
