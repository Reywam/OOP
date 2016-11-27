#include "stdafx.h"
#include <iostream>
#include "CVector3D.h"

using namespace std;

int main()
{
	CVector3D newVector(1, 1, 1);
	newVector.Normalize();
	cout << newVector.x << newVector.y << newVector.z << endl;
	return 0;
}