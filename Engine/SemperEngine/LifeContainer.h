#pragma once
#ifndef LIFECONTAINER
#define LIFECONTAINER

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

			std::shared_ptr<unsigned int> id;

		public:
			LifeContainer(T* self)
			{
				this->self = self;
				this->life = std::shared_ptr<bool>(new bool(true));
				this->id = std::shared_ptr<unsigned int>(new unsigned int(0));
			}
			~LifeContainer()
			{}

		private:

		};
	}
}


#endif // !LIFECONTAINER
