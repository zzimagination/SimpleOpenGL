#ifndef __RENDERBATCH__
#define __RENDERBATCH__

#include <vector>
#include <memory>
#include "Mathz.h"
#include "Mesh.h"
#include "Material.h"
#include "Graphic.h"
#include "Render.h"

namespace SemperEngine {

	namespace Core
	{
		class RenderBatch
		{
		public:

			enum class VertexType
			{
				Custom,

				Screen
			};

		private:

			VertexType _vertexType = VertexType::Custom;

			std::shared_ptr<Mesh> _mesh;

			RenderMatrix _renderMatrix;

			std::shared_ptr<Material> _material;

		public:

			void SetVertexType(VertexType type);

			VertexType GetVertexType();

			void SetMesh(std::shared_ptr<Mesh> mesh);

			GraphicVertexInfo GetGraphicVertexInfo();

			void SetModelMatrix(Matrix4x4 mat4);

			void SetViewMatrix(Matrix4x4 mat4);

			void SetProjectionMatrix(Matrix4x4 mat4);

			RenderMatrix GetRenderMatrix();

			void SetMaterial(std::shared_ptr<Material> material);

			std::shared_ptr<Material> GetMaterial();

			std::vector<GraphicTextureInfo> GetGraphicTextureInfos();
		};
	}
}
#endif // !RENDERBATCH




