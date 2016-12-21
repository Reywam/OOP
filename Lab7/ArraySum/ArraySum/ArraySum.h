#pragma once
#include <vector>

template <typename T>
T ArraySum(std::vector<T> const& arr);

template <typename T>
T ArraySum(std::vector<T> const& arr)
{
	T sum = T();

	if (!arr.empty())
	{
		for (auto &element : arr)
		{
			sum += element;
		}
	}

	return sum;
}

std::string ArraySum(std::vector<char> const& arr);