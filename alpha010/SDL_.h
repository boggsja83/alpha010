#pragma once

#include "Logger.h"

#include "SDL.h"
#include "SDL_image.h"
//#include <string>
//#include <map>

namespace ss
{

	class sdl_
	{
		// BEGIN	Singleton Stack

	//public:
	//	~sdl_()
	//	{
	//		log("~sdl_()");
	//		int r = destroy();
	//	}
	//	sdl_(sdl_&) = delete;
	//	void* operator=(const sdl_&) = delete;
	//	static sdl_& GetInstance()
	//	{
	//		static sdl_ inst_;
	//		//instance_ = &inst_;
	//		return inst_;
	//	}
	//private:
	//	sdl_()
	//	{
	//		log("sdl_()");
	//		int r = init();
	//	}

		// END		Singleton Stack


	// BEGIN	Constructor/Destructor
	public:
		sdl_() 
		{
			log("sdl_()");
			uint8_t r = init();
		}
		~sdl_() 
		{
			log("~sdl_()");
			uint8_t r = destroy();
		}
	// END		Constructor/Destructor


		// BEGIN	sdl_ details
	public:
		//static sdl_* instance_;

		uint8_t			init();
		uint8_t			init_locals();
		int				init_sdl_video();
		uint8_t			init_sdl_img();

		SDL_Window*		create_win(const char*, int, int, int, int, Uint32);
		SDL_Renderer*	create_rend(SDL_Window*, int, Uint32);
		SDL_Texture*	create_text(SDL_Renderer*, Uint32, int, int, int);
		SDL_Surface*	create_surf_from_path(const char*);
		SDL_Texture*	create_text_from_surf(SDL_Renderer*, SDL_Surface*);
		SDL_Texture*	create_text_from_path(SDL_Renderer*, const char*);

		int32_t			get_pixel_format(SDL_RendererInfo*);
		int				get_rend_info(SDL_Renderer*, SDL_RendererInfo*);
		int				query_text(SDL_Texture*, Uint32*, int*, int*, int*);
		int				rend_cpy(SDL_Renderer*, SDL_Texture*, const SDL_Rect*, const SDL_Rect*);
		int				set_rend_targ(SDL_Renderer*, SDL_Texture*);

		uint8_t			destroy();
		uint8_t			destroy_win(SDL_Window*);
		uint8_t			destroy_rend(SDL_Renderer*);
		uint8_t			destroy_text(SDL_Texture*);
		uint8_t			destroy_surf(SDL_Surface*);
		uint8_t			destroy_sdl();
		uint8_t			destroy_sdl_video();
		uint8_t			destroy_sdl_image();

		int				draw();

		// window properties
		const char*		title_win;
		size_t			width_win;
		size_t			height_win;
		size_t			x_win;
		size_t			y_win;
		int32_t			flags_win;

		int8_t			r_surf;
		int8_t			g_surf;
		int8_t			b_surf;
		SDL_Rect		rect_win;

		// renderer properties
		int8_t			index_rend;
		int32_t			flags_rend;
		SDL_RendererInfo info_rend;
		uint32_t		pixel_format_rend;

		int8_t			r_rend;
		int8_t			g_rend;
		int8_t			b_rend;
		

		SDL_Window*		Win_;
		SDL_Renderer*	Rend_;
		SDL_Surface*	Surface_;//dont really need this surface or texture below
		SDL_Texture*	Texture_;//


		// Use a map<int,std::string> that holds
		// everything that needs to be rendered
		// including their z-order
		// i.e. a render stack
		// or just add z-order to I_AV_SDL?
		// and then use an std::string[]/vector<std::string> here?

		// END		sdl_ details

	}; // END	class


} // END ss