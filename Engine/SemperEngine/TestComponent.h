#ifndef TEST_COMPONENT
#define TEST_COMPONENT

#include "BeautifulWorld.h"

namespace SemperEngine
{
	class TestComponent : public SemperEngine::Component {

	public:

		TestComponent();
		// ͨ�� Component �̳�
		virtual void Start() override;

		virtual void Update() override;

		virtual void End() override;

	};
}
#endif // !TEST_COMPONENT
