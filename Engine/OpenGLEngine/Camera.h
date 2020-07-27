#ifndef CAMERA_H
#define CAMERA_H
#include<vector>
#include "Mathz.hpp"
using namespace glm;
using namespace std;

enum  Camera_Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP,
	DOWN
};
// Default camera values
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;

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

	Vector3 front;

	Vector3 up;

	Vector3 right;
	
	float size;

	Matrix4x4 worldToViewMatrix;

	Matrix4x4 projectionMatrix;

	Projection projection;

	float farPlane;

	float nearPlane;

	float fov;

	float aspect;

	// Euler Angles
	float Yaw;
	float Pitch;
	// Camera options
	float MovementSpeed;
	float MouseSensitivity;
	float Zoom;

public:

	Camera();

	~Camera();

public:

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
#endif