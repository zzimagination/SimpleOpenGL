#pragma once
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


class Shader
{
public:
	std::string name;
    // 程序ID
    unsigned int ID;
    // 构造器读取并构建着色器
	Shader();

	Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);

    // 使用/激活程序
    void use();

    // uniform工具函数

	void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
    void setFloat4(const std::string& name, float x, float y, float z, float w) const;
    void setVec2(const std::string& name, const glm::vec2& value) const;
    void setVec2(const std::string& name, float x, float y) const;
    void setVec3(const std::string& name, const glm::vec3& value) const;
    void setVec3(const std::string& name, float x, float y, float z) const;
    void setVec4(const std::string& name, const glm::vec4& value) const;
    void setVec4(const std::string& name, float x, float y, float z, float w) const;
    void setMat2(const std::string& name, const glm::mat2& mat) const;
    void setMat3(const std::string& name, const glm::mat3& mat) const;
    void setMat4(const std::string& name, const glm::mat4& mat) const;

};
#endif