#ifndef SHADER_H
#define SHADER_H
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "Mathz.h"
namespace SemperEngine {

	using namespace std;

	constexpr const char* MODEL_MATRIX = "_model";
	constexpr const char* VIEW_MATRIX = "_view";
	constexpr const char* PROJECTION_MARIX = "_projection";
	constexpr const char* MAINCOLOR = "_color";

	class GraphicShader
	{
	public:

		string name;

		unsigned int ID;

	private:

		unsigned int _id;

		string _vertexShaderPath;

		string _fragmentShaderPath;

		string _geometryShaderPath;

	public:

		GraphicShader(unsigned int id);

		GraphicShader();

		~GraphicShader();

		GraphicShader(string vertexPath, string fragmentPath, string geometryPath = "");

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