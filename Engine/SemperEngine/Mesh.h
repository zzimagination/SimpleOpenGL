#pragma once
#ifndef __MESH__
#define __MESH__

#include "VertexData.h"
#include "ResourcePackage.h"

namespace SemperEngine
{
	class Mesh
	{
	private:

		Core::ResourcePackage<Core::VertexData> _package;

	public:

		Mesh();

		Mesh(Core::ResourcePackage<Core::VertexData> package);

		~Mesh();

		Core::ResourcePackage<Core::VertexData> Package();
	};
}

#endif // !MESH
