#ifndef __CAMERA__
#define __CAMERA__

#include "GameObject.h"
#include <glm\detail\type_float.hpp>

namespace SemperEngine {

	constexpr unsigned int ClearModeColor = 0x01;

	constexpr unsigned int ClearModeDepth = 0x02;

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

		std::vector<int> renderLayer;

	private:

		float _size;

		float _farPlane;

		float _nearPlane;

		float _fov;

		float _aspect;

		Vector2 _lastMousePos;

		float _yaw;

		float _pitch;

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

	private:

		void Move();

		void Rotate();
	};
}
#endif