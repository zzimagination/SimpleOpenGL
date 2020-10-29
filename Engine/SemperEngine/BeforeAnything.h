#pragma once
#ifndef __BEFOREANYTHING__
#define __BEFOREANYTHING__

#include "LogoCollection.h"

namespace SemperEngine
{
	class BeforeAnything
	{
	public:

		static void Start()
		{
			LogoCollection::AddLogoImage("Resources/Textures/logo2.png");
		}
	};
}
#endif // !__BEFOREANYTHING__
