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
			log("ViewController::init() ret: "<<(int)ret<<", "<<rt_ret_m[(int)ret]);
		}
		~ViewController() 
		{ 
			log("~ViewController()"); 
			rt ret = destroy(); 
			log("ViewController::destroy() ret: " << (int)ret << ", " << rt_ret_m[(int)ret]);
		}

		rt		init();
		rt		init_locals();
		rt		destroy();

		inline SDL_Window*		get_w();
		inline SDL_Renderer*	get_r();
		inline SDL_Texture*		get_t();
		inline SDL_Surface*		get_s();
		
	private:
		SDL_Window*		Win_;
		SDL_Renderer*	Rend_;
		SDL_Texture*	Texture_;
		SDL_Surface*	Surface_;

	}; // END	class ViewController

	SDL_Window* ViewController::get_w() { return Win_; }
	SDL_Renderer* ViewController::get_r() { return Rend_; }
	SDL_Texture* ViewController::get_t() { return Texture_; }
	SDL_Surface* ViewController::get_s() { return Surface_; }

}// END		namespace ss
