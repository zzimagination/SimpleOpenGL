#include "ShaderProgram.h"
#include <glad/glad.h>

using namespace std;

ShaderProgram::ShaderProgram() {}

ShaderProgram::~ShaderProgram()
{
	//glDeleteProgram(ID);
}

ShaderProgram::ShaderProgram(string vertexPath, string fragmentPath, string geometryPath)
{
	_vertexShaderPath = vertexPath;
	_fragmentShaderPath = fragmentPath;
	_geometryShaderPath = geometryPath;
}

void ShaderProgram::Use()
{
	glUseProgram(ID);
}

void ShaderProgram::Apply()
{
	// 1. ���ļ�·���л�ȡ����/Ƭ����ɫ��
	string vertexCode;
	string fragmentCode;
	string geometryCode;
	ifstream vShaderFile;
	ifstream fShaderFile;
	ifstream gShaderFile;
	// ��֤ifstream��������׳��쳣��
	vShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
	fShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
	gShaderFile.exceptions(ifstream::failbit | ifstream::badbit);

	// ���ļ�
	vShaderFile.open(_vertexShaderPath);
	fShaderFile.open(_fragmentShaderPath);
	stringstream vShaderStream, fShaderStream;
	// ��ȡ�ļ��Ļ������ݵ���������
	vShaderStream << vShaderFile.rdbuf();
	fShaderStream << fShaderFile.rdbuf();
	// �ر��ļ�������
	vShaderFile.close();
	fShaderFile.close();
	// ת����������string
	vertexCode = vShaderStream.str();
	fragmentCode = fShaderStream.str();
	if (_geometryShaderPath != "")
	{
		gShaderFile.open(_geometryShaderPath);
		std::stringstream gShaderStream;
		gShaderStream << gShaderFile.rdbuf();
		gShaderFile.close();
		geometryCode = gShaderStream.str();
	}

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();

	// 2. ������ɫ��
	unsigned int vertex, fragment;
	int success;
	char infoLog[512];

	// ������ɫ��
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	// ��ӡ�����������еĻ���
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	};

	//Ƭ����ɫ��
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
	if (_geometryShaderPath != "")
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
	// ��ɫ������
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	if (_geometryShaderPath != "")
		glAttachShader(ID, geometry);
	glLinkProgram(ID);

	// ��ӡ���Ӵ�������еĻ���
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	// ɾ����ɫ���������Ѿ����ӵ����ǵĳ������ˣ��Ѿ�������Ҫ��
	glDeleteShader(vertex);
	glDeleteShader(fragment);
	if (_geometryShaderPath != "")
	{
		glDeleteShader(geometry);
	}
}

void ShaderProgram::SetValue(const string& name, bool value) const
{
	auto local = glGetUniformLocation(ID, name.c_str());
	glUniform1i(local, (int)value);
}

void ShaderProgram::SetValue(const string& name, int value) const
{
	auto local = glGetUniformLocation(ID, name.c_str());
	glUniform1i(local, value);
}

void ShaderProgram::SetValue(const string& name, float value) const
{
	auto local = glGetUniformLocation(ID, name.c_str());
	glUniform1f(local, value);
}

void ShaderProgram::SetValue(const string& name, const Vector2& value) const
{
	float data[2] = { value.x,value.y };
	auto local = glGetUniformLocation(ID, name.c_str());
	glUniform2fv(local, 1, data);
}

void ShaderProgram::SetValue(const string& name, const Vector3& value) const
{
	float data[3] = { value.x, value.y,value.z };
	auto local = glGetUniformLocation(ID, name.c_str());
	glUniform3fv(local, 1, data);
}

void ShaderProgram::SetValue(const string& name, const Vector4& value) const
{
	float data[4] = { value.x,value.y,value.z,value.w };
	auto local = glGetUniformLocation(ID, name.c_str());
	glUniform4fv(local, 1, data);
}

void ShaderProgram::SetValue(const string& name, const Matrix4x4& mat) const
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
	auto local = glGetUniformLocation(ID, name.c_str());
	glUniformMatrix4fv(local, 1, GL_FALSE, &data[0][0]);
}