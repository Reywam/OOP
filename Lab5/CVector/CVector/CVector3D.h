#pragma once

class CVector3D final
{
public:
	// ������������ ������� ������
	CVector3D()
	{
		x = 0;
		y = 0;
		z = 0;
	};

	// ������������ ������ � ��������� ������������
	CVector3D(double x0, double y0, double z0)
	{
		x = x0;
		y = y0;
		z = z0;
	};

	// ���������� ����� �������
	double GetLength()const;

	// ����������� ������ (�������� ��� � ��������� �����)
	void Normalize();

	// ������ ������ � �������� ������
	//���������� ��� �� ����� ������
	const CVector3D operator+() const;

	//���������� ������ � ��������������� ������������
	const CVector3D operator-() const;

	//���������� ��������� �������� ���� ��������
	CVector3D const operator+(CVector3D const& vector2)const;

	CVector3D const operator-(CVector3D const& vector2)const;
	//��������� ���������� ����� ������� �� ����� ������� �������
	CVector3D& operator +=(CVector3D const& vector);

	CVector3D& CVector3D::operator -=(CVector3D const& vector);

	//�������� ������ �� ������
	CVector3D const operator *(double scalar)const;
	
	//��������� ������� ������� �� ������
	CVector3D const operator /(double scalar)const;

	//�������� ������ �� ������
	CVector3D& CVector3D::operator *=(double scalar);

	//�������� ������ �� ������
	CVector3D& CVector3D::operator /=(double scalar);

	//��������� ������� �� ���������
	bool CVector3D::operator ==(CVector3D const& other)const;
	bool CVector3D::operator !=(CVector3D const& other)const;

	// � ������ ������ ������ ����� ������� ����������
	double x, y, z;
};

//��������� ��������� ������� �� ������
CVector3D const operator *(double scalar, CVector3D const& vector);
