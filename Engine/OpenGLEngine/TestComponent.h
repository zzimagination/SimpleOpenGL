#ifndef TEST_COMPONENT
#define TEST_COMPONENT

#include "SemperEngine.h"

class TestComponent : public SemperEngine::Component {

public:
	// ͨ�� Component �̳�
	virtual void Start() override;

	virtual void Update() override;

	virtual void OnDestory() override;

};

#endif // !TEST_COMPONENT
