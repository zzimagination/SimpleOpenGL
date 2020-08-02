#include "ProjectSetting.h"
#include "Camera.h"
#include <math.h>
#include "ProjectSetting.h"

Camera::Camera()
{

}

Camera::~Camera()
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
	return (float)ProjectSetting::GetWindowWidth() / ProjectSetting::GetWindowHeight();
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
	return m;
}

Matrix4x4 Camera::CalculateViewMatrix()
{
	Matrix4x4 m;
	m = m * Matrix4x4::Translate(-position);
	m = m * Matrix4x4::Rotate(-eulerAngle);
	worldToViewMatrix = m;
	return m;
}

// Processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
{
	/*float velocity = MovementSpeed * deltaTime;
	if (direction == FORWARD)
		Position += Front * velocity;
	if (direction == BACKWARD)
		Position -= Front * velocity;
	if (direction == LEFT)
		Position -= Right * velocity;
	if (direction == RIGHT)
		Position += Right * velocity;
	if (direction == UP)
	{
		Position.y += velocity;
	}
	if (direction == DOWN)
	{
		Position.y -= velocity;
	}*/
}

// Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
void Camera::ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch)
{
	//xoffset *= MouseSensitivity;
	//yoffset *= MouseSensitivity;

	//Yaw += xoffset;
	//Pitch += yoffset;

	//// Make sure that when pitch is out of bounds, screen doesn't get flipped
	//if (constrainPitch)
	//{
	//	if (Pitch > 89.0f)
	//		Pitch = 89.0f;
	//	if (Pitch < -89.0f)
	//		Pitch = -89.0f;
	//}

	//// Update Front, Right and Up Vectors using the updated Euler angles
	//UpdateVectors();
}

// Processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
void Camera::ProcessMouseScroll(float yoffset)
{
	if (Zoom >= 1.0f && Zoom <= 45.0f)
		Zoom -= yoffset;
	if (Zoom <= 1.0f)
		Zoom = 1.0f;
	if (Zoom >= 45.0f)
		Zoom = 45.0f;
}

//void Camera::CalculateVectors()
//{
//	vec4 x = vec4(1, 0, 0, 0);
//	vec4 z = vec4(0, 0, 1, 0);
//	vec4 y = vec4(0, 1, 0, 0);
//	vec4 center = vec4(-Position, 1);
//
//
//	mat4 rat = mat4(1);
//	rat = rotate(rat, radians(-eulerAngle.x), vec3(1, 0, 0));
//	rat = rotate(rat, radians(-eulerAngle.y), vec3(0, 1, 0));
//	rat = rotate(rat, radians(-eulerAngle.z), vec3(0, 0, 1));
//	x = normalize(rat*x);
//	y = normalize(rat*y);
//	z = normalize(rat*z);
//	center = rat * center;
//	//worldToViewMatrix = mat4(
//	//	x,
//	//	y,
//	//	z,
//	//	center
//	//);//∞¥¡–≈≈¡–
//	worldToViewMatrix = Matrix4x4(
//		x.x, y.x, z.x, center.x,
//		x.y, y.y, z.y, center.y,
//		x.z, y.z, z.z, center.z,
//		x.w, y.w, z.w, center.w
//	);
//
//	float scale = 1;
//	switch (projection)
//	{
//	case Orthographic:
//		scale = (float)ProjectSetting::GetWindowWidth() / ProjectSetting::GetWindowHeight();
//		mat4  o = glm::ortho(-size * scale, size*scale, -size, size, 0.1f, 100.0f);
//		projectionMatrix = Matrix4x4(
//			o[0][0], o[1][0], o[2][0], o[3][0],
//			o[0][1], o[1][1], o[2][1], o[3][1],
//			o[0][2], o[1][2], o[2][2], o[3][2],
//			o[0][3], o[1][3], o[2][3], o[3][3]
//		);
//		break;
//	case Perspective:
//		mat4 p = glm::perspective(radians(75.0f), 1.5f, 0.1f, 100.0f);
//		projectionMatrix = Matrix4x4(
//			p[0][0], p[1][0], p[2][0], p[3][0],
//			p[0][1], p[1][1], p[2][1], p[3][1],
//			p[0][2], p[1][2], p[2][2], p[3][2],
//			p[0][3], p[1][3], p[2][3], p[3][3]
//		);
//		break;
//	}
//}
