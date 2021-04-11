#include "UnlitSection.h"
#include "../../CameraCollection.h"
#include "../../RenderCollection.h"
#include "../RenderBatchManager.h"
#include "../RenderRecordManager.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		UnlitSection::~UnlitSection()
		{
		}

		void UnlitSection::Prepare()
		{
		}

		void UnlitSection::Start()
		{
			auto clear = shared_ptr<ClearBatch>(new ClearBatch(Color::Black(), ClearColorDepth));
			RenderBatchManager::AddBatch(clear);

			auto objects = RenderCollection::GetCustomObjects(camera->layer);
			for (auto object = objects.begin(); object != objects.end(); object++)
			{
				auto RO = (*object);
				auto batch = shared_ptr<CustomRenderBatch>(new CustomRenderBatch);
				batch->camera = camera;
				batch->model = RO->modelMat;
				batch->mesh = RO->mesh.get();
				batch->material = RO->material.get();
				batch->records.push_back(RenderRecord(camera, DEPTHSECTION));
				RenderBatchManager::AddBatch(batch);
			}
		}
	}
}