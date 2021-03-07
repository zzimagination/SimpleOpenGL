#include "GLRendererAPI.h"
#include <glad/glad.h>
#include "Debug.h"

namespace SemperEngine
{
	namespace Core
	{
		namespace GraphicAPI
		{
			using namespace std;

			void GLRenderAPI::SetWireframe(bool enable)
			{
				if (enable) {
					glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				}
				else
				{
					glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				}
			}

			void GLRenderAPI::SetClearColor(Color color)
			{
				glClearColor(color.R(), color.G(), color.B(), color.A());
			}
			void GLRenderAPI::SetClear(Graphic::ClearMode mode)
			{
				int m = 0;
				if ((int)mode & 1 << 0)
				{
					m |= GL_COLOR_BUFFER_BIT;
				}
				if ((int)mode & 1 << 1)
				{
					m |= GL_DEPTH_BUFFER_BIT;
				}
				if ((int)mode & 1 << 2)
				{
					m |= GL_STENCIL_BUFFER_BIT;
				}
				glClear(m);
			}

			void GLRenderAPI::SetDepthTest(bool enable)
			{
				if (enable)
				{
					glEnable(GL_DEPTH_TEST);
				}
				else
				{
					glDisable(GL_DEPTH_TEST);
				}
			}
			void GLRenderAPI::SetDepthTestFunc(Graphic::DepthFunc func)
			{
				typedef Graphic::DepthFunc DepthFunc;
				switch (func)
				{
				case DepthFunc::Never:
					glDepthFunc(GL_NEVER);
					break;
				case DepthFunc::Less:
					glDepthFunc(GL_LESS);
					break;
				case DepthFunc::Equal:
					glDepthFunc(GL_EQUAL);
					break;
				case DepthFunc::LEqual:
					glDepthFunc(GL_LEQUAL);
					break;
				case DepthFunc::Greater:
					glDepthFunc(GL_GREATER);
					break;
				case DepthFunc::GEqual:
					glDepthFunc(GL_GEQUAL);
					break;
				case DepthFunc::NotEqual:
					glDepthFunc(GL_NOTEQUAL);
					break;
				case DepthFunc::Always:
					glDepthFunc(GL_ALWAYS);
					break;
				default:
					glDepthFunc(GL_LESS);
					break;
				}
			}

			void GLRenderAPI::SetCullFace(bool enable)
			{
				if (enable)
				{
					glEnable(GL_CULL_FACE);
				}
				else
				{
					glDisable(GL_CULL_FACE);
				}
			}
			void GLRenderAPI::SetCullMode(Graphic::CullFace face)
			{
				typedef Graphic::CullFace CullFace;
				switch (face)
				{
				case CullFace::Front:
					glCullFace(GL_FRONT);
					break;
				case CullFace::Back:
					glCullFace(GL_BACK);
					break;
				default:
					glCullFace(GL_BACK);
					break;
				}
			}

			void GLRenderAPI::SetBlendFunc(int source, int dest)
			{
				glBlendFunc(source, dest);
			}

			void GLRenderAPI::SetBlend(bool enable)
			{
				if (enable)
				{
					glEnable(GL_BLEND);
				}
				else
				{
					glDisable(GL_BLEND);
				}
			}

			void GLRenderAPI::BindVertexBuffer(unsigned int VAO)
			{
				glBindVertexArray(VAO);
			}

			void GLRenderAPI::BindTexture2D(int id, unsigned int tex)
			{
				glActiveTexture(GL_TEXTURE0 + id);
				glBindTexture(GL_TEXTURE_2D, tex);
			}

#pragma region Shader

			void GLRenderAPI::SetShader(ShaderPrograme shader)
			{
				glUseProgram(shader);
			}

