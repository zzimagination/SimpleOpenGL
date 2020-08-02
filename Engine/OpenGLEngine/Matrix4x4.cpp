#include "Matrix4x4.h"
#include "Vector4.h"
#include <math.h>

Matrix4x4 Matrix4x4::identity = Matrix4x4();

Matrix4x4 Matrix4x4::Translate(Vector3 v)
{
	Matrix4x4 m;
	m.w0 += v.x;
	m.w1 += v.y;
	m.w2 += v.z;
	return m;
}

Matrix4x4 Matrix4x4::Rotate(Vector3 angle)
{
	Matrix4x4 x;
	x.y1 = (float)cos(angle.x);
	x.z1 = -(float)sin(angle.x);
	x.y2 = (float)sin(angle.x);
	x.z2 = (float)cos(angle.x);

	Matrix4x4 y;
	y.x0 = (float)cos(angle.y);
	y.z0 = (float)sin(angle.y);
	y.x2 = -(float)sin(angle.y);
	y.z2 = (float)cos(angle.y);

	Matrix4x4 z;
	z.x0 = (float)cos(angle.z);
	z.y0 = -(float)sin(angle.z);
	z.x1 = (float)sin(angle.z);
	z.y1 = (float)cos(angle.z);

	return z * x * y;
}

Matrix4x4 Matrix4x4::Scale(Vector3 v)
{
	Matrix4x4 m;
	m.x0 = v.x;
	m.y1 = v.y;
	m.z2 = v.z;
	return m;
}

Matrix4x4::Matrix4x4()
{
	x0 = 1; y0 = 0; z0 = 0; w0 = 0;
	x1 = 0; y1 = 1; z1 = 0; w1 = 0;
	x2 = 0; y2 = 0; z2 = 1; w2 = 0;
	x3 = 0; y3 = 0; z3 = 0; w3 = 1;
}

Matrix4x4::Matrix4x4(Vector4& r0, Vector4& r1, Vector4& r2, Vector4& r3)
{
	x0 = r0.x; y0 = r0.y; z0 = r0.z; w0 = r0.w;
	x1 = r1.x; y1 = r1.y; z1 = r1.z; w0 = r1.w;
	x2 = r2.x; y2 = r2.y; z2 = r2.z; w2 = r2.w;
	x3 = r3.x; y3 = r3.y; z3 = r3.z; w3 = r3.w;
}

Matrix4x4::Matrix4x4(float r0c0, float r0c1, float r0c2, float r0c3, float r1c0, float r1c1, float r1c2, float r1c3, float r2c0, float r2c1, float r2c2, float r2c3, float r3c0, float r3c1, float r3c2, float r3c3)
{
	x0 = r0c0; y0 = r0c1; z0 = r0c2; w0 = r0c3;
	x1 = r1c0; y1 = r1c1; z1 = r1c2; w0 = r1c3;
	x2 = r2c0; y2 = r2c1; z2 = r2c2; w2 = r2c3;
	x3 = r3c0; y3 = r3c1; z3 = r3c2; w3 = r3c3;
}

Vector4 Matrix4x4::GetRow(int i) const
{
	if (i == 0)
	{
		return Vector4(x0, y0, z0, w0);
	}
	else if (i == 1)
	{
		return Vector4(x1, y1, z1, w1);
	}
	else if (i == 2)
	{
		return Vector4(x2, y2, z2, w2);
	}
	else 
	{
		return Vector4(x3, y3, z3, w3);
	}
}

Vector4 Matrix4x4::GetColumn(int i) const
{
	if (i == 0)
	{
		return Vector4(x0, x1, x2, x3);
	}
	else if (i == 1)
	{
		return Vector4(y0, y1, y2, y3);
	}
	else if (i == 2)
	{
		return Vector4(z0, z1, z2, z3);
	}
	else 
	{
		return Vector4(w0, w1, w2, w3);
	}
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &b)
{
	Matrix4x4 m;
	m.x0 = this->GetRow(0)*b.GetColumn(0);
	m.x1 = this->GetRow(1)*b.GetColumn(0);
	m.x2 = this->GetRow(2)*b.GetColumn(0);
	m.x3 = this->GetRow(3)*b.GetColumn(0);

	m.y0 = this->GetRow(0)*b.GetColumn(1);
	m.y1 = this->GetRow(1)*b.GetColumn(1);
	m.y2 = this->GetRow(2)*b.GetColumn(1);
	m.y3 = this->GetRow(3)*b.GetColumn(1);

	m.z0 = this->GetRow(0)*b.GetColumn(2);
	m.z1 = this->GetRow(1)*b.GetColumn(2);
	m.z2 = this->GetRow(2)*b.GetColumn(2);
	m.z3 = this->GetRow(3)*b.GetColumn(2);

	m.w0 = this->GetRow(0)*b.GetColumn(3);
	m.w1 = this->GetRow(1)*b.GetColumn(3);
	m.w2 = this->GetRow(2)*b.GetColumn(3);
	m.w3 = this->GetRow(3)*b.GetColumn(3);
	return m;
}