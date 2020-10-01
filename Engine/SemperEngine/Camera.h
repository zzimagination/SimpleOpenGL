#ifndef CAMERA_H
#define CAMERA_H


#include <vector>
#include <memory>
#include "LifeContainer.h"
#include "Mathz.h"
#include "GameObject.h"

namespace SemperEngine {

	class Camera : public GameObject
	{
	public:

		enum class Projection
		{
			Orthographic,

			Perspective
		};

	public:

		Matrix4x4 worldToViewMatrix;

		Matrix4x4 projectionMatrix;

		Projection projection = Projection::Perspective;

	private:

		float _size;

		float _farPlane;

		float _nearPlane;

		float _fov;

		float _aspect;

	public:

		Camera();

		~Camera();

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

		Matrix4x4 CalculateProjectionMatrix();

		Matrix4x4 CalculateViewMatrix();

	};
}
#endif