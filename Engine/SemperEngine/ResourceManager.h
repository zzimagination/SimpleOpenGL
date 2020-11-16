#pragma once
#ifndef __RESOURCE_MANAGER__
#define __RESOURCE_MANAGER__

#include <string>
#include <map>

namespace SemperEngine
{
	namespace Core
	{
		constexpr const char* WHITE_TEXTURE = "White";
		constexpr const char* BLACK_TEXTURE = "Black";
		constexpr const char* BUMP_TEXTURE = "Bump";

		class ResourceManager
		{
		public:

			static void PreLoad();

			static void AddAndDelete();

		private:

			static void PreLoadTexture();

			static void LoadInternalTexture(std::string name);

			static void PreLoadMesh();

		};
	}
}

#endif // !RESOURCE_MANAGER
