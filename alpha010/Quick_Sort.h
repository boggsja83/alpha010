#pragma once

#include "Logger.h"
#include <utility>
#include <cstdlib>

namespace ss
{
	static int seed_(time_t* _s)
	{
		srand((unsigned int)time(_s));
		return 0;
	}

	static int rand_int(int _lo, int _hi)
	{
		
		int r = rand() % ++_hi + _lo;
		return r;
	}

	template<typename T>
	static int partition(T _t[], int _lo, int _hi)
	{
		T p = _t[_hi];

		int i = _lo - 1;

		for (int j = _lo; j < _hi; ++j)
		{
			if (_t[j] < p)
			{
				++i;
				std::swap(_t[i], _t[j]);
			}
		}
		std::swap(_t[i + 1], _t[_hi]);
		return (i + 1);
	}

	template<typename T>
	static int quickSort(T _t[], int _lo, int _hi)
	{
		int _p = -1;
		int r = -1;

		if (_lo < _hi)
		{
			_p = partition(_t, _lo, _hi);

			r = quickSort(_t, _lo, _p - 1);
			r = quickSort(_t, _p + 1, _hi);
		}
		return 0;
	}
}	// END	namespace

