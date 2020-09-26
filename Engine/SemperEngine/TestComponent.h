#ifndef TEST_COMPONENT
#define TEST_COMPONENT

#include "SemperEngine.h"
#include "GameObject.h"

namespace SemperEngine
{
	class TestComponent : public SemperEngine::Component {

	public:

		TestComponent();
		// Í¨¹ý Component ¼Ì³Ð
		virtual void Start() override;

		virtual void Update() override;

		virtual void End() override;

	};
}
#endif // !TEST_COMPONENT
