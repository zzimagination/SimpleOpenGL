#ifndef __MODEL__
#define __MODEL__

#include "ModelObject.h"
#include "Mesh.h"

namespace SemperEngine
{
	class Model
	{
	public:

		Core::ModelObject* object;

	public:

		Model(Core::ModelObject* object);

		~Model();

		std::shared_ptr<Mesh> GetMesh();
	};
}

#endif // !__MODEL__
