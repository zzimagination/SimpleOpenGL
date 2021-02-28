#ifndef __RENDERBATCH__
#define __RENDERBATCH__

#include <vector>
#include <memory>
#include "Common.h"
#include "Mesh.h"
#include "Material.h"
#include "Graphic.h"
#include "Render.h"
#include "CameraObject.h"

namespace SemperEngine {

	namespace Core
	{
		class RenderBatch
		{
		public:

			static GraphicVertexInfo GetVertexInfo(Mesh* mesh);

			static RenderMatrix GetRenderMatrix(Matrix4x4 model, CameraObject* camera);

			static RenderOperation GetOperation(Material* material);

			static ShaderProperty GetShaderProperty(Material* material);

			static std::vector<GraphicTextureInfo> GetTextures(Material* material);

		public:

			virtual ~RenderBatch();

			virtual void GenerateGraphicResource();

			virtual void RenderGraphicObject();


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

		class ClearBatch : public RenderBatch
		{
		public:

			Color clearColor;

			Graphic::ClearMode clearMode;

		public:

			ClearBatch(Color color, Graphic::ClearMode mode);

			virtual ~ClearBatch() override;

			virtual void RenderGraphicObject() override;
		};

		class CustomRenderBatch : public RenderBatch
		{
		public:

			Mesh* mesh;

			CameraObject* camera;

			Material* material;

			Matrix4x4 model;

		public:

			virtual ~CustomRenderBatch() override;

			virtual void RenderGraphicObject() override;

			virtual void GenerateGraphicResource() override;
		};
	}
}
#endif // !RENDERBATCH




