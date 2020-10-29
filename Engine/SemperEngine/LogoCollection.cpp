#include "LogoCollection.h"

namespace SemperEngine
{
	std::vector<std::string> LogoCollection::_files;

	void LogoCollection::AddLogoImage(std::string file)
	{
		_files.push_back(file);
	}
	int LogoCollection::Count()
	{
		return _files.size();
	}
}