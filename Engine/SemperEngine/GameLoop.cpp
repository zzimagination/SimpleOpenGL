#include "GameLoop.h"
#include <thread>
#include <iostream>
#include <string>
#include "Mathz.h"
#include "Debug.h"
#include "WorldLoop.h"
#include "GameWindow.h"
#include "EventSystem.h"
#include "FrameRuntime.h"
#include "GraphicRender.h"
#include "BaseRenderPipeline.h"
#include "GraphicCommandManager.h"
#include "VertexDataCenter.h"

namespace SemperEngine {

	namespace Core {

		bool GameLoop::_isLooping = true;

		CompletedSignal GameLoop::loopSignal;

		CompletedSignal GameLoop::mainSignal;

		CompletedSignal GameLoop::logicSignal;

		void GameLoop::BeforeLoop()
		{
			WorldLoop::BeforeLoop();
			BaseRenderPipeline::Render();
			GraphicCommandManager::SwapCommands();
			_isLooping = true;
		}

		void GameLoop::MainLoop()
		{
			thread logic(LogicLoop);
			while (_isLooping)
			{
				/*����Ƿ����ѭ��*/
				if (ExitLoop())
				{
					loopSignal.Send(Exit);
					break;
				}
				else
				{
					loopSignal.Send();
				}
				/*֡ǰ����*/
				FrameRuntime::BeginFrame();
				GameWindow::PollWindowEvent();
				/*���Ϳ�ʼ����*/
				mainSignal.Send();
				/*���߳�ִ��*/

				GraphicRender::Render();
				GameWindow::SwapFrameBuffers();
				/*�ȴ������߳�ִ�����*/
				logicSignal.Wait();
				/*֡����*/

				GraphicCommandManager::SwapCommands();
				FrameRuntime::EndFrame();
			}
			logic.join();
		}

		void GameLoop::AfterLoop()
		{
			WorldLoop::AfterLoop();
		}

		void GameLoop::LogicLoop()
		{
			while (_isLooping)
			{
				/*����Ƿ����ѭ��*/
				if (loopSignal.Wait() == Exit)
				{
					break;
				}
				/*�ȴ���ʼ����*/
				mainSignal.Wait();
				/*������Ϸ�߼�*/
				EventSystem::ProcessEvent();
				WorldLoop::Loop();
				BaseRenderPipeline::Render();
				VertexDataCenter::UnloadNoUse();
			
				EventSystem::EndEvents();
				/*�����������*/
				logicSignal.Send();
			}
		}

		bool GameLoop::ExitLoop()
		{
			bool isExit = GameWindow::WindowShouldClose();
			_isLooping = !isExit;
			return isExit;
		}
	}
}