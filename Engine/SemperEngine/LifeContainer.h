#pragma once
#ifndef __LIFECONTAINER__
#define __LIFECONTAINER__

#include <memory>

namespace SemperEngine
{
	namespace Core
	{
		template<class T>
		class LifeContainer
		{
		public:

			T* self;

			std::shared_ptr<bool> life;

		public:

			LifeContainer()
			{
				life = std::shared_ptr<bool>(new bool(false));
			}

			LifeContainer(T* self)
			{
				this->self = self;
				this->life = std::shared_ptr<bool>(new bool(true));
			}
			~LifeContainer()
			{}

		private:

		};
	}
}


#endif // !LIFECONTAINER
