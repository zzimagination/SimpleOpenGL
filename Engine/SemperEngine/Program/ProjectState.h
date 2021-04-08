#ifndef __PROJECT_STATE__
#define __PROJECT_STATE__

namespace SemperEngine
{
	namespace Core
	{
		class ProjectState
		{
		public:

			enum class State
			{
				Original,

				Start,

				Loop,

				End
			};

		public:

			static State state;

			static bool close;
		};
	}
}

#endif // !__PROJECT_STATE__
