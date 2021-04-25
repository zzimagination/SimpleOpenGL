#pragma once
#ifndef __MESH__
#define __MESH__

#include <memory>
#include "Common.h"
#include "MeshObject.h"

namespace Semper
{
	class Mesh : public Core::IResourceTarget
	{
	private:

		Core::MeshObject* _object;

	public:

		Mesh();

		Mesh(Core::MeshObject* obj);

		~Mesh();

		Mesh* Copy();

		ArrayList<Float3> GetVertices();

		void SetVertices(ArrayList<Float3> vertices);


		// Í¨¹ý IResourceTarget ¼Ì³Ð
		virtual Core::ResourceObject* GetObject() override;

	};
}

#endif // !MESH
