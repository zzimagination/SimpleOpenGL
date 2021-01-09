#pragma once
#ifndef __MESH__
#define __MESH__

#include <memory>
#include "Common.h"
#include "MeshObject.h"

namespace SemperEngine
{
	class Mesh
	{
	private:

		Core::MeshObject* _object;

	public:

		Mesh();

		Mesh(Core::MeshObject* obj);

		~Mesh();

		Core::MeshObject* GetObject();

		Mesh* Copy();

		ArrayList<Float3> GetVertices();

		void SetVertices(ArrayList<Float3> vertices);
	};
}

#endif // !MESH
