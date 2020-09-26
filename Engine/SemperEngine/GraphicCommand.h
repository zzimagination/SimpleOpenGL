#pragma once
#ifndef GRAPHICCOMMAND
#define GRAPHICCOMMAND

namespace SemperEngine
{
	namespace Core
	{
		class GraphicCommand
		{
		public:

			virtual void Excute() = 0;
		};
	}
}

#endif