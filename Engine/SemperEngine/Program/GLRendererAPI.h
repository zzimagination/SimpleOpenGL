#pragma once
#ifndef __GL_RENDERAPI__
#define __GL_RENDERAPI__

#include <vector>
#include <memory>
#include <string>
#include "Graphic.h"

namespace SemperEngine
{
	namespace Core
	{
		namespace GraphicAPI
		{
			typedef unsigned int FrameBufferID;
			typedef unsigned int RenderBufferID;
			typedef unsigned int TextureID;
			typedef unsigned int ShaderPrograme;

			class GLRenderAPI
			{
			public:

				enum class ColorType
				{
					RGB = 0x1907,

					RGBA = 0x1908
				}; 

			public:

				static void SetWireframe(bool enable);

				static void SetClearColor(Color color);

				static void SetClear(Graphic::ClearMode mode);

				static void SetDepthTest(bool enable);

				static void SetDepthTestFunc(Graphic::DepthFunc func);

				static void SetCullFace(bool enable);

				static void SetCullMode(Graphic::CullFace face);

				static void SetBlendFunc(int source, int dest);

				static void SetBlend(bool enable);

				static void BindVertexBuffer(unsigned int VAO);

				static void BindTexture2D(int id, unsigned int tex);

				static void SetShader(ShaderPrograme shader);

				static void SetShaderValue(ShaderPrograme shader, const std::string& name, bool value);

				static void SetShaderValue(ShaderPrograme shader, const std::string& name, int value);

				static void SetShaderValue(ShaderPrograme shader, const std::string& name, float value);

				static void SetShaderValue(ShaderPrograme shader, const std::string& name, const Float2& value);

				static void SetShaderValue(ShaderPrograme shader, const std::string& name, const Float3& value);

				static void SetShaderValue(ShaderPrograme shader, const std::string& name, const Float4& value);

				static void SetShaderValue(ShaderPrograme shader, const std::string& name, const Matrix4x4& mat);

				static void DrawElements(int count);

				static void DrawLines(int count);

				static void DrawTriangles(int count);

				static FrameBufferID CreateFrameBuffer();

				static void DeleteFrameBuffer(FrameBufferID fbo);

				static void BindFrameBuffer(FrameBufferID fbo);

				static void CloseFrameBuffer();

				static void CheckFrameBuffer(FrameBufferID fbo);

				static TextureID AttachTexture(int width, int height, ColorType colorType, int index);

				static unsigned int AttachDepthStencil(int width, int height);

				static void DeleteRenderBuffer(FrameBufferID rbo);
			};
		}
	}
}
#endif // !GL_RENDERER
