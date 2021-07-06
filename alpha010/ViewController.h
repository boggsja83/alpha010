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
		ViewController() 
		{ 
			log("ViewController()"); 
			rt ret = init(); 
			log("ViewController::init() ret: " << hr(ret));
		}
		
		~ViewController() 
		{ 
			log("~ViewController()"); 
			rt ret = destroy(); 
			log("ViewController::destroy() ret: " << hr(ret));
		}

		rt		init();
		rt		init_locals();
		rt		destroy();

		inline SDL_Window*		win()	const { return Win_; }
		inline SDL_Renderer*	rend()	const { return Rend_; }
		inline SDL_Texture*		text()	const { return Texture_; }
		inline SDL_Surface*		surf()	const { return Surface_; }
		
	private:
		SDL_Window*		Win_;
		SDL_Renderer*	Rend_;
		SDL_Texture*	Texture_;
		SDL_Surface*	Surface_;

	}; // END	class ViewController

	//static SDL_Window* Win_;
	//static SDL_Renderer* Rend_;
	//static SDL_Texture* Texture_;
	//static SDL_Surface* Surface_;
	//SDL_Window* ViewController::get_w() { return Win_; }
	//SDL_Renderer* ViewController::get_r() { return Rend_; }
	//SDL_Texture* ViewController::get_t() { return Texture_; }
	//SDL_Surface* ViewController::get_s() { return Surface_; }

}// END		namespace ss
