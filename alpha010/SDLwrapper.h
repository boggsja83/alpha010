#pragma once

#include "ALL.h"

#include "WinProp.h"
#include "RendProp.h"

#include "SDL.h"
#include "SDL_image.h"

namespace ss
{
	/**********DECLARATIONS**********/
	static rt				init_sdl_video();
	static rt				init_sdl_img();

	static SDL_Window*		create_win(char const*, int, int, int, int, Uint32);
	static SDL_Renderer*	create_rend(SDL_Window*, int, Uint32);
	static SDL_Texture*		create_text(SDL_Renderer*, Uint32, int, int, int);
	static SDL_Surface*		create_surf_from_path(char const*);
	static SDL_Texture*		create_text_from_surf(SDL_Renderer*, SDL_Surface*);
	static SDL_Texture*		create_text_from_path(SDL_Renderer*, char const*);

	static int32_t			get_pixel_format(SDL_RendererInfo*);
	static rt				get_rend_info(SDL_Renderer*, SDL_RendererInfo*);
	static rt				set_rend_draw_color(SDL_Renderer*, Uint8, Uint8, Uint8, Uint8);
	static rt				set_rend_targ(SDL_Renderer*, SDL_Texture*);
	static rt				rend_cpy(SDL_Renderer*, SDL_Texture*, SDL_Rect const*, SDL_Rect const*);

	static rt				fill_rect(SDL_Surface*, SDL_Rect const *, Uint32);

	static rt				query_text(SDL_Texture*, Uint32*, int*, int*, int*);

	static SDL_Surface*		get_win_surf(SDL_Window* _win);
	
	static rt				update_win_surf(SDL_Window*);

	static rt				destroy_win(SDL_Window*);
	static rt				destroy_rend(SDL_Renderer*);
	static rt				destroy_text(SDL_Texture*);	
	static rt				destroy_surf(SDL_Surface*);
	static rt				destroy_sdl();
	static rt				destroy_sdl_video();
	static rt				destroy_sdl_image();

	/*----------DEFINITIONS----------*/

	ss::rt ss::init_sdl_video()
	{
		SDL_ClearError();
		int r = SDL_InitSubSystem(SDL_INIT_VIDEO);

		if (r) {
			log("init_sdl_video error: " << SDL_GetError()); 
			return rt::FAIL_INIT_SDL_VIDEO; 
		}
		log("init_sdl_video()");
		return rt::SUCCESS;
	}

	ss::rt ss::init_sdl_img()
	{
		IMG_GetError();
	
		uint32_t flags = IMG_INIT_PNG;
		uint32_t initted = IMG_Init(flags);

		if ((initted & flags) != flags) 
		{ 
			log("init_sdl_img() error: " << IMG_GetError()); 
			return rt::FAIL_INIT_IMG;
		}
		log("init_sdl_img()"); 
		return rt::SUCCESS;
	}

	SDL_Window* ss::create_win(char const* _title, int _x, int _y, int _w, int _h, Uint32 _flags)
	{
		SDL_Window* temp_w = nullptr;

		SDL_ClearError();
		temp_w = SDL_CreateWindow(
			_title,
			_x, _y,
			_w, _h,
			_flags
		);

		if (temp_w){ log("create_win(): " << temp_w); }
		else { log("create_win() error: " << SDL_GetError()); }
		return temp_w;
	}

	SDL_Renderer* ss::create_rend(SDL_Window* _win, int _index, Uint32 _flags)
	{
		SDL_Renderer* temp = nullptr;
		SDL_ClearError();
		temp = SDL_CreateRenderer(_win, _index, _flags);

		if (temp) { log("create_rend(): " << temp); }
		else { log("create_rend() error: " << SDL_GetError()); }
		return temp;
	}

	SDL_Surface* ss::create_surf_from_path(char const* _path)
	{
		SDL_Surface* temp = nullptr;
		IMG_GetError();
		temp = IMG_Load(_path);
		if (temp) { log("create_surf_from_path()"); }
		else { log("create_surf_from_path() error: " << IMG_GetError()); }
		return temp;
	}

