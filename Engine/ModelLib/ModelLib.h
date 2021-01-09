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
		struct Model
		{
			std::string name;

			std::vector<Model> children;

			std::vector<float> vertices;

			std::vector<float> uv;

			std::string warning;

			std::string error;
		};

		Model LoadObject(std::string path);
	}
}
#endif // !__MODEL__