#pragma once
#ifndef __MESH_OBJECT__
#define __MESH_OBJECT__

#include "Common.h"
#include "ResourceObject.h"
#include "ResourcePackage.h"
#include "Graphic.h"

namespace SemperEngine
{
	namespace Core
	{
		class MeshObject : public ResourceObject
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

			ResourcePackage<VertexData> resourcePackage;

			GraphicDataInfo graphicDataInfo;

		public:

			MeshObject();

			virtual ~MeshObject() override;

			virtual void EndCreate() override;

			virtual void EndDelete() override;

			virtual void EndModify() override;

			MeshObject* Copy();

			void SetVertex(ArrayList<Float3> vertices);

			ArrayList<Float3> GetVertex();
		};
	}
}

#endif // !__MESHOBJECT__
