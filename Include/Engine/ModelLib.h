#pragma once
#ifndef __MODELLIB__
#define __MODELLIB__

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容

#include <vector>
#include <string>

namespace SemperEngine
{
	namespace ModelLib
	{
		struct Float3
		{
			float x;

			float y;

			float z;
		};

		struct Float2
		{
			float x;

			float y;
		};

		struct Node
		{
			std::string name = "";

			std::vector<Node> children;

			Float3* vertices = nullptr;

			Float2* uv = nullptr;

			size_t size = 0;
		};

		struct Model
		{
			std::string path = "";

			Node root;

			std::string warning = "";

			std::string error = "";
		};

		Model LoadObject(std::string path);
	}
}
#endif // !__MODEL__