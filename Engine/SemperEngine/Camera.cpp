#include "Camera.h"
#include "Application.h"
#include "CameraCollection.h"

namespace SemperEngine {

	using namespace std;

	Camera::Camera()
	{
		_size = 5;
		_farPlane = 1000;
		_nearPlane = 1;
		_fov = 60;
		_aspect = 1.777778f;
	}

	Camera::~Camera()
	{
		
	}

	void Camera::Start()
	{
	}

	void Camera::Update()
	{
		Core::CameraCollection::AddCamera(this->life);
	}

	void Camera::End()
	{
		*life.life = false;
	}

	float Camera::GetSize()
	{
		return _size;
	}

	void Camera::SetSize(float size)
	{
		_size = Math::Clamp(0.1f, 100.0f, size);
	}

	float Camera::GetFar()
	{
		return _farPlane;
	}

	void Camera::SetFar(float l)
	{
		_farPlane = Math::Clamp(_nearPlane + 0.1f, l, l);
	}

	float Camera::GetNear()
	{
		return _nearPlane;
	}

	void Camera::SetNear(float l)
	{
		if (l <= 0)
		{
			_nearPlane = 0.01f;
		}
		else
		{
			_nearPlane = l;
		}
		if (_nearPlane > _farPlane)
		{
			_farPlane = _nearPlane + 0.01f;
		}
	}

	float Camera::GetFov()
	{
		return _fov;
	}

	void Camera::SetFov(float fov)
	{
		_fov = Math::Clamp(0.1f, 100.0f, fov);
	}

	float Camera::GetAspect()
	{
		_aspect = (float)Application::GetWindowWidth() / Application::GetWindowHeight();
		return _aspect;
	}

	Matrix4x4 Camera::CalculateProjectionMatrix()
	{
		Matrix4x4 m;
		switch (projection)
		{
		case Projection::Orthographic:
			m.x0 = 1 / (GetAspect()*GetSize());
			m.y1 = 1 / (GetSize());
			m.z2 = -2 / (GetFar() - GetNear());
			m.w2 = -(GetFar() + GetNear()) / (GetFar() - GetNear());
			break;
		case Projection::Perspective:
			m.x0 = (1 / tan(GetFov()* Math::pi / 180 / 2)) / GetAspect();
			m.y1 = 1 / tan(GetFov()*Math::pi / 180 / 2);
			m.z2 = -(GetFar() + GetNear()) / (GetFar() - GetNear());
			m.z3 = -1;
			m.w2 = -(2 * GetNear()*GetFar()) / (GetFar() - GetNear());
			m.w3 = 0;
			break;
		}
		projectionMatrix = m;
		return projectionMatrix;
	}

	Matrix4x4 Camera::CalculateViewMatrix()
	{
		Matrix4x4 m;
		m = m * Matrix4x4::Translate(-transform.position);
		m = m * Matrix4x4::Rotate(-transform.eulerAngle);
		worldToViewMatrix = m;
		return worldToViewMatrix;
	}

	//// Processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
	//void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
	//{
	//	/*float velocity = MovementSpeed * deltaTime;
	//	if (direction == FORWARD)
	//		Position += Front * velocity;
	//	if (direction == BACKWARD)
	//		Position -= Front * velocity;
	//	if (direction == LEFT)
	//		Position -= Right * velocity;
	//	if (direction == RIGHT)
	//		Position += Right * velocity;
	//	if (direction == UP)
	//	{
	//		Position.y += velocity;
	//	}
	//	if (direction == DOWN)
	//	{
	//		Position.y -= velocity;
	//	}*/
	//}

	//// Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
	//void Camera::ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch)
	//{
	//	//xoffset *= MouseSensitivity;
	//	//yoffset *= MouseSensitivity;

	//	//Yaw += xoffset;
	//	//Pitch += yoffset;

	//	//// Make sure that when pitch is out of bounds, screen doesn't get flipped
	//	//if (constrainPitch)
	//	//{
	//	//	if (Pitch > 89.0f)
	//	//		Pitch = 89.0f;
	//	//	if (Pitch < -89.0f)
	//	//		Pitch = -89.0f;
	//	//}

	//	//// Update Front, Right and Up Vectors using the updated Euler angles
	//	//UpdateVectors();
	//}

	//// Processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
	//void Camera::ProcessMouseScroll(float yoffset)
	//{
	//	//if (Zoom >= 1.0f && Zoom <= 45.0f)
	//	//	Zoom -= yoffset;
	//	//if (Zoom <= 1.0f)
	//	//	Zoom = 1.0f;
	//	//if (Zoom >= 45.0f)
	//	//	Zoom = 45.0f;
	//}
}