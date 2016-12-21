#include "stdafx.h"
#include "ArraySum.h"

std::string ArraySum(std::vector<char> const& arr)
{
	std::string sum = std::string();

	if (!arr.empty())
	{
		for (auto element : arr)
		{
			sum = sum + element;
		}
	}

	return sum;
}