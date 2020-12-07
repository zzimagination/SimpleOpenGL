#pragma once
#ifndef __WORLD_SCRIPT__
#define __WORLD_SCRIPT__

#include <string>
#include "GameObject.h"

namespace SemperEngine
{
	class World
	{
	public:

		static std::string GetInside();

		static std::string GetActive();

		static void SetActive(std::string name);

		static bool Inside();

		static void AddGameObject(std::string world, GameObject* gameObject);

	};
}

#endif // !WORLD_SCRIPT
