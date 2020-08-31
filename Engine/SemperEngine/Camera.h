#ifndef CAMERA_H
#define CAMERA_H
#include<vector>
#include "Mathz.h"

namespace SemperEngine {

	using namespace std;

	enum  Camera_Movement {
		FORWARD,
		BACKWARD,
		LEFT,
		RIGHT,
		UP,
		DOWN
	};

	enum Projection
	{
		Orthographic,

		Perspective
	};

	// An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
	class Camera
	{
	public:

		Vector3 position;

		Vector3 eulerAngle;

		Matrix4x4 worldToViewMatrix;

		Matrix4x4 projectionMatrix;

		Projection projection = Projection::Perspective;

	private:

		float _size = 5;

		float _farPlane = 1000;

		float _nearPlane = 1;

		float _fov = 60;

		float _aspect = 1.777778f;

	public:

		Camera();

		~Camera();

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

		// Processes input received from any keyboard-like input system. 
		//Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
		void ProcessKeyboard(Camera_Movement direction, float deltaTime);

		// Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
		void ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);

		// Processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
		void ProcessMouseScroll(float yoffset);

	};
}
#endif