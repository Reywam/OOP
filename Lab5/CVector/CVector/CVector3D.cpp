#include "stdafx.h"
#include "CVector3D.h"
#include <math.h>
#include <float.h>

#define _USE_MATH_DEFINES
using namespace std;

//¬озвращает результат сложени€ векторов
const CVector3D CVector3D::operator+(CVector3D const& vector2)const
{
	// левым аргументом €вл€етс€ текущий экземпл€р класса
	// правым Ц единственный аргумент vector2
	return CVector3D(x + vector2.x, y + vector2.y, z + vector2.z);
}

//¬озвращает результат сложени€ векторов
const CVector3D CVector3D::operator-(CVector3D const& vector2)const
{
	// левым аргументом €вл€етс€ текущий экземпл€р класса
	// правым Ц единственный аргумент vector2
	return CVector3D(x - vector2.x, y - vector2.y, z - vector2.z);
}

CVector3D& CVector3D::operator +=(CVector3D const& vector)
{
	x += vector.x;
	y += vector.y;
	z += vector.z;
	return *this;
}

CVector3D& CVector3D::operator -=(CVector3D const& vector)
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
	return *this;
}

const CVector3D CVector3D::operator+() const
{
	return *this;
}

const CVector3D CVector3D::operator-() const
{
	return CVector3D(-x, -y, -z);
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
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}

CVector3D& CVector3D::operator /=(double scalar)
{
	if (scalar != 0)
	{
		x /= scalar;
		y /= scalar;
		z /= scalar;
	}
	return *this;
}

bool CVector3D::operator ==(CVector3D const& other)const
{
	//return (x == other.x) && (y == other.y) && (z == other.z);
	if ((fabs(x - other.x) < DBL_EPSILON) && (fabs(y - other.y) < DBL_EPSILON) && (fabs(z - other.z) < DBL_EPSILON))
	{
		return true;
	}
	return false;
}

bool CVector3D::operator !=(CVector3D const& other)const
{
	return !(*this == other);
}