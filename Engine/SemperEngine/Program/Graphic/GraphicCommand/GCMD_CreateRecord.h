#ifndef __GCMD_CREATERECORD__
#define __GCMD_CREATERECORD__

#include "../GraphicCommand.h"

namespace Semper
{
	namespace Core
	{
		class GCMD_CreateRecord : public GraphicCommand
		{
		public:

			GraphicRecord* record = nullptr;

		public:

			GCMD_CreateRecord(GraphicRecord* record);

			virtual ~GCMD_CreateRecord() override;

			virtual void Execute() override;
		};
	}
}
#endif // !__GCMD_CREATERECORD__
