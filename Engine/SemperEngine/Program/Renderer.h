#ifndef RENDERER
#define RENDERER

#include "Component.h"
#include "RenderCustomObject.h"
#include <memory>
#include "Mesh.h"
#include "RenderLayer.h"

namespace SemperEngine
{
	class Renderer : public Component
	{
	private:

		std::unique_ptr<Core::RenderCustomObject> _object;

	public:

		Renderer();

		virtual ~Renderer() override;

		virtual void Start() override;

		virtual void Update() override;

		void SetMesh(std::shared_ptr<Mesh> mesh);

		std::shared_ptr<Mesh> GetMesh();

		void AddRenderLayer(int layer);

		RenderLayer GetRenderLayer();
	};
}

#endif // !RENDERER
