#include "Camera.h"
#include "Application.h"
#include "CameraCollection.h"

namespace SemperEngine {

	using namespace std;

	Camera::Camera()
	{
		_size = 5;
		_farPlane = 1000;
		_nearPlane = 0.2;
		_fov = 60;
		_aspect = 1.777778f;
		projection = Projection::Perspective;
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
			m.x0 = (1 / tan(GetFov()* Math::pi / 180.0f / 2.0f)) / GetAspect();
			m.y1 = 1 / tan(GetFov()*Math::pi / 180.0f / 2.0f);
			m.z2 = -(GetFar() + GetNear()) / (GetFar() - GetNear());
			m.z3 = -1;
			m.w2 = -(2.0f * GetNear()*GetFar()) / (GetFar() - GetNear());
			m.w3 = 0;
			break;
		}
		projectionMatrix = m;
		return projectionMatrix;
	}

	Matrix4x4 Camera::CalculateViewMatrix()
	{
		Vector3 zero(0, 0, 0);
		Vector3 pos = transform.position;
		Vector3 up(0, 1, 0);

		Vector3 look = (transform.GetModelMatrix()*Vector3(0, 0, 1)).Normalize();
		Vector3 left = Vector3::Cross(up, look).Normalize();
		Vector3 top = Vector3::Cross(look, left).Normalize();

		Matrix4x4 view(
			left.x, left.y, left.z, -Vector3::Dot(left, pos),
			top.x, top.y, top.z, -Vector3::Dot(top, pos),
			look.x, look.y, look.z, -Vector3::Dot(look, pos),
			0, 0, 0, 1
		);

		worldToViewMatrix = view;
		return worldToViewMatrix;
	}
}