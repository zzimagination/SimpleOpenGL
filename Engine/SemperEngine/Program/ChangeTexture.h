#pragma once
#ifndef __CHANGETEXTURE__
#define __CHANGETEXTURE__

#include "Component.h"
#include "Texture.h"
#include <memory>

using namespace Semper;

class ChangeTexture : public Component
{
public:

	Color color;

	std::shared_ptr<Texture> texture;

	virtual void Update() override;
};

#endif // !__CHANGETEXTURE__
