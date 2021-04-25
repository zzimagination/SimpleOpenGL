#ifndef __MODELOBJECT__
#define __MODELOBJECT__

#include <vector>
#include "ResourceObject.h"
#include "MeshObject.h"

namespace Semper
{
	namespace Core
	{
		class ModelObject : public ResourceObject
		{
		public:

			struct Node
			{
				MeshObject* mesh = nullptr;

				std::vector<Node> children;
			};

		public:

			Node root;

		public:

			virtual ~ModelObject() override;

			virtual void OnUse() override;

			virtual void OnDispose() override;

			MeshObject* GetMeshObject();

			MeshObject* GetMeshObject(std::string name);

		private:

			void UseMesh(Node& node);

			void DisposeMesh(Node& node);
		};
	}
}


#endif // !__MODELOBJECT__
