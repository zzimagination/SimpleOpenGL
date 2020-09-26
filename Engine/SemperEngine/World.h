#pragma once
#ifndef WORLD_SCRIPT
#define WORLD_SCRIPT

#include <vector>

namespace SemperEngine {

	namespace Core
	{
		class WorldMachine;
	}



	class World
	{
	public:

		unsigned int treeID;

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
