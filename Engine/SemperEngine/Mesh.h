#pragma once
#ifndef __MESH__
#define __MESH__

#include <memory>
#include "MeshObject.h"

namespace SemperEngine
{
	class Mesh
	{
	public:

		std::shared_ptr<Core::MeshObject> object;

	public:

		Mesh();

		~Mesh();

		Mesh* Copy();
	};
}

#endif // !MESH
