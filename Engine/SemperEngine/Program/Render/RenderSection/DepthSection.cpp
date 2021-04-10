#include "DepthSection.h"
#include "../../CameraCollection.h"
#include "../../RenderCollection.h"
#include "../../RenderBatchManager.h"
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
			for (auto i = 0; i < _materials.size(); i++)
			{
				delete _materials[i];
			}
			_materials.clear();
		}

		void DepthSection::Start()
		{
			auto _cameras = CameraCollection::GetCameras();
			for (auto camera = _cameras.begin(); camera < _cameras.end(); camera++)
			{
				RenderCamera(*camera);
			}
		}

		void DepthSection::RenderCamera(CameraObject* camera)
		{
			auto batch = shared_ptr<ClearBatch>(new ClearBatch(Color::Color32(0, 0, 0), ClearColorDepth));
			RenderBatchManager::AddBatch(batch);

			auto distance = Math::Abs(camera->far - camera->near);
			auto material = new Material("Depth");
			material->AddProperty("_NFDis", distance);
			_materials.push_back(material);

			auto objects = RenderCollection::GetCustomObjects(camera->layer);
			for (auto o = objects.begin(); o != objects.end(); o++)
			{
				RenderObject(*o, camera, material);
			}
		}
		void DepthSection::RenderObject(RenderCustomObject* object, CameraObject* camera, Material* material)
		{
			auto batch = shared_ptr<CustomRenderBatch>(new CustomRenderBatch);
			batch->camera = camera;
			batch->model = object->modelMat;
			batch->mesh = object->mesh.get();
			batch->material = material;
			RenderBatchManager::AddBatch(batch);
		}
	}
}