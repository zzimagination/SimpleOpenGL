#pragma once
#ifndef __CHANGECOLOR__
#define __CHANGECOLOR__

#include "Component.h"
#include "Material.h"
#include <memory>

using namespace Semper;

class ChangeColor : public Component
{
public:

	Color color;

	std::shared_ptr<Material> material;

	virtual void Update() override;
};

#endif // !__CHANGECOLOR__
