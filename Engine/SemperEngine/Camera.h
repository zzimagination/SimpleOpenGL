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

		//// Processes input received from any keyboard-like input system. 
		////Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
		//void ProcessKeyboard(Camera_Movement direction, float deltaTime);

		//// Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
		//void ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);

		//// Processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
		//void ProcessMouseScroll(float yoffset);

	};
}
#endif