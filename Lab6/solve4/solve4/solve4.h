#pragma once
#include <iostream>
#include <vector>

struct EquationRoots
{
	unsigned numRoots = 0;
	double root[4];
};

void ToCanonicalForm(const double a, double &b, double &c, double &d, double &e);
EquationRoots Solve4(double a, double b, double c, double d, double e);
void PrintRoots(EquationRoots const &solution);