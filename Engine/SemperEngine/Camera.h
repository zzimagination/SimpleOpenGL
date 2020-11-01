#ifndef __CAMERA__
#define __CAMERA__

#include "GameObject.h"
#include "CameraObject.h"

namespace SemperEngine {

	class Camera : public GameObject
	{
	public:

		enum class Projection
		{
			Orthographic,

			Perspective
		};

		enum class ClearMode
		{
			None,

			Color,

			DepthOnly
		};

	public:

		Matrix4x4 worldToViewMatrix;

		Matrix4x4 projectionMatrix;

		Projection projection;

		ClearMode clearMode;

		Color clearColor;

	private:

		float _size;

		float _farPlane;

		float _nearPlane;

		float _fov;

		float _aspect;

		Float2 _lastMousePos;

		float _yaw;

		float _pitch;

		std::unique_ptr<Core::CameraObject> _cameraObject;

	public:

		Camera();

		virtual ~Camera() override;

		virtual void Start() override;

		virtual void Update() override;

		virtual void End() override;

	public:

		float GetSize();

		void SetSize(float size);

		float GetFar();

		void SetFar(float l);

		float GetNear();

		void SetNear(float l);

		float GetFov();

		void SetFov(float fov);

		float GetAspect();

		void SetAspect(float a);

		Matrix4x4 CalculateProjectionMatrix();

		Matrix4x4 CalculateViewMatrix();

		void AddRenderLayer(int layer);

		void RemoveRenderLayer(int layer);

		std::vector<int> GetRenderLayers();

	private:

		void Move();

		void Rotate();

		void ChangeProjection();
	};
}
#endif