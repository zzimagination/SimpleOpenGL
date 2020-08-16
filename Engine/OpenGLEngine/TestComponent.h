#ifndef TEST_COMPONENT
#define TEST_COMPONENT

#include "SemperEngine.h"

class TestComponent : public SemperEngine::Component {

public:
	// Í¨¹ý Component ¼Ì³Ð
	virtual void Start() override;

	virtual void Update() override;

	virtual void OnDestory() override;

};

#endif // !TEST_COMPONENT
