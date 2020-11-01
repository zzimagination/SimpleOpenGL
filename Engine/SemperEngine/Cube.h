#pragma once
#ifndef __GAMEOBJECT_CUBE__
#define __GAMEOBJECT_CUBE__

#include "GameObject.h"
#include "Mesh.h"
#include "RenderObject.h"

namespace SemperEngine
{
	class Cube : public GameObject
	{
	public:

		std::shared_ptr<Material> material;

	private:

		std::shared_ptr<Mesh> _cube;

		std::unique_ptr<Core::RenderObject> _renderObject;

	public:

		Cube();

		virtual ~Cube() override;

		virtual void Start() override;

		virtual void Update() override;

		RenderLayer GetRenderLayer();

		void AddRenderLayer(int layer);
	};
}

#endif // !GAMEOBJECT_CUBE
