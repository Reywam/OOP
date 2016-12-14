#include "stdafx.h"
#include "solve4.h"

using namespace std;

int main()
{
	EquationRoots solution;

	vector<double> numbers;

	while (!cin.eof())
	{
		double number;
		cin >> number;

		if (numbers.size() != 5)
		{
			numbers.push_back(number);
		}
	}

	try
	{
		if (numbers.size() != 5)
		{
			throw domain_error("Invalid arguements count.\nCount of arguements must be equal to 5.");
		}

		solution = Solve4(numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
	}
	catch (invalid_argument const &e)
	{
		cout << e.what() << endl;
	}
	catch (domain_error const &e)
	{
		cout << e.what() << endl;
	}
	
	PrintRoots(solution);

    return 0;
}