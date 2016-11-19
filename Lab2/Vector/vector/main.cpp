#include "stdafx.h"
#include "VectorProcessor.h"

using namespace std;

//Каждый элемент массива должен быть умножен на минимальный элемент исходного массива
int main()
{
	vector<double> numbers = ReadVector(cin);
	ProcessVector(numbers);
	SortVector(numbers);
	OutVector(cout, numbers);
	return 0;
}
