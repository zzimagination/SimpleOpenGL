#include "Camera.h"
#include "GameSetting.h"
#include "CameraCollection.h"
#include "Event.h"
#include "Time.h"

namespace SemperEngine {

	using namespace std;
	using namespace Core;

	Camera::Camera()
	{
		this->_size = 5;
		this->_farPlane = 1000;
		this->_nearPlane = 0.2f;
		this->_fov = 65;
		this->_aspect = (float)GameSetting::windowWidth / GameSetting::windowHeight;
		this->projection = Projection::Perspective;
		this->clearMode = ClearMode::Color;
		this->clearColor = Color::ColorFloat(0.8f, 0.8f, 0.8f);
		_cameraObject = unique_ptr<CameraObject>(new CameraObject());
	}

	Camera::~Camera()
	{
	}

	void Camera::Start()
	{
		auto look = transform.rotation * Float3::forward;
		Float3 lookp(look.x, 0, look.z);
		_yaw = Math::ArcCos(Float3::Dot(lookp, Float3::forward) / lookp.Length());
		_pitch = Math::ArcCos(Float3::Dot(lookp, look) / (look.Length(), lookp.Length()));
	}

	void Camera::Update()
	{
		ChangeProjection();
		Move();
		Rotate();
		UpdateObject();
		AddObject();
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
		return _aspect;
	}

	void Camera::SetAspect(float a)
	{
		_aspect = a;
	}

	Matrix4x4 Camera::CalculateProjectionMatrix()
	{
		Matrix4x4 m;
		switch (projection)
		{
		case Projection::Orthographic:
			m.x0 = 1 / (GetAspect() * GetSize());
			m.y1 = 1 / (GetSize());
			m.z2 = -2 / (GetFar() - GetNear());
			m.w2 = -(GetFar() + GetNear()) / (GetFar() - GetNear());
			break;
		case Projection::Perspective:

			float n = _nearPlane;
			float f = _farPlane;
			float tan = Math::Tan(_fov / 2);
			float t = n * tan;
			float b = -t;
			float l = -t * _aspect;
			float r = -l;

			m.x0 = n / r;
			m.y1 = n / t;
			m.z2 = (f + n) / (n - f);
			m.z3 = -1;
			m.w2 = (2 * f * n) / (n - f);
			m.w3 = 0;
			break;
		}
		projectionMatrix = m;
		return projectionMatrix;
	}

	Matrix4x4 Camera::CalculateViewMatrix()
	{
		Float3 zero(0, 0, 0);
		Float3 pos = transform.position;
		Float3 up(0, 1, 0);

		Float3 look = transform.rotation * Float3(0, 0, 1);
		Float3 right = transform.rotation * Float3(1, 0, 0);
		Float3 top = Float3::Cross(look, right);

		Matrix4x4 view(
			right.x, right.y, right.z, -Float3::Dot(right, pos),
			top.x, top.y, top.z, -Float3::Dot(top, pos),
			look.x, look.y, look.z, -Float3::Dot(look, pos),
			0, 0, 0, 1
		);

		worldToViewMatrix = view;
		return worldToViewMatrix;
	}
	void Camera::AddRenderLayer(int layer)
	{
		_cameraObject->renderLayer.Add(layer);
	}
	void Camera::RemoveRenderLayer(int layer)
	{
		_cameraObject->renderLayer.Remove(layer);
	}
	std::vector<int> Camera::GetRenderLayers()
	{
		return _cameraObject->renderLayer.GetLayers();
	}
	void Camera::Move()
	{
		typedef Keyboard::Key Key;
		typedef InputAction::Button BA;
		Float3 moveDelta;
		if (Event::KeyAction(Key::w, BA::press) || Event::KeyAction(Key::w, BA::keep))
		{
			moveDelta.z = -Time::GetDeltaTime() * 5;
		}
		else if (Event::KeyAction(Key::s, BA::press) || Event::KeyAction(Key::s, BA::keep))
		{
			moveDelta.z = Time::GetDeltaTime() * 5;
		}
		if (Event::KeyAction(Key::a, BA::press) || Event::KeyAction(Key::a, BA::keep))
		{
			moveDelta.x = -Time::GetDeltaTime() * 5;
		}
		else if (Event::KeyAction(Key::d, BA::press) || Event::KeyAction(Key::d, BA::keep))
		{
			moveDelta.x = Time::GetDeltaTime() * 5;
		}
		if (Event::KeyAction(Key::q, BA::press) || Event::KeyAction(Key::q, BA::keep))
		{
			moveDelta.y = -Time::GetDeltaTime() * 5;
		}
		else if (Event::KeyAction(Key::e, BA::press) || Event::KeyAction(Key::e, BA::keep))
		{
			moveDelta.y = Time::GetDeltaTime() * 5;
		}

		auto forward = transform.rotation * Float3(0, 0, 1);
		auto up = Float3(0, 1, 0);
		auto left = transform.rotation * Float3(1, 0, 0);
		transform.position = transform.position + forward * moveDelta.z + moveDelta.y * up + moveDelta.x * left;
	}
	void Camera::Rotate()
	{
		typedef Keyboard::Key Key;
		typedef Mouse::Button MButton;
		typedef InputAction::Button BA;
		if (!Event::MouseButtonAction(MButton::right, BA::keep))
		{
			_lastMousePos = Event::MousePosition();
			return;
		}

		auto nowPos = Event::MousePosition();
		auto delta = nowPos - _lastMousePos;
		_lastMousePos = nowPos;
		_yaw += delta.x * Time::GetDeltaTime() * -5;
		_pitch += delta.y * Time::GetDeltaTime() * -5;
		transform.rotation = Quaternion::AngleAxis(_yaw, Float3(0, 1, 0)) * Quaternion::AngleAxis(_pitch, Float3(1, 0, 0));
	}
	void Camera::ChangeProjection()
	{
		if (Event::KeyAction(Keyboard::Key::f1, InputAction::Button::press))
		{
			if (projection == Projection::Orthographic)
			{
				projection = Projection::Perspective;
			}
			else
			{
				projection = Projection::Orthographic;
			}
		}
	}

	void Camera::UpdateObject()
	{
		_cameraObject->viewMatrix = CalculateViewMatrix();
		_cameraObject->projectMatrix = CalculateProjectionMatrix();
		_cameraObject->clearColor = clearColor;
		switch (clearMode)
		{
		case ClearMode::None:
			_cameraObject->clearMode = RenderEnum::ClearMode::Color;
			break;
		case ClearMode::Color:
			_cameraObject->clearMode = ClearColorDepth;
			break;
		case ClearMode::DepthOnly:
			_cameraObject->clearMode = RenderEnum::ClearMode::Depth;
			break;
		}
	}

	void Camera::AddObject()
	{
		CameraCollection::AddCamera(_cameraObject->myLife);
	}


}