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
		// Í¨¹ý Component ¼Ì³Ð
		virtual void Start() override;

		virtual void Update() override;

	};
}
#endif // !TEST_COMPONENT
