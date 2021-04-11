#include "DepthSection.h"
#include "../../CameraCollection.h"
#include "../../RenderCollection.h"
#include "../RenderBatchManager.h"
#include "../RenderRecordManager.h"
#include <memory>

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;


		DepthSection::~DepthSection()
		{
		}

		void DepthSection::Prepare()
		{
			if (_material != nullptr)
			{
				delete _material;
				_material = nullptr;
			}
		}

		void DepthSection::Start()
		{
			auto batch = shared_ptr<ClearBatch>(new ClearBatch(Color::Color32(0, 0, 0), ClearColorDepth));
			RenderBatchManager::AddBatch(batch);

			auto distance = Math::Abs(camera->far - camera->near);
			_material = new Material("Depth");
			_material->AddProperty("_NFDis", distance);

			auto objects = RenderCollection::GetCustomObjects(camera->layer);
			for (auto object = objects.begin(); object != objects.end(); object++)
			{
				auto batch = shared_ptr<CustomRenderBatch>(new CustomRenderBatch);
				batch->camera = camera;
				batch->model = (*object)->modelMat;
				batch->mesh = (*object)->mesh.get();
				batch->material = _material;
				RenderBatchManager::AddBatch(batch);
			}
		}
	}
}