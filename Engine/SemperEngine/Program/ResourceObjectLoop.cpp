#include "ResourceObjectLoop.h"
#include "ResourceObjectCenter.h"
#include "ResourceInternal.h"
#include "Resource.h"

namespace SemperEngine
{
	namespace Core
	{
		void ResourceObjectLoop::Start()
		{
			ResourceInternal::PreLoad();
			ResourceObjectCenter::EndProcess();
		}

		void ResourceObjectLoop::BeforeLoop()
		{
			Resource::DisposeUnuse();
			ResourceObjectCenter::EndProcess();
		}

		void ResourceObjectLoop::Loop()
		{
			Resource::DisposeUnuse();
			ResourceObjectCenter::EndProcess();
		}

		void ResourceObjectLoop::AfterLoop()
		{
			ResourceInternal::Dispose();
			Resource::DisposeUnuse();
			ResourceObjectCenter::EndProcess();
		}

	}
}