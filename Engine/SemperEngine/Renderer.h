#ifndef RENDERER
#define RENDERER

#include <vector>
#include "Mathz.h"
#include "Component.h"
#include "Material.h"

namespace SemperEngine {

	class RenderObject;
	class Material;
	class GameObject;
	class Transform;

	class Renderer : public Component
	{
	protected:

		std::vector<RenderObject*> _renderObjects;

	public:

		Renderer();

		~Renderer();

	public:

		std::vector<RenderObject*> GetRenderObjects();

	protected:

		void AddToCollection();

		void RemoveFromCollection();

		virtual void GenerateRenderObject() = 0;

		virtual void UpdateRenderObject() = 0;

		virtual void DeleteRenderObject() = 0;
	};
}

#endif // !RENDER