			void GLRenderAPI::SetShaderValue(ShaderPrograme shader, const string& name, bool value)
			{
				auto local = glGetUniformLocation(shader, name.c_str());
				glUniform1i(local, (int)value);
			}
			void GLRenderAPI::SetShaderValue(ShaderPrograme shader, const string& name, int value)
			{
				auto local = glGetUniformLocation(shader, name.c_str());
				glUniform1i(local, value);
			}
			void GLRenderAPI::SetShaderValue(ShaderPrograme shader, const string& name, float value)
			{
				auto local = glGetUniformLocation(shader, name.c_str());
				glUniform1f(local, value);
			}
			void GLRenderAPI::SetShaderValue(ShaderPrograme shader, const string& name, const Float2& value)
			{
				float data[2] = { value.x,value.y };
				auto local = glGetUniformLocation(shader, name.c_str());
				glUniform2fv(local, 1, data);
			}
			void GLRenderAPI::SetShaderValue(ShaderPrograme shader, const string& name, const Float3& value)
			{
				float data[3] = { value.x, value.y,value.z };
				auto local = glGetUniformLocation(shader, name.c_str());
				glUniform3fv(local, 1, data);
			}
			void GLRenderAPI::SetShaderValue(ShaderPrograme shader, const string& name, const Float4& value)
			{
				float data[4] = { value.x,value.y,value.z,value.w };
				auto local = glGetUniformLocation(shader, name.c_str());
				glUniform4fv(local, 1, data);
			}
			void GLRenderAPI::SetShaderValue(ShaderPrograme shader, const string& name, const Matrix4x4& mat)
			{
				float data[4][4]{};

				data[0][0] = mat.x0;
				data[0][1] = mat.x1;
				data[0][2] = mat.x2;
				data[0][3] = mat.x3;

				data[1][0] = mat.y0;
				data[1][1] = mat.y1;
				data[1][2] = mat.y2;
				data[1][3] = mat.y3;

				data[2][0] = mat.z0;
				data[2][1] = mat.z1;
				data[2][2] = mat.z2;
				data[2][3] = mat.z3;

				data[3][0] = mat.w0;
				data[3][1] = mat.w1;
				data[3][2] = mat.w2;
				data[3][3] = mat.w3;
				auto local = glGetUniformLocation(shader, name.c_str());
				glUniformMatrix4fv(local, 1, GL_FALSE, &data[0][0]);
			}

#pragma endregion

			void GLRenderAPI::DrawElements(int count)
			{
				glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
			}

			void GLRenderAPI::DrawLines(int count)
			{
				glDrawArrays(GL_LINES, 0, count);
			}
			void GLRenderAPI::DrawTriangles(int count)
			{
				glDrawArrays(GL_TRIANGLES, 0, count);
			}
			FrameBufferID GLRenderAPI::CreateFrameBuffer()
			{
				FrameBufferID fbo = 0;
				glGenFramebuffers(1, &fbo);
				return fbo;
			}
			void GLRenderAPI::DeleteFrameBuffer(FrameBufferID fbo)
			{
				glDeleteFramebuffers(1, &fbo);
			}
			void GLRenderAPI::BindFrameBuffer(FrameBufferID fbo)
			{
				glBindFramebuffer(GL_FRAMEBUFFER, fbo);
			}
			void GLRenderAPI::CheckFrameBuffer(FrameBufferID fbo)
			{
				if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
				{
					glBindFramebuffer(GL_FRAMEBUFFER, 0);
					Debug::LogError({ "FrameBuffer error: " , to_string(fbo) });
					return;
				}
			}
			void GLRenderAPI::CloseFrameBuffer()
			{
				glBindFramebuffer(GL_FRAMEBUFFER, 0);
			}

			TextureID GLRenderAPI::AttachTexture(int width, int height, ColorType colorType, int index)
			{
				TextureID texture;
				glGenTextures(1, &texture);
				glBindTexture(GL_TEXTURE_2D, texture);
				glTexImage2D(GL_TEXTURE_2D, 0, (int)colorType, width, height, 0, (int)colorType, GL_UNSIGNED_BYTE, NULL);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + index, GL_TEXTURE_2D, texture, 0);
				return texture;
			}

			unsigned int GLRenderAPI::AttachDepthStencil(int width, int height, bool texture)
			{
				if (!texture) 
				{
					unsigned int rbo;
					glGenRenderbuffers(1, &rbo);
					glBindRenderbuffer(GL_RENDERBUFFER, rbo);
					glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
					glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);
					return rbo;
				}
				else
				{
					unsigned int texture;
					glGenTextures(1, &texture);
					glBindTexture(GL_TEXTURE_2D, texture);
					glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_STENCIL, width, height, 0, GL_DEPTH_STENCIL, GL_UNSIGNED_INT_24_8, NULL);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
					glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, texture, 0);
					return texture;
				}
			}

			void GLRenderAPI::DeleteRenderBuffer(FrameBufferID rbo)
			{
				glDeleteRenderbuffers(1, &rbo);
			}
		}
	}
}