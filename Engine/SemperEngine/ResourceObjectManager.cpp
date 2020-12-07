#include "ResourceObjectManager.h"
#include "ResourceObjectCenter.h"
#include "ResourceInternal.h"

namespace SemperEngine
{
	namespace Core
	{
		void ResourceObjectManager::PreLoad()
		{
			ResourceInternal::PreLoad();
			ResourceObjectCenter::DeleteObjects();
			ResourceObjectCenter::NewObjects();
		}
		void ResourceObjectManager::EndProcess()
		{
			ResourceObjectCenter::DeleteObjects();
			ResourceObjectCenter::NewObjects();
		}
		void ResourceObjectManager::Dispose()
		{
			ResourceInternal::Dispose();
			ResourceObjectCenter::DeleteObjects();
		}
	}
}