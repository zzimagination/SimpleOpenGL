#define UNLITSECTION "Unlit"
#define DEPTHSECTION "Depth"

#ifndef __RENDER__
#define __RENDER__

namespace SemperEngine
{
	class Render
	{
	public:
		enum class MSAA
		{
			m4,
			m8,
			m16
		};
	};
}

#endif // !__RENDER__
