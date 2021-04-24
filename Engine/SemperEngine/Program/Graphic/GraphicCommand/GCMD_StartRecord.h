#ifndef __GCMD_STARTRECORD__
#define __GCMD_STARTRECORD__

#include "../GraphicCommand.h"

namespace SemperEngine
{
	namespace Core
	{
		class GCMD_StartRecord : public GraphicCommand
		{
		public:

			GraphicRecord* record = nullptr;

		public:

			GCMD_StartRecord(GraphicRecord* record);

			virtual ~GCMD_StartRecord() override;

			// Í¨¹ý GraphicCommand ¼Ì³Ð
			virtual void Excute() override;

		};
	}
}

#endif // !__GCMD_STARTRECORD__
