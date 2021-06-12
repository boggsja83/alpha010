#pragma once

#include "Logger.h"
#include "SDL_.h"
#include "Asset_Mgr.h"
#include "View_Asset.h"

#include "Quick_Sort.h"

namespace ss
{
//#ifndef MAX_ASSET_COUNT
//#define MAX_ASSET_COUNT 100
//#endif

	class engine
	{
	public:
		engine()
		{
			log("engine()");
			uint8_t r = init();
		}
		~engine()
		{
			log("~engine()");
			uint8_t r = destroy();
		}

		// engine() functions
		uint8_t init();
		uint8_t init_locals();
		uint8_t destroy();

		// view controller
		sdl_ sdl_inst;

		// input controller
		
		// audio controller
		
		// game loop
		uint8_t loop();
		uint8_t input();
		uint8_t draw();
		bool On_;

		// asset manager



	};
} // END ss
