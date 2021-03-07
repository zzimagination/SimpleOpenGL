#include "RenderSection.h"
#include "../../CameraCollection.h"
#include "../../RenderCollection.h"

#include "../../RenderBatchManager.h"
#include "../RenderRecordManager.h"
#include "../../ResourceInternal.h"

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
			_cameras = CameraCollection::GetCameras();
		}

		void UnlitSection::Start()
		{
			for (auto c = _cameras.begin(); c < _cameras.end(); c++)
			{
				RenderCamera(*c);
			}
		}

		void UnlitSection::RenderCamera(CameraObject* camera)
		{
			auto batch = shared_ptr<ClearBatch>(new ClearBatch(camera->clearColor, camera->clearMode));
			RenderBatchManager::AddBatch(batch);
			auto objects = RenderCollection::GetCustomObjects(camera->layer);
			for (auto o = objects.begin(); o != objects.end(); o++)
			{
				RenderObject(*o, camera);
			}
		}
		void UnlitSection::RenderObject(RenderCustomObject* object, CameraObject* camera)
		{
			auto batch = shared_ptr<CustomRenderBatch>(new CustomRenderBatch);
			batch->camera = camera;
			batch->model = object->modelMat;
			batch->mesh = object->mesh.get();
			batch->material = object->material.get();
			RenderBatchManager::AddBatch(batch);
		}
		CreateRecordSection::~CreateRecordSection()
		{
		}
		void CreateRecordSection::Prepare()
		{
			RenderRecordManager::CreateRecord("Unlit");
		}
		void CreateRecordSection::Start()
		{
		}
		StopRecordSection::~StopRecordSection()
		{
		}
		void StopRecordSection::Prepare()
		{
			RenderRecordManager::StopRecord();
		}
		void StopRecordSection::Start()
		{
		}

		ScreenRecordSection::~ScreenRecordSection()
		{
		}
		void ScreenRecordSection::Prepare()
		{
			auto batch = shared_ptr<ClearBatch>(new ClearBatch());
			RenderBatchManager::AddBatch(batch);
		}
		void ScreenRecordSection::Start()
		{
			auto batch = shared_ptr<ScreenRenderBatch>(new ScreenRenderBatch);
			batch->useRecord = true;
			auto mat = ResourceInternal::ScreenViewMat();
			batch->material = mat.get();
			RenderBatchManager::AddBatch(batch);
		}
	}
}