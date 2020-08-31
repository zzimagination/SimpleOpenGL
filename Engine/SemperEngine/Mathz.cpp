#include "Mathz.h"

#ifdef  MATH_GLM
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#endif

namespace SemperEngine {

	Vector3 MathVector::Cross(Vector3 a, Vector3 b)
	{
		return Vector3(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
	}
	float MathVector::Dot(Vector3 a, Vector3 b)
	{
		return a.x*b.x + a.y*b.y + a.z*b.z;
	}

}