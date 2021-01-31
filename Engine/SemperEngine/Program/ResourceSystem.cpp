#include "ResourceSystem.h"
#include "ResourceObjectCenter.h"
#include "ResourceInternal.h"
#include "Resource.h"

namespace SemperEngine
{
	namespace Core
	{
		void ResourceSystem::Start()
		{
			ResourceInternal::PreLoad();
			ResourceObjectCenter::EndProcess();
		}

		void ResourceSystem::BeforeLoop()
		{
			Resource::DisposeUnuse();
			ResourceObjectCenter::EndProcess();
		}

		void ResourceSystem::Loop()
		{
			Resource::DisposeUnuse();
			ResourceObjectCenter::EndProcess();
		}

		void ResourceSystem::AfterLoop()
		{
			ResourceInternal::Dispose();
			Resource::DisposeUnuse();
			ResourceObjectCenter::EndProcess();
		}

		void ResourceSystem::EndProcess()
		{
			ResourceObjectCenter::EndProcess();
		}

		void ResourceSystem::DisposeUnused()
		{
			Resource::DisposeUnuse();
			ResourceObjectCenter::EndProcess();
		}

	}
}