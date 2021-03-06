#include "stdafx.h"
#include "solve4.h"
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#include <functional>

using namespace std;

int Sign(const int &val)
{
	return (val > 0) ? (1) : ((val < 0) ? (-1) : (0));
}

void ToCanonicalForm(const double a, double &b, double &c, double &d, double &e)
{
	b /= a;
	c /= a;
	d /= a;
	e /= a;
}

// Вычисляем корни квадратного уравнения ax^2 + bx + c = 0
EquationRoots Solve2(double a, double b, double c)
{
	EquationRoots solution;

	auto d = (b * b) - (4 * a * c);

	if (d == 0)
	{
		auto x1 = -b / (2 * a);

		solution.root[0] = x1;
		solution.numRoots = 1;
	}

	if (d > 0)
	{
		auto x1 = (-b + sqrt(d)) / (2 * a);
		auto x2 = (-b - sqrt(d)) / (2 * a);

		solution.root[0] = x1;
		solution.root[1] = x2;
		solution.numRoots = 2;
	}

	return solution;
}

EquationRoots Solve3(double a, double b, double c)
{
	EquationRoots roots;

	double q = (pow(a, 2) - 3 * b) / 9;
	double r = (2 * pow(a, 3) - 9 * a * b + 27 * c) / 54;
	double s = pow(q, 3) - pow(r, 2);

	if (s > 0)
	{
		double t = acos(r / sqrt(pow(abs(q), 3))) / 3;
		roots.numRoots = 3;
		roots.root[0] = -2 * sqrt(abs(q)) * cos(t) - (a / 3);
		roots.root[1] = -2 * sqrt(abs(q)) * cos(t + (2 * M_PI) / 3) - (a / 3);
		roots.root[2] = -2 * sqrt(abs(q)) * cos(t - (2 * M_PI) / 3) - (a / 3);
	}
	else if (abs(s) < DBL_EPSILON)
	{
		roots.numRoots = 2;
		roots.root[0] = -2 * pow(r, 0.33) - (a / 3);
		roots.root[1] = pow(r, 0.33) - (a / 3);
	}
	else
	{
		if (q > 0)
		{
			double t = acosh(abs(r) / sqrt(pow(abs(q), 3))) / 3;
			roots.numRoots = 1;
			roots.root[0] = -2.0 * Sign((int)r) * sqrt(abs(q)) * cosh(t) - a / 3.0;
		}
		else
		{
			double t = asinh(abs(r) / sqrt(pow(abs(q), 3))) / 3;
			roots.numRoots = 1;
			roots.root[0] = -2.0 * Sign((int)r) * sqrt(abs(q)) * sinh(t) - a / 3.0;
		}
	}

	return roots;
}

EquationRoots MergeRoots(EquationRoots const &SquareEquation1, EquationRoots const &SquareEquation2)
{
	EquationRoots resolvent;

	int root = 0;

	for (size_t i = 0; i < SquareEquation1.numRoots; i++)
	{
		resolvent.root[root] = SquareEquation1.root[i];
		root++;
	}

	for (size_t i = 0; i < SquareEquation2.numRoots; i++)
	{
		resolvent.root[root] = SquareEquation2.root[i];
		root++;
	}

	resolvent.numRoots = root;
	return resolvent;
}

EquationRoots Solve4(double a, double b, double c, double d, double e)
{
	if (a == 0)
	{
		throw invalid_argument("First arguement must be not equal to zero.");
	}

	ToCanonicalForm(a, b, c, d , e);

	double n = -c;
	double p = (b * d) - (4 * e);
	double q = 4 * (c * e) - (b * b * e) - (d * d);

	EquationRoots resolvent = Solve3(n, p, q);

	n = *max_element(begin(resolvent.root), end(resolvent.root));
	p = sqrt((b * b / 4) - (c - n));
	q = sqrt(abs((n * n / 4) - e));

	if (((b * n / 2) - d) < 0)
	{
		q *= -1;
	}

	EquationRoots SquareEquation1 = Solve2(1, b / 2 + p, n / 2 + q);
	EquationRoots SquareEquation2 = Solve2(1, b / 2 - p, n / 2 - q);

	if ((SquareEquation1.numRoots == 0) && (SquareEquation2.numRoots == 0))
	{
		throw std::domain_error("Equation does not have any real roots.");
	}

	resolvent = MergeRoots(SquareEquation1, SquareEquation2);

	return resolvent;
}

void PrintRoots(EquationRoots const &solution)
{
	for (size_t i = 0; i < solution.numRoots; ++i)
	{
		cout << solution.root[i] << endl;
	}
}