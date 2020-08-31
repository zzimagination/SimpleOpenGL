#ifndef RENDERER
#define RENDERER
#include "Cube.h"
#include "Component.h"

namespace SemperEngine {

	class RenderObject;
	class Material;
	class GameObject;
	class Transform;

	using namespace std;

	class Renderer : public Component
	{
	private:

		Cube cube;

		Material* _material;

	public:

		Renderer();

		~Renderer();

		virtual void Start() override;

		virtual void Update() override;

		virtual void End() override;

	private:

		RenderObject* _renderObject;

	public:

		void Collect();

		void Drop();

		virtual Material* GetMaterial();

		virtual void SetMaterial(Material *material);

		RenderObject* GetRenderObject();

	private:

		virtual void GenerateRenderObject();

		virtual void UpdateRenderObject();

		virtual void DeleteRenderObject();
	};
}

#endif // !RENDER