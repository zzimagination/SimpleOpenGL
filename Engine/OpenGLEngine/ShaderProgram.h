#ifndef SHADER_H
#define SHADER_H
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "Mathz.h"
namespace SemperEngine {
#define MODEL_MATRIX "_model"
#define VIEW_MATRIX "_view"
#define PROJECTION_MARIX "_projection"

	using namespace std;

	class ShaderProgram
	{

	public:

		string name;

		unsigned int ID;

	private:

		string _vertexShaderPath;

		string _fragmentShaderPath;

		string _geometryShaderPath;

	public:

		ShaderProgram();

		~ShaderProgram();

		ShaderProgram(string vertexPath, string fragmentPath, string geometryPath = "");

	public:

		void Use();
		void Apply();
		void SetValue(const string& name, bool value) const;
		void SetValue(const string& name, int value) const;
		void SetValue(const string& name, float value) const;
		void SetValue(const string& name, const Vector2& value) const;
		void SetValue(const string& name, const Vector3& value) const;
		void SetValue(const string& name, const Vector4& value) const;
		void SetValue(const string& name, const Matrix4x4& mat) const;
	};
}
#endif