#pragma once
#ifndef __MESH_OBJECT__
#define __MESH_OBJECT__

#include <array>
#include "Common.h"
#include "ResourceObject.h"
#include "Graphic.h"

namespace SemperEngine
{
	namespace Core
	{
		struct CubeData
		{
			static std::array<Float3, 24> vertices;

			static std::array<Float2, 24> uv;

			static std::array<int, 36> indices;
		};

		struct ScreenVertexData
		{
			static std::array<Float3, 4> vertices;

			static std::array<Float2, 4> uv;

			static std::array<int, 6> indices;
		};

		class MeshObject : public ResourceObject, public IGraphicResource
		{
		public:

			struct Setting
			{
				bool readOnly = false;
			};

		public:

			static MeshObject* Create();

			static MeshObject* CreateCube();

			static MeshObject* CreateRectangle();

		public:

			ArrayList<Float3> vertices;

			ArrayList<Float2> uv;

			ArrayList<int> index;

			GraphicDataInfo graphicDataInfo;

			bool graphicBind = false;

		public:

			MeshObject();

			virtual ~MeshObject() override;

			MeshObject* Copy();

		protected:

			virtual void EndDelete() override;

			virtual void EndModify() override;

		public:

			// Í¨¹ý IGraphicResource ¼Ì³Ð
			virtual void CreateGraphicResource() override;

			virtual void DeleteGraphicResource() override;

		};
	}
}

#endif // !__MESHOBJECT__
