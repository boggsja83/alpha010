#pragma once

#include "Logger.h"
#include <map>
#include <array>
#include "SDL.h"
#include "View_Asset.h"

namespace ss
{
//#ifndef MAX_RENDER_COUNT
//#define MAX_RENDER_COUNT 100 // max number of items to draw to screen
//#endif
	static const int8_t MAX_RENDER_COUNT = 100;
	/// <summary>
	///		This structure holds multiple SDL_Texture*s and automatically
	///		arranges them according to their z-order as they are inserted
	/// </summary>
	class render_list
	{
	public:
		// BEGIN	render_map details
		render_list() 
		{
			log("render_map()");
			uint8_t r = init();
		}
		~render_list() 
		{
			log("~render_map()");
			uint8_t r = destroy();
		}


		// class members
		uint8_t init();
		uint8_t destroy();

		std::array<view_asset,MAX_RENDER_COUNT> List_;

		//asset
		//rect
		//z-order
		//texture
		//std::map<SDL_Texture*, uint8_t> texts_;
		

		// END		render_map details

	}; // end class

} // end namespace

