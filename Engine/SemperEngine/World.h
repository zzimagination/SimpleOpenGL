#pragma once
#ifndef __WORLD_SCRIPT__
#define __WORLD_SCRIPT__

#include <vector>
#include <memory>
#include <string>
#include "ObjectIndex.h"

namespace SemperEngine {

	namespace Core
	{
		class WorldMachine;
	}



	class World
	{
	public:

		Core::ObjectIndex treeIndex1;

	private:

		std::string _name;

		int _id;

	public:

		World();

		World(std::string name, int id);

		~World();

		std::string Name();

		int ID();

		bool operator== (const World &world);

		bool operator!= ( const World &world);
	};





}
#endif // !WORLD_SCRIPT
