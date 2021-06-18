#pragma once

#include "Logger.h"

#include "WinProp.h"
#include "RendProp.h"
#include "SDLwrapper.h"

namespace ss
{
	class ViewController
	{
	public:
		ViewController() { log("ViewController()"); uint8_t ret = init(); }
		~ViewController() { log("ViewController()"); uint8_t ret = destroy(); }

		uint8_t init();
		uint8_t init_locals();
		uint8_t destroy();

		SDL_Window*		Win_;
		SDL_Renderer*	Rend_;
		SDL_Texture*	Texture_;
		SDL_Surface*	Surface_;

	}; // END	class ViewController
}// END		namespace ss
