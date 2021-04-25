#ifndef __TEST_COMPONENT__
#define __TEST_COMPONENT__

#include <vector>
#include "GameObject.h"
#include "Component.h"

namespace Semper
{
	class TestComponent : public Component 
	{
	public:

		float y = 0;

		std::vector<GameObject*> objects;

	public:

		virtual ~TestComponent() override;
		// ͨ�� Component �̳�
		virtual void Start() override;

		virtual void Update() override;

	};
}
#endif // !TEST_COMPONENT
