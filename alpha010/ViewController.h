#pragma once

#include "ALL.h"

#include "WinProp.h"
#include "RendProp.h"
#include "SDLwrapper.h"

namespace ss
{
	class ViewController
	{
	public:
		ViewController() { log("ViewController()"); rt ret = init(); }
		~ViewController() { log("ViewController()"); rt ret = destroy(); }

		rt init();
		rt init_locals();
		rt destroy();

		SDL_Window*		Win_;
		SDL_Renderer*	Rend_;
		SDL_Texture*	Texture_;
		SDL_Surface*	Surface_;

	}; // END	class ViewController
}// END		namespace ss
