#include "stdafx.h"
#include "CVector3D.h"
#include <math.h>
#include <float.h>

#define _USE_MATH_DEFINES
using namespace std;

const CVector3D CVector3D::operator+() const
{
	return *this;
}

const CVector3D CVector3D::operator-() const
{
	return CVector3D(-x, -y, -z);
}

//Возвращает результат сложения векторов
const CVector3D CVector3D::operator+(CVector3D const& vector)const
{
	return CVector3D(x + vector.x, y + vector.y, z + vector.z);
}

//Возвращает результат разности векторов
CVector3D const CVector3D::operator-(CVector3D const& vector)const
{
	return *this + (-vector);
}

CVector3D& CVector3D::operator +=(CVector3D const& vector)
{
	return *this = *this + vector;
}

CVector3D& CVector3D::operator -=(CVector3D const& vector)
{
	return *this = *this - vector;
}

double CVector3D::GetLength()const
{
	return sqrt(x*x + y*y + z*z);
}

void CVector3D::Normalize()
{
	if (GetLength() != 0)
	{
		x = x / GetLength();
		y = y / GetLength();
		z = z / GetLength();
	}
}

const CVector3D CVector3D::operator *(double scalar)const
{
	return CVector3D(x * scalar, y * scalar, z * scalar);
}

CVector3D const operator *(double scalar, CVector3D const& vector)
{
	return CVector3D(scalar * vector.x, scalar * vector.y, scalar * vector.z);
}

CVector3D const CVector3D::operator /(double scalar)const
{
	if (scalar != 0)
	{
		return CVector3D(x / scalar, y / scalar, z / scalar);
	}

	return CVector3D(x, y, z);
}

CVector3D& CVector3D::operator *=(double scalar)
{
	return *this = *this * scalar;
}

CVector3D& CVector3D::operator /=(double scalar)
{
	if (scalar != 0)
	{
		*this = *this / scalar;
	}

	return *this;
}

bool CVector3D::operator ==(CVector3D const& vector)const
{
	return ((fabs(x - vector.x) < DBL_EPSILON) && (fabs(y - vector.y) < DBL_EPSILON) && (fabs(z - vector.z) < DBL_EPSILON));
	/*{
		return true;
	}

	return false;*/
}

bool CVector3D::operator !=(CVector3D const& vector)const
{
	return !(*this == vector);
}