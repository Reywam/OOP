#pragma once

class CVector3D final
{
public:
	// Конструирует нулевой вектор
	CVector3D()
	{
		x = 0;
		y = 0;
		z = 0;
	};

	// Конструирует вектор с заданными координатами
	CVector3D(double x0, double y0, double z0)
	{
		x = x0;
		y = y0;
		z = z0;
	};

	// Возвращает длину вектора
	double GetLength()const;

	// Нормализует вектор (приводит его к единичной длине)
	void Normalize();

	// Другие методы и операции класса
	//Возвращает тот же самый вектор
	const CVector3D operator+() const;

	//Возвращает вектор с противоположным направлением
	const CVector3D operator-() const;

	//Возвращает результат сложения двух векторов
	CVector3D const operator+(CVector3D const& vector2)const;

	CVector3D const operator-(CVector3D const& vector2)const;
	//Выполняют увеличение длины вектора на длину второго вектора
	CVector3D& operator +=(CVector3D const& vector);

	CVector3D& CVector3D::operator -=(CVector3D const& vector);

	//Умножает вектор на скаляр
	CVector3D const operator *(double scalar)const;
	
	//Выполняет деление вектора на скаляр
	CVector3D const operator /(double scalar)const;

	//Умножает вектор на скаляр
	CVector3D& CVector3D::operator *=(double scalar);

	//Умножает вектор на скаляр
	CVector3D& CVector3D::operator /=(double scalar);

	//Проверяет вектора на равенство
	bool CVector3D::operator ==(CVector3D const& other)const;
	bool CVector3D::operator !=(CVector3D const& other)const;

	// В данном случае данные можно сделать публичными
	double x, y, z;
};

//Выполняет умножение скаляра на вектор
CVector3D const operator *(double scalar, CVector3D const& vector);
