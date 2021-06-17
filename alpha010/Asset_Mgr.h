#pragma once

#include <vector>

#include "Logger.h"
#include "View_Asset.h"

namespace ss
{
//#ifndef MAX_ASSET_COUNT
//#define MAX_ASSET_COUNT 100
//#endif
	//static const int8_t MAX_ASSET_COUNT = 100;

	class asset_mgr
	{
	public:
		asset_mgr()
		{
			log("asset_mgr()");
			uint8_t r = init();
		}
		~asset_mgr()
		{
			log("~asset_mgr()");
			uint8_t r = destroy();
		}

		uint8_t init();
		uint8_t destroy();
		
		uint8_t load_a(view_asset*);
		uint8_t del_a(char const*);
		//uint8_t del_a(view_asset*);
		uint8_t del_all();
		uint8_t get_a(char const*);


		// should really be tuple<z-index,src,dst,texture*>
		//...maybe just texture
		std::vector<view_asset> Vec_;
		//on gettexure type function, if not found, try to load it
		//no textuure in asset (sdl not needed in sdl?)

	};	//END	class
}	// END	namesapce
