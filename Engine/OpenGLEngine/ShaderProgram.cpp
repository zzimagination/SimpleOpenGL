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
	vShaderFile.open(vertexPath);
	fShaderFile.open(fragmentPath);
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
	// ��ɫ������
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	if (geometryPath != nullptr)
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


void ShaderProgram::setMat4(const string& name, const Matrix4x4& mat) const
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

	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &data[0][0]);
}