	SDL_Texture* ss::create_text(SDL_Renderer* _rend, Uint32 _format, int _access, int _w, int _h)
	{
		// format can be whole lot of things...
		// 
		// access
		// SDL_TEXTUREACCESS_STATIC changes rarely, not lockable
		// SDL_TEXTUREACCESS_STREAMING changes frequently, lockable
		// SDL_TEXTUREACCESS_TARGET can be used as a render target

		// w width
		// h height

		SDL_Texture* temp_t = nullptr;

		SDL_ClearError();
		temp_t = SDL_CreateTexture(_rend, _format, _access, _w, _h);
		if (temp_t) { log("create_text(): " << temp_t); }
		else { log("create_text() error: " << SDL_GetError()); }
		return temp_t;
	}

	SDL_Texture* ss::create_text_from_surf(SDL_Renderer* _rend, SDL_Surface* _surf)
	{
		SDL_ClearError();
		SDL_Texture* temp_t = SDL_CreateTextureFromSurface(_rend, _surf);
		if (!temp_t) { log("create_text_from_surf(" << _rend << ", " << _surf << ") error: " << SDL_GetError()); }
		return temp_t;
	}

	SDL_Texture* ss::create_text_from_path(SDL_Renderer* _rend, char const* _path)
	{
		SDL_Surface* temp_s = nullptr;
		SDL_Texture* temp_t = nullptr;

		temp_s = create_surf_from_path(_path);
		if (temp_s)
		{
			temp_t = create_text_from_surf(_rend, temp_s);
			rt ret = destroy_surf(temp_s);

			if (!temp_t) { log("create_text_from_path() failed to create texture: " << _path); }
		}
		else { log("create_surf_from_path() failed to create surface: " << _path); }

		return temp_t;
	}

	ss::rt ss::set_rend_draw_color(SDL_Renderer* _rend, uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a)
	{
		SDL_ClearError();
		int ret = SDL_SetRenderDrawColor(_rend, _r, _g, _b, _a);
		if (ret)
		{ 
			log("set_rend_draw_color failed: " << SDL_GetError()); 
			return rt::FAIL_SET_REND_DRAW_COLOR;
		}
		return rt::SUCCESS;
	}

	ss::rt ss::set_rend_targ(SDL_Renderer* _r, SDL_Texture* _t)
	{
		SDL_ClearError();
		int ret = SDL_SetRenderTarget(_r, _t);
		if (ret) 
		{ 
			log("set_rend_targ(" << _r << ", " << _t << ") error: " << SDL_GetError());
			return rt::FAIL_SET_REND_TARG;
		}
		return rt::SUCCESS;
	}

	int32_t ss::get_pixel_format(SDL_RendererInfo* _ri)
	{
		//int n = _ri->num_texture_formats;
		//Uint32 u = 0;

		//for (int i=0; i<n;++i)
		//{
		//	u = _ri->texture_formats[i];
		//}
		//
		//return u;
		return _ri->texture_formats[0];
	}

	ss::rt ss::get_rend_info(SDL_Renderer* _r, SDL_RendererInfo* _ri)
	{
		SDL_ClearError();
		int ret = SDL_GetRendererInfo(_r, _ri);
		if (ret) 
		{ 
			log("get_rend_info(" << _r << ", " << _ri << ") error: " << SDL_GetError()); 
			return rt::FAIL_GET_RENDER_INFO;
		}
		return rt::SUCCESS;
	}

	ss::rt ss::fill_rect(SDL_Surface* _src, const SDL_Rect* _rect, Uint32 _color)
	{
		SDL_ClearError();
		int ret = SDL_FillRect(_src, _rect, _color);
		if (ret) 
		{ 
			log("ss::fill_rect(" << _src << ", " << _rect << ", " << _color << ") error: " << SDL_GetError()); 
			return rt::FAIL_FILL_RECT;
		}
		//return rt::SUCCESS;
		return rt::SUCCESS;
	}

	ss::rt ss::query_text(SDL_Texture* _text, Uint32* _format, int* _access, int* _w, int* _h)
	{
		//int SDL_QueryTexture(SDL_Texture * texture,
		//	Uint32 * format, int* access,
		//	int* w, int* h);

		int ret = -1;

		SDL_ClearError();
		ret = SDL_QueryTexture(_text, _format, _access, _w, _h);
		if (ret)
		{
			//bad
			log("query_text(" <<
				_text << ", " <<
				_format << ", " <<
				_access << ", " <<
				_w << ", " << _h <<
				") error: " << SDL_GetError());
			return rt::FAIL_QUERY_TEXT;
		}
		return rt::SUCCESS;
	}

