#pragma once

namespace ss
{

	typedef struct dm_dim_t
	{
		size_t w;
		size_t h;

		dm_dim_t() :w(-1), h(-1) {}
	}wh;

} // END	namespace ss