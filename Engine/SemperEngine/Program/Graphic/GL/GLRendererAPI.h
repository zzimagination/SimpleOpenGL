#ifndef __GL_RENDERAPI__
#define __GL_RENDERAPI__

#include <vector>
#include <memory>
#include <string>
#include "GLCommon.h"

namespace Semper
{
	namespace GL
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

			enum class Mask
			{
				Depth = 0x00000100,
				Stencil = 0x00000400,
				Color = 0x00004000,
			};

			enum class Filter
			{
				Nearst = 0x2600,
				Linear = 0x2601
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

			static void SetMSAA(bool enable);

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

			static TextureID AttachMSTexture(int width, int height, int index, int sample);

			static unsigned int AttachDepth(int width, int height);

			static unsigned int AttachMSDepth(int width, int height, int sample);

			static void DeleteRenderBuffer(FrameBufferID rbo);

			static void BlitFrameBuffer(FrameBufferID read, FrameBufferID draw, int width, int height, int mask, int filter);

		};
	}
}
#endif // !GL_RENDERER
