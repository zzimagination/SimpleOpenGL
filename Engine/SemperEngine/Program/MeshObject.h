#pragma once
#ifndef __MESH_OBJECT__
#define __MESH_OBJECT__

#include "Common.h"
#include "ResourceObject.h"
#include "Graphic.h"

namespace SemperEngine
{
	namespace Core
	{
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

			std::string name;

			std::unique_ptr<VertexData> data;

			GraphicDataInfo graphicDataInfo;

			bool graphicBind = false;

		public:

			MeshObject();

			virtual ~MeshObject() override;

			MeshObject* Copy();

			void SetVertex(ArrayList<Float3> vertices);

			ArrayList<Float3> GetVertex();

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
