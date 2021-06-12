#pragma once

#include <array>

#include "Logger.h"
#include "View_Asset.h"

namespace ss
{
//#ifndef MAX_ASSET_COUNT
//#define MAX_ASSET_COUNT 100
//#endif
	static const int8_t MAX_ASSET_COUNT = 100;

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
		
		//on gettexure type function, if not found, try to load it
		//no textuure in asset (sdl not needed in sdl?)

	};	//END	class
}	// END	namesapce
