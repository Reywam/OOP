#pragma once

#include <iostream>
#include <vector>

std::vector<double> ReadVector(std::istream & input);
void ProcessVector(std::vector<double> & numbers);
void SortVector(std::vector<double> & numbers);
void OutVector(std::ostream & output, std::vector<double> & numbers);