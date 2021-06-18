#pragma once

#include "ALL.h"
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
		return  rand() % ++_hi + _lo;
	}

	template<typename T>
	static int qs_part(T _t[], int _lo, int _hi)
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
	static int qs(T _t[], int _lo, int _hi)
	{
		int p = -1;
		int r = -1;

		if (_lo < _hi)
		{
			p = qs_part(_t, _lo, _hi);

			r = qs(_t, _lo, p - 1);
			r = qs(_t, p + 1, _hi);
		}
		return 0;
	}
}	// END	namespace

