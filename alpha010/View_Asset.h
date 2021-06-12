#pragma once

#include "Logger.h"
#include "SDL_.h"

namespace ss
{
	class view_asset
	{

	public:
		// BEGIN	view_asset() details
		//view_asset(const char* _name)
		//{
		//	log("view_asset("<<_name<<")");
		//	
		//	asset_name = _name;
		//	uint8_t r = init();
		//}
		view_asset()
		{
			log("view_asset()");
			uint8_t r = init();
		}
		~view_asset()
		{
			log("~view_asset()");
			uint8_t r = destroy();
		}

		uint8_t			init();
		uint8_t			destroy();
		//uint8_t			draw();

		const char*		asset_name;
		//const char*		asset_path;

		SDL_Rect		src_rect;
		SDL_Rect		dst_rect;
		
		uint8_t			z_order;

		//SDL_Texture*	raw_text;

		// END		view_asset() details
	}; // END	class

} // END ss
