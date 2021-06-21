#pragma once

namespace ss
{
	typedef struct ps_pos_t
	{
		size_t x;
		size_t y;
		size_t z;

		ps_pos_t():x(-1),y(-1),z(-1){}
	}xyz;
}
