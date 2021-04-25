#include "ProjectState.h"

namespace Semper
{
	namespace Core
	{
		ProjectState::State ProjectState::state = ProjectState::State::Original;

		bool ProjectState::close = false;
	}
}