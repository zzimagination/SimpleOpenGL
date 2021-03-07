#ifndef __GCMD_CLEARRECORD__
#define __GCMD_CLEARRECORD__
#include "../../GraphicCommand.h"
namespace SemperEngine
{
	namespace Core
	{
		class GCMD_ClearRecord : public GraphicCommand
		{
		public:

			GraphicRecord* record = nullptr;

		public:

			virtual ~GCMD_ClearRecord() override;

			virtual void Excute() override;
		};
	}
}
#endif // !__GCMD_CLEARRECORD__
