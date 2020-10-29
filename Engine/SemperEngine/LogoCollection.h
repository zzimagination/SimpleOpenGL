#pragma once
#ifndef __LOGO_COLLECTION__
#define __LOGO_COLLECTION__

#include <string>
#include <vector>

namespace SemperEngine
{
	namespace Core {
		class LogoPipeline;
	}
	class LogoCollection
	{
	private:

		static std::vector<std::string> _files;

	public:

		static void AddLogoImage(std::string file);

		static int Count();

		friend class Core::LogoPipeline;
	};
}

#endif // !__LOGO_COLLECTION__
