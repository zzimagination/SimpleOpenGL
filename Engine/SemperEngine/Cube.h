#pragma once
#ifndef __GAMEOBJECT_CUBE__
#define __GAMEOBJECT_CUBE__

#include "GameObject.h"
#include "VertexData.h"
#include "ResourcePackage.h"
#include "RenderObject.h"

namespace SemperEngine
{
	class Cube : public GameObject
	{
	public:

		std::shared_ptr<Material> material;

	private:

		Core::ResourcePackage<Core::VertexData> _cube;

		std::unique_ptr<Core::RenderObject> _renderObject;

	public:

		Cube();

		virtual ~Cube() override;

	public:

		virtual void Start() override;

		virtual void Update() override;

		virtual void End() override;

	};
}

#endif // !GAMEOBJECT_CUBE
