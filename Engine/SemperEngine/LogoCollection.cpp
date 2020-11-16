#include "LogoCollection.h"

namespace SemperEngine
{
	std::vector<std::string> LogoCollection::files;

	void LogoCollection::AddLogoImage(std::string file)
	{
		files.push_back(file);
	}
	int LogoCollection::Count()
	{
		return files.size();
	}
}