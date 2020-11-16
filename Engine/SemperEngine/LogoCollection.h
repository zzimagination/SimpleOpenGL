#pragma once
#ifndef __LOGO_COLLECTION__
#define __LOGO_COLLECTION__

#include <string>
#include <vector>

namespace SemperEngine
{
	class LogoCollection
	{
	public:

		static std::vector<std::string> files;

	public:

		static void AddLogoImage(std::string file);

		static int Count();
	};
}

#endif // !__LOGO_COLLECTION__
