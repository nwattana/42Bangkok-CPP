#pragma once
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& ctn, int tofind)
{
	return (std::find(ctn.begin(), ctn.end(), tofind));
}