#include "GLRendererAPI.h"
#include <glad/glad.h>


namespace SemperEngine
{
	namespace Core
	{
		namespace GraphicAPI
		{
			using namespace std;

			unsigned int GLRenderAPI::_shader = 0;

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
			void GLRenderAPI::SetClear(RenderEnum::ClearMode mode)
			{
				int m = 0;
				if ((int)mode & 1<<0 )
				{
					m |= GL_COLOR_BUFFER_BIT;
				}
				if ((int)mode & 1<<1)
				{
					m |= GL_DEPTH_BUFFER_BIT;
				}
				if ((int)mode & 1<<2)
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
			void GLRenderAPI::SetDepthTestFunc(RenderEnum::DepthFunc func)
			{
				typedef RenderEnum::DepthFunc DepthFunc;
				switch (func)
				{
				case DepthFunc::Never:
					glDepthFunc(GL_NEVER);
					break;
				case DepthFunc::Less :
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
			void GLRenderAPI::SetCullMode(RenderEnum::CullFace face)
			{
				typedef RenderEnum::CullFace CullFace;
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

			void GLRenderAPI::SetShader(unsigned int program)
			{
				glUseProgram(program);
				_shader = program;
			}
			void GLRenderAPI::SetShaderValue(const string& name, bool value)
			{
				auto local = glGetUniformLocation(_shader, name.c_str());
				glUniform1i(local, (int)value);
			}
			void GLRenderAPI::SetShaderValue(const string& name, int value)
			{
				auto local = glGetUniformLocation(_shader, name.c_str());
				glUniform1i(local, value);
			}
			void GLRenderAPI::SetShaderValue(const string& name, float value)
			{
				auto local = glGetUniformLocation(_shader, name.c_str());
				glUniform1f(local, value);
			}
			void GLRenderAPI::SetShaderValue(const string& name, const Float2& value)
			{
				float data[2] = { value.x,value.y };
				auto local = glGetUniformLocation(_shader, name.c_str());
				glUniform2fv(local, 1, data);
			}
			void GLRenderAPI::SetShaderValue(const string& name, const Float3& value)
			{
				float data[3] = { value.x, value.y,value.z };
				auto local = glGetUniformLocation(_shader, name.c_str());
				glUniform3fv(local, 1, data);
			}
			void GLRenderAPI::SetShaderValue(const string& name, const Float4& value)
			{
				float data[4] = { value.x,value.y,value.z,value.w };
				auto local = glGetUniformLocation(_shader, name.c_str());
				glUniform4fv(local, 1, data);
			}
			void GLRenderAPI::SetShaderValue(const string& name, const Matrix4x4& mat)
			{
				float data[4][4];

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
				auto local = glGetUniformLocation(_shader, name.c_str());
				glUniformMatrix4fv(local, 1, GL_FALSE, &data[0][0]);
			}

			void GLRenderAPI::DrawElements(int count)
			{
				glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
			}
			void GLRenderAPI::DrawLines(int count)
			{
				glDrawArrays(GL_LINES, 0, count);
			}
		}
	}
}