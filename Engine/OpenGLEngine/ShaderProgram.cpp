#include "ShaderProgram.h"
#include <glad/glad.h>

using namespace std;

ShaderProgram::ShaderProgram() {}

ShaderProgram::~ShaderProgram()
{
	//glDeleteProgram(ID);
}

ShaderProgram::ShaderProgram(const char* vertexPath, const char* fragmentPath, const char* geometryPath)
{
	// 1. 从文件路径中获取顶点/片段着色器
	string vertexCode;
	string fragmentCode;
	string geometryCode;
	ifstream vShaderFile;
	ifstream fShaderFile;
	ifstream gShaderFile;
	// 保证ifstream对象可以抛出异常：
	vShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
	fShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
	gShaderFile.exceptions(ifstream::failbit | ifstream::badbit);

	// 打开文件
	vShaderFile.open(vertexPath);
	fShaderFile.open(fragmentPath);
	stringstream vShaderStream, fShaderStream;
	// 读取文件的缓冲内容到数据流中
	vShaderStream << vShaderFile.rdbuf();
	fShaderStream << fShaderFile.rdbuf();
	// 关闭文件处理器
	vShaderFile.close();
	fShaderFile.close();
	// 转换数据流到string
	vertexCode = vShaderStream.str();
	fragmentCode = fShaderStream.str();
	if (geometryPath != nullptr)
	{
		gShaderFile.open(geometryPath);
		std::stringstream gShaderStream;
		gShaderStream << gShaderFile.rdbuf();
		gShaderFile.close();
		geometryCode = gShaderStream.str();
	}

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();

	// 2. 编译着色器
	unsigned int vertex, fragment;
	int success;
	char infoLog[512];

	// 顶点着色器
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	// 打印编译错误（如果有的话）
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	};

	//片段着色器
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	unsigned int geometry;
	if (geometryPath != nullptr)
	{
		const char * gShaderCode = geometryCode.c_str();
		geometry = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(geometry, 1, &gShaderCode, NULL);
		glCompileShader(geometry);
		glGetShaderiv(geometry, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(geometry, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
	}
	// 着色器程序
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	if (geometryPath != nullptr)
		glAttachShader(ID, geometry);
	glLinkProgram(ID);

	// 打印连接错误（如果有的话）
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	// 删除着色器，它们已经链接到我们的程序中了，已经不再需要了
	glDeleteShader(vertex);
	glDeleteShader(fragment);
	if (geometryPath != nullptr)
	{
		glDeleteShader(geometry);
	}
}

void ShaderProgram::use()
{
	glUseProgram(ID);
}

void ShaderProgram::setBool(const string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}
void ShaderProgram::setInt(const string& name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
void ShaderProgram::setFloat(const string& name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void ShaderProgram::setVec2(const string& name, const Vector2& value) const
{
	float data[2] = { value.x,value.y };
	glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, data);
}
void ShaderProgram::setVec3(const string& name, const Vector3& value) const
{
	float data[3] = { value.x, value.y,value.z };
	glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, data);
}
void ShaderProgram::setVec4(const string& name, const Vector4& value) const
{
	float data[4] = { value.x,value.y,value.z,value.w };
	glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, data);
}


void ShaderProgram::setMat4(const string& name,const Matrix4x4& mat) const
{
	float data[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			data[i][j] = mat[j][i];
		}
	}
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &data[0][0]);
}