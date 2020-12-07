#pragma once

#include <string>
#include <vector>
#include <memory>

using namespace std;

class GLHelper
{
public:

	static vector<float> points;

	static string vertexShader;

	static string fragmentShader;

	static unsigned int CompileShader(string vert, string frag);

	static unsigned int GetVertex(vector<float> points);

	static void DrawLine();
};

