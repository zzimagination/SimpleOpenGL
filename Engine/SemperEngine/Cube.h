#pragma once
#ifndef GAMEOBJECT_CUBE
#define GAMEOBJECT_CUBE

#include <memory>
#include "CubeData.h"
#include "RenderObject.h"
#include "GameObject.h"

namespace SemperEngine
{
	class Cube : public GameObject
	{
	private:

		CubeData _cubeData;

		std::unique_ptr<Core::RenderObject> _renderObject;

		std::shared_ptr<Material> _material;

	public:

		Cube();

		~Cube();

		virtual void Start() override;

		virtual void Update() override;

		virtual void End() override;

		void SetMaterial(std::shared_ptr<Material> material);
	};
}

#endif // !GAMEOBJECT_CUBE
