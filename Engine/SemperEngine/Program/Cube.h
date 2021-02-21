#pragma once
#ifndef __GAMEOBJECT_CUBE__
#define __GAMEOBJECT_CUBE__

#include "GameObject.h"
#include "Mesh.h"
#include "RenderCustomObject.h"
#include "Material.h"

namespace SemperEngine
{
	class Cube : public GameObject
	{
	private:

		std::unique_ptr<Core::RenderCustomObject> _renderObject;

	public:

		Cube();

		virtual ~Cube() override;

		virtual void Start() override;

		virtual void Update() override;

		RenderLayer GetRenderLayer();

		void AddRenderLayer(int layer);

		std::shared_ptr<Mesh> GetMesh();

		std::shared_ptr<Material> GetMaterial();

		void SetMaterial(std::shared_ptr<Material> mat);
	};
}

#endif // !GAMEOBJECT_CUBE
