#include "Quaternion.h"

namespace SemperEngine
{
	Quaternion Quaternion::AngleAxis(float angle, Vector3 axis)
	{
		float s = Math::Sin(angle * 0.5f);
		float x = s * axis.x;
		float y = s * axis.y;
		float z = s * axis.z;
		float w = Math::Cos(angle * 0.5f);
		return Quaternion(x, y, z, w);
	}
	Quaternion::Quaternion()
	{
		_data = Vector4(0, 0, 0, 1);
	}
	Quaternion::Quaternion(float x, float y, float z, float w)
	{
		_data.x = x;
		_data.y = y;
		_data.z = z;
		_data.w = w;
	}
	float Quaternion::X()
	{
		return _data.x;
	}
	float Quaternion::Y()
	{
		return _data.y;
	}
	float Quaternion::Z()
	{
		return _data.z;
	}
	float Quaternion::W()
	{
		return _data.w;
	}
	Quaternion Quaternion::inverse()
	{
		float w = this->W();
		float x = -this->X();
		float y = -this->Y();
		float z = -this->Z();
		return Quaternion(x, y, z, w);
	}
	Matrix4x4 Quaternion::ToMatrix()
	{
		float x = this->X();
		float y = this->Y();
		float z = this->Z();
		float w = this->W();
		Matrix4x4 m(
			1 - 2 * y * y - 2 * z * z, 2 * x * y - 2 * w * z, 2 * x * z + 2 * w * y, 0,
			2 * x * y + 2 * w * z, 1 - 2 * x * x - 2 * z * z, 2 * y * z - 2 * w * x, 0,
			2 * x * z - 2 * w * y, 2 * y * z + 2 * w * x, 1 - 2 * x * x - 2 * y * y, 0,
			0, 0, 0, 1
		);
		return m;
	}
	Quaternion& Quaternion::operator=(const Quaternion& right)
	{
		this->_data = right._data;
		return *this;
	}
	Quaternion Quaternion::operator*(const Quaternion& right)
	{
		float s1 = this->W();
		float x1 = this->X();
		float y1 = this->Y();
		float z1 = this->Z();
		float s2 = right._data.w;
		float x2 = right._data.x;
		float y2 = right._data.y;
		float z2 = right._data.z;

		float x = s1 * x2 + s2 * x1 + y1 * z2 - z1 * y2;
		float y = s1 * y2 + s2 * y1 + z1 * x2 - x1 * z2;
		float z = s1 * z2 + s2 * z1 + x1 * y2 - y1 * x2;
		float s = s1 * s2 - (x1 * x2 + y1 * y2 + z1 * z2);
		return Quaternion(x, y, z, s);
	}
	Vector3 Quaternion::operator*(const Vector3& right)
	{
		Quaternion q = Quaternion(right.x, right.y, right.z, 0);
		float s = this->W();
		Vector3 v(this->X(), this->Y(), this->Z());
		auto result = s * s * right + Vector3::Cross(2 * s * v, right) + Vector3::Dot(v, right) * v - Vector3::Cross(Vector3::Cross(v, right), v);
		return result;
	}
}