	SDL_Surface* ss::get_win_surf(SDL_Window* _win)
	{
		SDL_ClearError();
		SDL_Surface* temp_s = SDL_GetWindowSurface(_win);
		if (!temp_s) { log("ss::get_win_surf(" << _win << ") error: " << SDL_GetError()); }
		return temp_s;
	}

	ss::rt ss::update_win_surf(SDL_Window* _win)
	{
		SDL_ClearError();
		int ret = SDL_UpdateWindowSurface(_win);
		if (ret) 
		{ 
			log("ss:update_win_surf(" << _win << ") error: " << SDL_GetError()); 
			return rt::FAIL_UPDATE_WIN_SURF;
		}
		return rt::SUCCESS;
	}

	ss::rt ss::rend_cpy(SDL_Renderer* _rend, SDL_Texture* _text, SDL_Rect const* _src, SDL_Rect const* _dst)
	{
		SDL_ClearError();
		int ret = SDL_RenderCopy(_rend, _text, _src, _dst);
		if (ret) 
		{ 
			log("rend_cpy(" << _rend << ", " << _text << ", " << _src << ", " << _dst << ") error: " << SDL_GetError()); 
			return rt::FAIL_REND_CPY;
		}
		return rt::SUCCESS;
	}

	ss::rt ss::destroy_win(SDL_Window* _w)
	{
		SDL_ClearError();
		SDL_DestroyWindow(_w);
		std::string s = SDL_GetError();
		if (s.size() == 0)
		{
			// good
			log("destroy_win(" << _w << ")");
			return rt::SUCCESS;
			//return rt::FAIL_DESTROY_WIN;
		}
		else
		{
			// bad
			log("destroy_win() error: " << s);
			return rt::FAIL_DESTROY_WIN;
		}
	}

	ss::rt ss::destroy_rend(SDL_Renderer* _r)
	{
		SDL_ClearError();
		SDL_DestroyRenderer(_r);
		std::string s = SDL_GetError();
		if (s.size() == 0)
		{
			// good
			log("destroy_rend(" << _r << ")");
			return rt::SUCCESS;
		}
		else
		{
			// bad
			log("destroy_rend(" << _r << ") error: " << s);
			return rt::FAIL_DESTROY_REND;
		}
	}

	ss::rt ss::destroy_text(SDL_Texture* _t)
	{
		SDL_ClearError();
		SDL_DestroyTexture(_t);
		std::string s = SDL_GetError();
		if (s.size() == 0)
		{
			// good
			log("destroy_text(" << std::hex << (int32_t)_t << ")");
			return rt::SUCCESS;
		}
		else
		{
			// bad
			log("destroy_text(" << _t << ") error: " << s);
			return rt::FAIL_DESTROY_TEXT;
		}
	}

	ss::rt ss::destroy_surf(SDL_Surface* _s)
	{
		SDL_ClearError();
		SDL_FreeSurface(_s);
		std::string s = SDL_GetError();
		if (s.size() == 0)
		{
			log("destroy_surf(" << _s << ")");
			return rt::SUCCESS;
		}
		else
		{
			log("destroy_surf(" << _s << ") error: " << s);
			return rt::FAIL_DESTROY_SURF;
		}
	}

	ss::rt ss::destroy_sdl()
	{
		SDL_ClearError();
		SDL_Quit();
		std::string s = SDL_GetError();
		if (s.size() == 0)
		{
			//good
			log("destroy_sdl() " << s);
			return rt::SUCCESS;
		}
		else
		{
			//bad
			log("destroy_sdl() error: " << s);
			return rt::FAIL_DESTROY_SDL;
		}
	}

	ss::rt ss::destroy_sdl_video()
	{
		SDL_ClearError();
		SDL_QuitSubSystem(SDL_INIT_VIDEO);
		std::string s = SDL_GetError();
		if (s.size() == 0)
		{
			//good
			log("destroy_sdl_video() " << s);
			return rt::SUCCESS;
		}
		else
		{
			//bad
			log("destroy_sdl_error() error: " << s);
			return rt::FAIL_DESTROY_SDL_VIDEO;
		}
	}

	ss::rt ss::destroy_sdl_image()
	{
		IMG_GetError();
		IMG_Quit();
		std::string s = IMG_GetError();
		if (s.size() == 0)
		{
			//good
			log("destroy_sdl_image()");
			return rt::SUCCESS;
		}
		else
		{
			//bad
			log("destroy_sdl_image() error: " << s);
			return rt::FAIL_DESTROY_SDL_IMG;
		}
	}





} // END ss
