#pragma once
#ifndef __MESH__
#define __MESH__

#include <memory>
#include "MeshObject.h"
#include "ArrayList.h"

namespace SemperEngine
{
	class Mesh
	{
	public:

		Core::MeshObject* object;

	public:

		Mesh();

		Mesh(Core::MeshObject* obj);

		~Mesh();

		Mesh* Copy();

		ArrayList<Float3> GetVertices();

		void SetVertices(ArrayList<Float3> vertices);
	};
}

#endif // !MESH
