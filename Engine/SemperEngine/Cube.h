#pragma once
#ifndef GAMEOBJECT_CUBE
#define GAMEOBJECT_CUBE

#include "GameObject.h"
#include "VertexData.h"
#include "ResourcePackage.h"
#include "RenderObject.h"

namespace SemperEngine
{
	class Cube : public GameObject
	{
	private:

		Core::ResourcePackage<Core::VertexData> _cube;

		std::unique_ptr<Core::RenderObject> _renderObject;

		std::unique_ptr<Material> _material;

	public:

		Cube();

		~Cube();

	public:

		virtual void Start() override;

		virtual void Update() override;

		virtual void End() override;

	};
}

#endif // !GAMEOBJECT_CUBE
