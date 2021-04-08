#include "ProjectState.h"

namespace SemperEngine
{
	namespace Core
	{
		ProjectState::State ProjectState::state = ProjectState::State::Original;

		bool ProjectState::close = false;
	}
}