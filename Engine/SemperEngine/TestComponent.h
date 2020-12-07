#ifndef __TEST_COMPONENT__
#define __TEST_COMPONENT__

#include "BeautifulWorld.h"

namespace SemperEngine
{
	class TestComponent : public SemperEngine::Component {

	public:

		virtual ~TestComponent() override;
		// ͨ�� Component �̳�
		virtual void Start() override;

		virtual void Update() override;

	};
}
#endif // !TEST_COMPONENT
