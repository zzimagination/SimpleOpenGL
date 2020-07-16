#ifndef SHADER_H
#define SHADER_H
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "Mathz.hpp"


#define MODEL_MATRIX "_model"
#define VIEW_MATRIX "_view"
#define PROJECTION_MARIX "_projection"

using namespace std;

class ShaderProgram
{
public:

	ShaderProgram();

	~ShaderProgram();

	ShaderProgram(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);

public:

	string name;

    unsigned int ID;

public:

    void use();

	void setBool(const string& name, bool value) const;
    void setInt(const string& name, int value) const;
    void setFloat(const string& name, float value) const;

    void setVec2(const string& name, const Vector2& value) const;
    void setVec3(const string& name, const Vector3& value) const;
    void setVec4(const string& name, const Vector4& value) const;

    void setMat4(const string& name, const Matrix4x4& mat) const;

};
#endif