#pragma once
#ifndef __MESH_OBJECT__
#define __MESH_OBJECT__

#include "ResourceObject.h"
#include "ResourcePackage.h"
#include "VertexData.h"
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

			ResourcePackage<VertexData> resourcePackage;

			GraphicDataInfo graphicDataInfo;

		public:

			MeshObject();

			MeshObject(bool share);

			MeshObject(bool share, Setting setting);

			virtual ~MeshObject() override;
		};
	}
}

#endif // !__MESHOBJECT__
